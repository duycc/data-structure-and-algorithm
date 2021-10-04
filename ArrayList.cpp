//===--------------------------- test\ArrayList.cpp - [data-structure-and-algorithm] --------------------*- C++ -*-===//
// brief :
//
//
// author: YongDu
// date  : 2021-10-04
//===--------------------------------------------------------------------------------------------------------------===//

#include "src/linear_list.h"
#include "src/array_list.hpp"

void testArrayList() {
  LinearList<int> *x = new ArrayList<int>(100);
  ArrayList<double> y(100);

  ArrayList<char> z;

  ArrayList<double> w(y);
}

int main() {
  testArrayList();
  return 0;
}
