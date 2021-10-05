//===--------------------------- test/testSort.hpp - [tinyDTL] ------------------------------------------*- C++ -*-===//
// Brief :
//   test Sort Alogrithm
//
// Author: YongDu
// Date  : 2021-10-06
//===--------------------------------------------------------------------------------------------------------------===//

#if !defined(TEST_SORT_HPP)
#define TEST_SORT_HPP

#include <iostream>
#include <iterator>

#include "sort.hpp"
#include "util.h"

using std::cout;
using std::endl;

namespace dtl {
namespace test {

void testSort() {
  fmtRun("Run Sort Test", Color::kBlue);
  ArrayList<int> nums{26, 3, 49, 556, 81, 9, 863, 0};

  fmtOut("Unsorted elements: ", Color::kGreen);
  cout << nums << endl;

  bubbleSort(nums);

  fmtOut("Sorted elements: ", Color::kGreen);
  cout << nums << endl;
}

} // namespace test
} // namespace dtl

#endif // TEST_SORT_HPP
