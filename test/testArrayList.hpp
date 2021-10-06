//===--------------------------- test/testArrayList.hpp - [tinyDTL] -------------------------------------*- C++ -*-===//
// Brief :
//
//
// Author: YongDu
// Date  : 2021-10-06
//===--------------------------------------------------------------------------------------------------------------===//

#if !defined(TEST_ARRAY_LIST_HPP)
#define TEST_ARRAY_LIST_HPP

#include <algorithm>
#include <numeric>

#include "ArrayList.hpp"

using std::cout;
using std::endl;

namespace dtl {
namespace test {

void testArrayList() {
  fmtRun("Run ArrayList Test", Color::kBlue);
  try {
    LinearList<int> * x = new ArrayList<int>(100);
    ArrayList<double> y(100);
    ArrayList<char>   z;
    ArrayList<double> w(y);

    // std::cout << w.capacity() << std::endl;
    // std::cout << w.get(0) << std::endl;
    // std::cout << w.indexOf(0.0) << std::endl;

    ArrayList<int> a(3);
    std::cout << a.capacity() << std::endl;
    std::cout << a.size() << std::endl;
    a.insert(0, 0);
    std::cout << a.capacity() << std::endl;
    std::cout << a.size() << std::endl;
    a.insert(1, 1);
    std::cout << a.capacity() << std::endl;
    std::cout << a.size() << std::endl;
    a.insert(2, 2);
    std::cout << a.capacity() << std::endl;
    std::cout << a.size() << std::endl;

    std::cout << a.indexOf(2) << std::endl;
    std::cout << a << std::endl;
    a.erase(1);
    std::cout << a.size() << std::endl;

    std::cout << a[0] << ", " << a[1] << std::endl;
    std::swap(a[0], a[1]);
    std::cout << a[0] << ", " << a[1] << std::endl;

    ArrayList<int> b(3);
    b.insert(0, 1);
    b.insert(1, 2);
    b.insert(2, 3);
    std::cout << b << std::endl;
    std::reverse(b.begin(), b.end());
    std::cout << b << std::endl;

    std::cout << std::accumulate(b.begin(), b.end(), 0) << std::endl;

    ArrayList<int> c{1, 2, 3, 4, 5};
    cout << c << endl;

  } catch (Exception &e) {
    e.outputMessage();
  }
}

} // namespace test
} // namespace dtl

#endif // TEST_ARRAY_LIST_HPP
