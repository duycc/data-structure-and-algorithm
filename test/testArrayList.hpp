
#if !defined(TEST_ARRAY_LIST_HPP)
#define TEST_ARRAY_LIST_HPP

#include "ArrayList.hpp"

void testArrayList() {
  ArrayList<int> *x = new ArrayList<int>(100);
  ArrayList<double> y(100);

  ArrayList<char> z;

  ArrayList<double> w(y);

  std::cout << z.capacity() << std::endl;
}

#endif // TEST_ARRAY_LIST_HPP
