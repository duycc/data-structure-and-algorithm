//===--------------------------- algorithm/sort.hpp - [tinyDTL] -----------------------------------------*- C++ -*-===//
// Brief :
//
//
// Author: YongDu
// Date  : 2021-10-06
//===--------------------------------------------------------------------------------------------------------------===//

#if !defined(SORT_HPP)
#define SORT_HPP

#include <vector>
#include <algorithm>

namespace dtl {
template <typename T>
void bubbleSort(std::vector<T> &vec) {
  int len = vec.size();
  for (int i{}; i < len - 1; ++i) {
    for (int j{}; j < len - 1 - i; ++j) {
      if (vec[j] > vec[j + 1])
        std::swap(vec[j], vec[j + 1]);
    }
  }
}
} // namespace dtl
#endif // SORT_HPP
