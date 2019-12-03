#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define INT long long

class Sorts {
 protected:
  struct data {
    INT operations = 0;
    INT comparisons = 0;
  };
  int get_random_number(int min, int max) {
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
  }
  std::string print_vector(std::vector<int>& arr) {
    std::stringstream ss;
    std::string s;
    for (int i = 0; i < arr.size() - 1; ++i) {
      ss <<  arr[i] << ",";
    }
    ss << arr[arr.size()-1];

    getline(ss, s);
    return s;
  }
  data bubble_sort_slow(std::vector<int>& arr) {
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
  data bubble_sort_fast(std::vector<int>& arr) {
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
      if (b){
        return_data.comparisons += 1;
        break;
      }
     
    }
    return return_data;
  }
  data insertion_sort(std::vector<int>& arr) {
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
  data insertion_sort_bin(std::vector<int>& arr) {
    data return_data;
    for (int i = 1; i < arr.size(); ++i) {
      return_data.comparisons += 1;
      int key = arr[i];
      int lo, hi = i;
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
    return return_data;
  }
};
class Iter : protected Sorts {
 public:
  Iter(const int n) { 
    std::vector<int> b(n,0);
    std::cout << print_vector(b) << std::endl;
  }
  
};