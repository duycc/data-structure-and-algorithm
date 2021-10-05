//===--------------------------- data-structure/ArrayList.hpp - [tinyDTL] -------------------------------*- C++ -*-===//
// Brief :
//   ArrayList-impl
//
// Author: YongDu
// Date  : 2021-10-06
//===--------------------------------------------------------------------------------------------------------------===//

#if !defined(ARRAY_LIST_HPP)
#define ARRAY_LIST_HPP

#include <sstream>
#include <algorithm>

#include "LinearList.h"
#include "Exception.h"
#include "Iterator.h"

namespace dtl {
namespace {
template <typename T>
void changeLength1D(T *&a, int oldLegth, int newLength) {
  if (newLength < 0) {
    throw IllegalParameter("new length must be >= 0");
  }
  T * temp = new T[newLength];
  int number = std::min(oldLegth, newLength);
  std::copy(a, a + number, temp);
  delete[] a;
  a = temp;
}
} // namespace

template <typename T>
class ArrayList : public LinearList<T> {
public:
  ArrayList(int initCapacity = 10);
  ArrayList(const ArrayList<T> &);
  ~ArrayList() { delete[] element; }

  bool empty() const override { return listSize == 0; }
  int  size() const override { return listSize; }
  T &  get(int theIndex) const override;
  int  indexOf(const T &theElement) const override;
  void erase(int theIndex) override;
  void insert(int theIndex, const T &theElement) override;
  void output(std::ostream &out) const override;

  int capacity() const { return arrayLength; }

  T &operator[](int theIndex) const {
    checkIndex(theIndex);
    return element[theIndex];
  }

public:
  Iterator<T> begin() { return Iterator<T>(element); }
  Iterator<T> end() { return Iterator<T>(element + listSize); }

protected:
  void checkIndex(int theIndex) const;

  T * element{nullptr};
  int arrayLength{0};
  int listSize{0};
};

template <typename T>
ArrayList<T>::ArrayList(int initCapacity) {
  if (initCapacity < 1) {
    std::ostringstream s;
    s << "Initial Capacity = " << initCapacity << " Must be > 0";
    throw IllegalParameter(s.str());
  }
  this->arrayLength = initCapacity;
  this->element = new T[arrayLength];
  this->listSize = 0;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &theList) {
  arrayLength = theList.arrayLength;
  listSize = theList.listSize;
  element = new T[arrayLength];
  std::copy(theList.element, theList.element + listSize, this->element);
}

template <typename T>
void ArrayList<T>::checkIndex(int theIndex) const {
  if (theIndex < 0 || theIndex >= listSize) {
    std::ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw IllegalIndex(s.str());
  }
}

template <typename T>
T &ArrayList<T>::get(int theIndex) const {
  checkIndex(theIndex);
  return element[theIndex];
}

template <typename T>
int ArrayList<T>::indexOf(const T &theElement) const {
  int theIndex = static_cast<int>(std::find(element, element + listSize, theElement) - element);
  if (theIndex == listSize) {
    return -1;
  }
  return theIndex;
}

template <typename T>
void ArrayList<T>::erase(int theIndex) {
  this->checkIndex(theIndex);
  std::copy(element + theIndex + 1, element + listSize, element + theIndex);
  element[--listSize].~T(); // 自定义类型需要调用析构函数
}

template <typename T>
void ArrayList<T>::insert(int theIndex, const T &theElement) {
  if (theIndex < 0 || theIndex > listSize) {
    std::ostringstream s;
    s << "index = " << theIndex << ", size = " << listSize;
    throw IllegalIndex(s.str());
  }
  if (listSize == arrayLength) {
    int newLength = arrayLength == 0 ? 2 : 2 * arrayLength;
    changeLength1D(element, arrayLength, newLength);
    arrayLength = newLength;
  }
  std::copy_backward(element + theIndex, element + listSize, element + listSize + 1);
  element[theIndex] = theElement;
  listSize++;
}

template <typename T>
void ArrayList<T>::output(std::ostream &out) const {
  std::copy(element, element + listSize, std::ostream_iterator<T>{out, " "});
}

template <typename T>
std::ostream &operator<<(std::ostream &out, const ArrayList<T> &x) {
  x.output(out);
  return out;
}

} // namespace dtl

#endif // ARRAY_LIST_HPP
