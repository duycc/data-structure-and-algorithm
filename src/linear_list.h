//===--------------------------- src\linear_list.h - [data-structure-and-algorithm] ---------------------*- C++ -*-===//
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
  virtual ~LinearList(){};
  virtual bool empty() const = 0;
  virtual int size() const = 0;
  virtual T &get(int theIndex) const = 0;
  virtual int indexOf(const T &theElement) const = 0;
  virtual void erase(int theIndex) = 0;
  virtual void insert(int theIndex, const T &theElement) = 0;
  virtual void output(std::ostream &out) const = 0;
};

#endif // LINEAR_LIST_H
