//===--------------------------- algorithm/sort.hpp - [tinyDTL] -----------------------------------------*- C++ -*-===//
// Brief :
//
//
// Author: YongDu
// Date  : 2021-10-06
//===--------------------------------------------------------------------------------------------------------------===//

#if !defined(SORT_HPP)
#define SORT_HPP

#include <algorithm>

#include "ArrayList.hpp"

namespace dtl {
template <typename T>
void bubbleSort(ArrayList<T> &nums) {
  int len = nums.size();
  for (int i = 0; i < len - 1; ++i) {
    for (int j = 0; j < len - 1 - i; ++j) {
      if (nums[j] > nums[j + 1])
        std::swap(nums[j], nums[j + 1]);
    }
  }
}

template <typename T>
void selectSort(ArrayList<T> &nums) {}

} // namespace dtl
#endif // SORT_HPP
