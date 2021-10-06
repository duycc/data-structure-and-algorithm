//===--------------------------- solution/sort.hpp - [tinyDTL] ------------------------------------------*- C++ -*-===//
// Brief :
//  Impl of all sorting algorithms
//
// Author: YongDu
// Date  : 2021-10-06
//===--------------------------------------------------------------------------------------------------------------===//

#if !defined(SORT_HPP)
#define SORT_HPP

#include <algorithm>

#include "ArrayList.hpp"

namespace dtl {
namespace solution {

template <typename T>
void bubbleSort(ArrayList<T> &nums) {
  int len = nums.size();
  for (int i = 0; i < len - 1; ++i) {
    for (int j = 0; j < len - 1 - i; ++j) {
      if (nums[j] > nums[j + 1])
        dtl::swap(nums[j], nums[j + 1]);
    }
  }
}

template <typename T>
void selectSort(ArrayList<T> &nums) {}

void testSort() {
  fmtRun("Run Sort Test", Color::kBlue);
  ArrayList<int> nums{26, 3, 49, 556, 81, 9, 863, 0};

  fmtOut("Unsorted elements: ", Color::kGreen);
  cout << nums << endl;

  bubbleSort(nums);

  fmtOut("Sorted elements: ", Color::kGreen);
  cout << nums << endl;
}

} // namespace solution
} // namespace dtl

#endif // SORT_HPP
