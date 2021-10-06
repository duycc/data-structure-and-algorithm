//===--------------------------- dtl/util.hpp - [tinyDTL] -----------------------------------------------*- C++ -*-===//
// Brief :
//
//
// Author: YongDu
// Date  : 2021-10-06
//===--------------------------------------------------------------------------------------------------------------===//

#if !defined(UTIL_H)
#define UTIL_H

#include <string>
#include <iostream>

namespace dtl {
template <typename T>
void swap(T &lhs, T &rhs) {
  T tmp = lhs;
  lhs = rhs;
  rhs = tmp;
}

enum Color { kBlack = 30, kRed, kGreen, kYellow, kBlue, kPurple, kDarkGreen, kWhite };

void fmtRun(const std::string &text, Color color = Color::kGreen) {
  std::string colText = "\033[" + std::to_string(color) + "m" + text + "\033[0m] ";
  std::cout << "//===------------------------- [" << colText << std::string(40 - text.size(), '-') << "-===//"
            << std::endl;
}

void fmtOut(const std::string &outText, Color color = Color::kWhite) {
  std::cout << "\033[" + std::to_string(color) + "m" + outText + "\033[0m" << std::endl;
}
} // namespace dtl

#endif // UTIL_H
