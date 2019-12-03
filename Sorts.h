#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define RANDOM_MIN -1000
#define RANDOM_MAX 1000
#define INT long long

class Sorts {
 private:
  std::vector<int> arr;
  struct data {
    INT operations = 0;
    INT comparisons = 0;
  };
  data return_data;
  void qsort(int b, int e) {
    int l = b, r = e;
    int piv =
        arr[(l + r) / 2];  
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
 protected:
  int get_random_number(int min, int max) {
    constexpr static const double fraction =
        1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
  }
  std::string print_vector(std::vector<int> arr) {
    std::stringstream ss;
    std::string s;
    for (int i = 0; i < arr.size() - 1; ++i) {
      ss << arr[i] << ",";
    }
    ss << arr[arr.size() - 1];

    getline(ss, s);
    return s;
  }
  data bubble_sort_slow(std::vector<int> arr) {
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
  data bubble_sort_fast(std::vector<int> arr) {
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
  data insertion_sort(std::vector<int> arr) {
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
  /*
  data insertion_sort_bin(std::vector<int> arr) {
    data return_data;
    for (int i = 1; i < arr.size(); ++i) {
      return_data.comparisons += 1;
      int key = arr[i];
      int lo = 0, hi = i;
      return_data.operations += 2;
      while (lo < hi) {
        return_data.comparisons += 1;
        int mid = lo + (hi - lo);
        return_data.operations += 1;
        if (key < arr[mid]) {
          return_data.comparisons += 1;
          return_data.operations += 1;
          hi = mid;
        } else {
          return_data.operations += 1;
          lo = mid + 1;
          return_data.operations += 1;
          for (int j = i; j > lo; --j) {
            return_data.comparisons += 1;
            arr[j] = arr[j - 1];
            arr[lo] = key;
            return_data.operations += 3;
          }
        }
      }
    }
    std::cout << print_vector(arr) << std::endl;
    return return_data;
  }
  */
  data qsort_ret(std::vector<int> arr, int n) {
    this->arr = arr;
    qsort( 0, n-1);
    return this->return_data;
  }
  data bubble_sort_bin(std::vector<int> arr) {
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
};
class Iter : protected Sorts {
 public:
  Iter(const int n) {
    std::vector<int> start_data;
    for (size_t i = 0; i < n; i++) {
      start_data.push_back(get_random_number(RANDOM_MIN, RANDOM_MAX));
    }
    std::cout << print_vector(start_data) << std::endl;
    bubble_sort_slow(start_data);
    bubble_sort_fast(start_data);
    bubble_sort_bin(start_data);
    insertion_sort(start_data); 
    qsort_ret(start_data, n);
  }
};