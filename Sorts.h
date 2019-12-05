#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define RANDOM_MIN -10000
#define RANDOM_MAX 10000
#define INT long long

std::ofstream file_out_op("operations.csv");
std::ofstream file_out_co("comparisons.csv");

struct data {
  INT operations = 0;
  INT comparisons = 0;
};

class Sorts {
 private:
  std::vector<int> arr;
  data return_data;

  int middle(int a, int b, int c) {
    if (a >= b && a <= c || a <= b && a >= c) {
      return a;
    }
    if (b >= a && b <= c || b >= c && b <= a) {
      return b;
    }
    return c;
  }
  void qsort(int b, int e) {
    int l = b, r = e;
    int piv = middle(arr[l], arr[r], arr[(l + r) / 2]);
    while (l <= r) {
      while (arr[l] < piv) {
        return_data.comparisons += 1;
        l++;
      }
      while (arr[r] > piv) {
        return_data.comparisons += 1;
        r--;
      }
      return_data.comparisons += 1;
      if (l <= r) {
        std::swap(arr[l++], arr[r--]);
        return_data.operations += 3;
      }
    }
    if (b < r) qsort(b, r);
    if (e > l) qsort(l, e);
  }
  std::vector<int> merge(std::vector<int> a, std::vector<int> b) {
    std::vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
      return_data.comparisons += 1;
      if (a[i] < b[j]) {
        res.push_back(a[i]);
        i++;
      } else {
        res.push_back(b[j]);
        j++;
      }
      return_data.operations += 1;
    }
    while (i < a.size()) {
      res.push_back(a[i]);
      i++;
      return_data.operations++;
    }
    while (j < b.size()) {
      res.push_back(b[j]);
      j++;
      return_data.operations++;
    }
    return res;
  }
  std::vector<int> merge_sort(std::vector<int> arr) {
    int n = arr.size();
    if (n <= 1) return arr;
    int m = n / 2;
    std::vector<int> left, right;
    for (int i = 0; i < n; i++) {
      if (i < m)
        left.push_back(arr[i]);
      else
        right.push_back(arr[i]);
      return_data.operations++;
    }
    left = merge_sort(left);
    right = merge_sort(right);
    return merge(left, right);
  }

 protected:
  
  int get_random_number(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
  }
  std::string print_vector(std::vector<int> arr) {
    std::stringstream ss;
    std::string s;
    for (int i = 0; i < arr.size() - 1; ++i) {
      ss << arr[i] << ";";
    }
    ss << arr[arr.size() - 1];

    getline(ss, s);
    return s;
  }
  data bubble_sort_slow(std::vector<int> arr) {
    data return_data;
    int tmp = 0;
    for (int i = 0; i < arr.size(); i++) {
      for (int j = arr.size() - 1; j > 0; j--) {
        return_data.comparisons += 1;
        if (arr[j] < arr[j - 1]) {
          std::swap(arr[j], arr[j - 1]);
          return_data.operations += 3;
        }
      }
    }
    return return_data;
  }
  data bubble_sort_fast(std::vector<int> arr) {
    data return_data;
    bool b = true;
    for (int i = 0; i < arr.size(); i++) {
      b = true;
      for (int j = arr.size() - 1; j >= (i + 1); j--) {
        return_data.comparisons += 1;
        if (arr[j] < arr[j - 1]) {
          std::swap(arr[j], arr[j - 1]);
          b = false;
          return_data.operations += 3;
        }
      }
      if (b) {
        break;
      }
    }
    return return_data;
  }
  data insertion_sort(std::vector<int> arr) {
    data return_data;
    int temp, item;
    for (int counter = 1; counter < arr.size(); counter++) {
      return_data.operations += 1;
      temp = arr[counter];
      item = counter - 1;
      while (item >= 0 && arr[item] > temp) {
        return_data.comparisons += 2;
        return_data.operations += 2;
        arr[item + 1] = arr[item];
        arr[item] = temp;
        item--;
      }
    }
    return return_data;
  }
  data binary_insert_sort(std::vector<int> arr) {
    data return_data;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
      int l = -1, r = i;
      while (r - l > 1) {
        int m = (l + r) / 2;
        return_data.comparisons++;
        if (arr[m] < arr[i])
          l = m;
        else
          r = m;
      }
      int t = arr[i];
      arr.erase(arr.begin() + i);
      return_data.operations += i;
      arr.insert(arr.begin() + r, t);
      return_data.operations += r;
    }
    return return_data;
  }
  data qsort_ret(std::vector<int> arr) {
    this->arr = arr;
    qsort(0, arr.size() - 1);
    data return_data = this->return_data;
    this->return_data.comparisons = 0;
    this->return_data.operations = 0;
    return return_data;
  }
  data bubble_sort_bin(std::vector<int> arr) {
    data return_data;
    int tmp = 0;
    bool b = true;
    for (int i = 0; i < arr.size(); i++) {
      b = true;
      for (int j = i; j < arr.size() - 1 - i; j++) {
        return_data.comparisons += 1;
        if (arr[j] > arr[j + 1]) {
          std::swap(arr[j], arr[j + 1]);
          b = false;
          return_data.operations += 3;
        }
      }
      for (int j = arr.size() - 2 - i; j >= (i + 1); j--) {
        return_data.comparisons += 1;
        if (arr[j] < arr[j - 1]) {
          std::swap(arr[j], arr[j - 1]);
          b = false;
          return_data.operations += 3;
        }
      }
      if (b) break;
    }
    return return_data;
  }
  // i hate next shit-sort
  data merge_sort_ret(std::vector<int> arr) { 
    merge_sort(arr);
    data return_data_merge = this->return_data;
    this->return_data.comparisons = 0;
    this->return_data.operations = 0;
    return return_data_merge;
  }
};
class interface : protected Sorts {
 public:
  interface(const int n) {
    std::vector<int> start_data;
    std::vector<data> vector_of_data;
    
    for (size_t i = 0; i < n; i++) {
      start_data.push_back(get_random_number(RANDOM_MIN, RANDOM_MAX));
    }

    std::cout << "start data is: " << print_vector(start_data) << std::endl;

    vector_of_data.push_back(binary_insert_sort(start_data));
    vector_of_data.push_back(qsort_ret(start_data));
    vector_of_data.push_back(bubble_sort_slow(start_data));
    vector_of_data.push_back(bubble_sort_fast(start_data));
    vector_of_data.push_back(bubble_sort_bin(start_data));
    vector_of_data.push_back(insertion_sort(start_data));
    vector_of_data.push_back(merge_sort_ret(start_data));

    for (size_t i = 0; i < 7; i++) {
      std::cout << "is: " << vector_of_data[i].comparisons
                << " comprasions, and " << vector_of_data[i].operations
                << " operations \n";
    }
    
    file_out_co << n << ";";
    file_out_op << n << ";";

    for (size_t i = 0; i < 7; i++) {
      file_out_co << vector_of_data[i].comparisons << ";";
      file_out_op << vector_of_data[i].operations << ";";
    }

    file_out_co << "\n";
    file_out_op << "\n";
  }
};