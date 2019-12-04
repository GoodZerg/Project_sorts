#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define RANDOM_MIN -10000
#define RANDOM_MAX 10000
#define INT long long

class Sorts {
 private:

  struct data {
    INT operations = 0;
    INT comparisons = 0;
  };
  std::vector<int> arr;
  data return_data;

  int middle                 (int a, int b,  int c) {
    if (a >= b && a <= c || a <= b && a >= c) {
      return a;
    }
    if (b >= a && b <= c || b >= c && b <= a) {
      return b;
    }
    return c;
  }
  void qsort                 (int b,         int e) {
    int l = b, r = e;
    int piv = middle(arr[l], arr[r],
           arr[(l + r) / 2]);
    return_data.operations += 3;
    while (l <= r) {
      return_data.comparisons += 1;
      while (arr[l] < piv){ 
        return_data.comparisons += 1;
        l++;
        return_data.operations += 1;
      }
      while (arr[r] > piv){ 
        return_data.comparisons += 1;
        r--;
        return_data.operations += 1;
      }
      return_data.comparisons += 1;
      if (l <= r) {
        std::swap(arr[l++], arr[r--]);
        return_data.operations += 3;
      }
    }
    return_data.comparisons += 1;
    if (b < r) qsort(b, r);
    return_data.comparisons += 1;
    if (e > l) qsort(l, e);
  }
  std::vector<int> merge     (std::vector<int> a, 
                              std::vector<int> b){
    std::vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size()) {
      return_data.comparisons += 3;
      if (a[i] < b[j]) {
        res.push_back(a[i]);
        i++;
      } else {
        res.push_back(b[j]);
        j++;
      }
      return_data.operations += 2;
    }
    while (i < a.size()) {
      return_data.comparisons += 1;
      res.push_back(a[i]);
      i++;
      return_data.operations++;
    }
    while (j < b.size()) {
      return_data.comparisons += 1;
      res.push_back(b[j]);
      j++;
      return_data.operations++;
    }
    return res;
  }

 protected:

  data return_data_merge;
  int get_random_number      (int min,     int max) {
    static const double fraction =
        1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
  }
  std::string print_vector   (std::vector<int> arr) {
    std::stringstream ss;
    std::string s;
    for (int i = 0; i < arr.size() - 1; ++i) {
      ss << arr[i] << ",";
    }
    ss << arr[arr.size() - 1];

    getline(ss, s);
    return s;
  }
  data bubble_sort_slow      (std::vector<int> arr) {
    data return_data;
    int tmp = 0;
    return_data.operations += 1;
    return_data.operations += 1;
    for (int i = 0; i < arr.size(); i++) {
      return_data.comparisons += 1;
      return_data.operations += 1;
      return_data.operations += 1;
      for (int j = arr.size() - 1; j > 0; j--) {
        return_data.operations += 1;
        return_data.comparisons += 1;
        if (arr[j] < arr[j - 1]) {
          return_data.comparisons += 1;
          std::swap(arr[j], arr[j - 1]);
          return_data.operations += 3;
        }
      }
    }
    return return_data;
  }
  data bubble_sort_fast      (std::vector<int> arr) {
    data return_data;
    bool b = true;
    return_data.operations += 1;
    return_data.operations += 1;
    for (int i = 0; i < arr.size(); i++) {
      b = true;
      return_data.operations += 2;
      return_data.comparisons += 1;
      return_data.operations += 1;
      for (int j = arr.size() - 1; j >= (i + 1); j--) {
        return_data.operations += 1;
        return_data.comparisons += 1;
        if (arr[j] < arr[j - 1]) {
          return_data.comparisons += 1;
          std::swap(arr[j], arr[j - 1]);
          b = false;
          return_data.operations += 4;
        }
      }
      if (b) {
        return_data.comparisons += 1;
        break;
      }
    }
    return return_data;
  }
  data insertion_sort        (std::vector<int> arr) {
    data return_data;
    int temp, item;
    return_data.operations += 1;
    for (int counter = 1; counter < arr.size(); counter++) {
      return_data.comparisons += 1;
      return_data.operations += 1;
      temp = arr[counter];
      item = counter - 1;
      return_data.operations += 2;
      while (item >= 0 && arr[item] > temp) {
        return_data.comparisons += 2;
        return_data.operations += 3;
        arr[item + 1] = arr[item];
        arr[item] = temp;
        item--;
      }
    }
    return return_data;
  }
  data binary_insert_sort    (std::vector<int> arr) {
    data return_data;
    int n = arr.size();
    for (int i = 1; i < n; i++) {
      return_data.comparisons++;
      int l = -1, r = i;
      while (r - l > 1) {
        return_data.comparisons++;
        int m = (l + r) / 2;
        return_data.comparisons++;
        if (arr[m] < arr[i])
          l = m;
        else
          r = m;
        return_data.operations++;
      }
      int t = arr[i];
      arr.erase(arr.begin() + i);
      return_data.operations += n - i;
      arr.insert(arr.begin() + r, t);
      return_data.operations += n - r;
    }
    return return_data;
  }
  data qsort_ret             (std::vector<int> arr) {
    this->arr = arr;
    qsort( 0, arr.size() - 1);
    data return_data = this->return_data;
    this->return_data.comparisons = 0;
    this->return_data.operations = 0;
    return return_data;
  }
  data bubble_sort_bin       (std::vector<int> arr) {
    data return_data;
    int tmp = 0;
    bool b = true;
    return_data.operations += 3;
    return_data.comparisons += 1;
    for (int i = 0; i < arr.size(); i++) {
      return_data.operations += 1;
      b = true;
      return_data.operations += 2;
      for (int j = i; j < arr.size() - 1 - i; j++) {
        return_data.comparisons += 1;
        return_data.operations += 1;
        return_data.comparisons += 1;
        if (arr[j] > arr[j + 1]) {
          std::swap(arr[j], arr[j + 1]);
          b = false;
          return_data.operations += 4;
        }
      }
      return_data.operations += 1;
      for (int j = arr.size() - 2 - i; j >= (i + 1); j--) {
        return_data.comparisons += 1;
        return_data.operations += 1;
        if (arr[j] < arr[j - 1]) {
          return_data.comparisons += 1;
          std::swap(arr[j], arr[j - 1]);
          b = false;
          return_data.operations += 4;
        }
      }
      return_data.comparisons += 1;
      if (b) break;
    }
    return return_data;
  }
  // i hate next shit-sort
  std::vector<int> merge_sort(std::vector<int> arr) {
    int n = arr.size();
    return_data_merge = return_data;
    if (n <= 1) return arr;
    int m = n / 2;
    std::vector<int> left, right;
    for (int i = 0; i < n; i++) {
      return_data.comparisons++;
      if (i < m)
        left.push_back(arr[i]);
      else
        right.push_back(arr[i]);
      return_data.operations++;
    }
    left = merge_sort(left);
    right = merge_sort(right);
    return_data_merge = return_data;
    return merge(left, right);
  }
};
class interface : protected Sorts {
 public:

  interface(const int n) {
    std::vector<int> start_data;

    for (size_t i = 0; i < n; i++) {
      start_data.push_back(get_random_number(RANDOM_MIN, RANDOM_MAX));
    }

    std::cout << "start data is: " << print_vector(start_data) << std::endl;

    binary_insert_sort  (start_data);
    qsort_ret           (start_data);
    bubble_sort_slow    (start_data);
    bubble_sort_fast    (start_data);
    bubble_sort_bin     (start_data);
    insertion_sort      (start_data);
    merge_sort          (start_data); // return data in "return_data_merge"
  }
};