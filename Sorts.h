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
  std::string print_vector( std::vector<int>& arr) {
    std::stringstream ss;
    std::string s;
    for (int i = 0; i < arr.size() - 1; ++i) {
      ss <<  arr[i] << ",";
    }
    ss << arr[arr.size()-1];

    getline(ss, s);
    return s;
  }
  
};
class Iter : protected Sorts {
 public:
  Iter(const int n) { 
    std::vector<int> b(n,0);
    std::cout << print_vector(b) << std::endl;
  }
  
};