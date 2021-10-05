
#if !defined(TEST_ARRAY_LIST_HPP)
#define TEST_ARRAY_LIST_HPP

#include "ArrayList.hpp"

namespace dtl {
namespace test {

void testArrayList() {
  try {
    LinearList<int> *x = new ArrayList<int>(100);
    ArrayList<double> y(100);
    ArrayList<char> z;
    ArrayList<double> w(y);

    std::cout << w.capacity() << std::endl;
    // std::cout << w.get(0) << std::endl;
    // std::cout << w.indexOf(0.0) << std::endl;

    ArrayList<int> a(a);
    std::cout << a.capacity() << std::endl;
    std::cout << a.size() << std::endl;
    a.insert(0, 0);
    a.insert(1, 1);
    a.insert(2, 2);
    std::cout << a.capacity() << std::endl;
    std::cout << a.size() << std::endl;
    std::cout << a.indexOf(2) << std::endl;
    std::cout << a << std::endl;
    a.erase(1);
    std::cout << a.size() << std::endl;

    a.output(std::cout);
  } catch (Exception &e) {
    e.outputMessage();
  }
}

} // namespace test
} // namespace dtl

#endif // TEST_ARRAY_LIST_HPP
