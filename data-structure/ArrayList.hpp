#if !defined(ARRAY_LIST_HPP)
#define ARRAY_LIST_HPP

#include <sstream>
#include <algorithm>

#include "LinearList.h"
#include "IllegalParameter.h"

template <typename T>
class ArrayList : public LinearList<T> {
public:
  ArrayList(int initCapacity = 10);
  ArrayList(const ArrayList<T> &);
  ~ArrayList() { delete[] element; }

  bool empty() const override { return listSize == 0; }
  int size() const override { return listSize; }
  T &get(int theIndex) const override;
  int index(const T &theElement) const override;
  void erase(int theIndex) override;
  void insert(int theIndex, const T &theElement) override;
  void output(std::ostream &out) const override;

  int capacity() const { return arrayLength; }

protected:
  void checkIndex(int theIndex) const;

  T *element{nullptr};
  int arrayLength{0};
  int listSize{0};
};

template <typename T>
ArrayList<T>::ArrayList(int initCapacity) {}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &theList) {}

template <typename T>
void ArrayList<T>::checkIndex(int theIndex) const {}

template <typename T>
T &ArrayList<T>::get(int theIndex) const {
  checkIndex(theIndex);
  return element[theIndex];
}

template <typename T>
int ArrayList<T>::index(const T &theElement) const {
  return 0;
}

template <typename T>
void ArrayList<T>::erase(int theIndex) {}

template <typename T>
void ArrayList<T>::insert(int theIndex, const T &theElement) {}

template <typename T>
void ArrayList<T>::output(std::ostream &out) const {}

#endif // ARRAY_LIST_HPP
