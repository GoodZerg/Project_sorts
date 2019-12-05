#include "Sorts.h"

int main() {
  std::vector<int> sizes;

  sizes.push_back(500);
  sizes.push_back(800);
  sizes.push_back(1000);
  sizes.push_back(2700);
  sizes.push_back(5000);

  std::vector<std::string> vector_of_sorts_names;

  vector_of_sorts_names.push_back("binary_insert_sort");
  vector_of_sorts_names.push_back("qsort");
  vector_of_sorts_names.push_back("bubble_sort_slow");
  vector_of_sorts_names.push_back("bubble_sort_fast");
  vector_of_sorts_names.push_back("bubble_sort_bin");
  vector_of_sorts_names.push_back("insertion_sort");
  vector_of_sorts_names.push_back("merge_sort");

  file_out_co <<  ";";
  file_out_op <<  ";";

  for (auto i : vector_of_sorts_names) {
    file_out_co << i << ";";
    file_out_op << i << ";";
  }

  file_out_co << "\n";
  file_out_op << "\n";

  for (auto i : sizes) {
    interface* n = new interface(i);
    delete n;
  }

  system("pause");
  return 0;
}