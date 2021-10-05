//===--------------------------- data-structure/Iterator.h - [tinyDTL] ----------------------------------*- C++ -*-===//
// Brief :
//   Iterator - impl
//
// Author: YongDu
// Date  : 2021-10-06
//===--------------------------------------------------------------------------------------------------------------===//

#if !defined(ITERATOR_H)
#define ITERATOR_H

#include <iterator>

namespace dtl {
template <typename T>
class Iterator {
public:
  typedef std::bidirectional_iterator_tag iterator_category;
  typedef T                               value_type;
  typedef std::ptrdiff_t                  difference_type;
  typedef T *                             pointer;
  typedef T &                             reference;

  Iterator(T *thePosition = 0) : position(thePosition) {}

  T &operator*() const { return *position; }
  T *operator->() const { return &*position; }

  Iterator &operator++() {
    ++position;
    return *this;
  }
  Iterator operator++(int) {
    Iterator old = *this;
    ++position;
    return old;
  }

  Iterator &operator--() {
    --position;
    return *this;
  }
  Iterator operator--(int) {
    Iterator old = *this;
    --position;
    return old;
  }

  bool operator!=(const Iterator rhs) const { return position != rhs.position; }
  bool operator==(const Iterator rhs) const { return position == rhs.position; }

protected:
  T *position;
};
} // namespace dtl

#endif // ITERATOR_H
