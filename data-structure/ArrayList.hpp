#if !defined(ARRAY_LIST_HPP)
#define ARRAY_LIST_HPP

#include <sstream>
#include <algorithm>

#include "LinearList.h"
#include "IllegalParameter.h"

template <typename T>
class ArrayList : public LinearList<T> {
public:
  ArrayList(int capacity = 10);
  ArrayList(const ArrayList<T> &);
  ~ArrayList() { delete[] element_; }

  bool empty() const override { return list_size_ == 0; }
  int size() const override { return list_size_; }
  T &get(int index) const override;
  int index(const T &element) const override;
  void erase(int index) override;
  void insert(int index, const T &element) override;
  void output(std::ostream &out) const override;

  int capacity() const { return array_length_; }

protected:
  void check_index(int index) const;

  T *element_;
  int array_length_;
  int list_size_;
};

template <typename T>
ArrayList<T>::ArrayList(int capacity) {
  if (capacity < 1) {
    std::ostringstream s;
    s << "Initial capacity = " << capacity << " Must be > 0";
    throw IllegalParameter(s.str());
  }
  array_length_ = capacity;
  element_ = new T[array_length_];
  list_size_ = 0;
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &list) {
  array_length_ = list.array_length_;
  list_size_ = list.list_size_;
  element_ = new T[array_length_];
  std::copy(list.element_, list.element_ + list_size_, element_);
}

template <typename T>
void ArrayList<T>::check_index(int index) const {
  if (index < 0 || index >= list_size_) {
    std::ostringstream s;
    s << "index = " << index << " size = " << list_size_;
    throw IllegalParameter(s.str());
  }
}

template <typename T>
T &ArrayList<T>::get(int index) const {
  check_index(index);
  return element_[index];
}

template <typename T>
int ArrayList<T>::index(const T &element) const {
  int index = std::find(element_, element_ + list_size_, element);
  if (index == list_size_) {
    return -1;
  }
  return index;
}

template <typename T>
void ArrayList<T>::erase(int index) {
  check_index(index);
  std::copy(element_ + index + 1， element_ + list_size_, element_ + index);
  element_[--list_size_];
}

template <typename T>
void ArrayList<T>::insert(int index, const T &element) {
  if (index < 0 || index >= list_size_) {
    std::ostringstream s;
    s << "index = " << index << " size = " << list_size_;
    throw IllegalParameter(s.str());
  }
  if (list_size_ == array_length_) { // TODO
    return;
  }
  std::copy_backward(element_ + index, element_ + list_size_, element_ + list_size_ + 1);
  element_[index] = element;
  list_size_++;
}

template <typename T>
void ArrayList<T>::output(std::ostream &out) const {
  std::copy(element_, element_ + list_size_, std::ostream_iterator<T>(std::cout, " "));
}

#endif // ARRAY_LIST_HPP
