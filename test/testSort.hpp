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

using std::cout;
using std::endl;

namespace dtl {
namespace test {

void testSort() {
  std::cout << "//============================================================================//" << std::endl;
  std::cout << "//===--------------------------- Run Sort Test ----------------------------===//" << std::endl;

  std::vector<int> vec = {26, 3, 49, 556, 81, 9, 863, 0};
  cout << "before sort:\n";
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{cout, " "});
  cout << endl;

  bubbleSort(vec);

  cout << "after sort:\n";
  std::copy(vec.begin(), vec.end(), std::ostream_iterator<int>{cout, " "});
  cout << endl;

  std::vector<int> vec1;
  std::cout << vec1.capacity() << std::endl;
  vec.push_back(1);
  std::cout << vec1.capacity() << std::endl;

  std::cout << "//===--------------------------- End Sort Test ----------------------------===//" << std::endl;
  std::cout << "//============================================================================//" << std::endl;
}

} // namespace test
} // namespace dtl

#endif // TEST_SORT_HPP
