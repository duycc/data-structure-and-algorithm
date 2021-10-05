//===--------------------------- test/testSort.hpp - [data-structure-and-algorithm] ---------------------*- C++ -*-===//
// brief :
//
//
// author: YongDu
// date  : 2021-10-04
//===--------------------------------------------------------------------------------------------------------------===//

#if !defined(TEST_SORT_HPP)
#define TEST_SORT_HPP

#include <iostream>
#include <iterator>

#include "sort.hpp"

using std::cout;
using std::endl;

namespace dtl {
namespace test {

void testSort() {
  std::vector<int> vec = {26, 3, 49, 556, 81, 9, 863, 0};

  cout << "before sort:\n";
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{cout, " "});
  cout << endl;

  bubbleSort(vec);

  cout << "after sort:\n";
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{cout, " "});
  cout << endl;

  return;
}

} // namespace test
} // namespace dtl

#endif // TEST_SORT_HPP
