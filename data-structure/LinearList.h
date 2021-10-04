//===--------------------------- data-structure/LinearList.h --------------------------------------------*- C++ -*-===//
// brief :
//
//
// author: YongDu
// date  : 2021-10-04
//===--------------------------------------------------------------------------------------------------------------===//

#if !defined(LINEAR_LIST_H)
#define LINEAR_LIST_H

#include <iostream>

template <typename T>
class LinearList {
public:
  virtual ~LinearList() {}
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual T &get(int index) const = 0;
  virtual int index(const T &element) const = 0;
  virtual void erase(int index) = 0;
  virtual void insert(int index, const T &element) = 0;
  virtual void output(std::ostream &out) const = 0;
};

#endif // LINEAR_LIST_H
