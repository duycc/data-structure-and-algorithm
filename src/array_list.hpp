//===--------------------------- src\array_list.hpp - [data-structure-and-algorithm] --------------------*- C++ -*-===//
// brief :
//
//
// author: YongDu
// date  : 2021-10-04
//===--------------------------------------------------------------------------------------------------------------===//

#if !defined(ARRAY_LIST_HPP)
#define ARRAY_LIST_HPP

#include <algorithm>
#include <sstream>

#include "linear_list.h"
#include "illegal_param.h"

template <typename T>
class ArrayList : public LinearList<T> {
public:
  ArrayList(int initialCapacity = 10);
  ArrayList(const ArrayList<T> &);
  ~ArrayList() { delete[] element; }

  bool empty() const override { return listSize == 0; }
  int size() const override { return listSize; }
  T &get(int theIndex) const override;
  int indexOf(const T &theElement) const override;
  void erase(int theIndex) override;
  void insert(int theIndex, const T &theElement) override;
  void output(std::ostream &out) const override;

  int capacity() const { return arrayLength; }

protected:
  T *element;
  int arrayLength;
  int listSize;

  void checkIndex(int theIndex) const;
};

template <typename T>
ArrayList<T>::ArrayList(int initialCapacity) {
  if (initialCapacity < 1) {
    std::ostringstream s;
    s << "Initial capacity = " << initialCapacity << " Must be > 0";
    throw IllegalParameterValue("test");
  }
  arrayLength = initialCapacity;
  element = new T[arrayLength];
  listSize = 0;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &theList) {
  arrayLength = theList.arrayLength;
  listSize = theList.listSize;
  element = new T[arrayLength];
  std::copy(theList.element, theList.element + listSize, element);
}

#endif // ARRAY_LIST_HPP
