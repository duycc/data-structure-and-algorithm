//===--------------------------- data-structure/IllegalParameter.h --------------------------------------*- C++ -*-===//
// brief :
//
//
// author: YongDu
// date  : 2021-10-04
//===--------------------------------------------------------------------------------------------------------------===//

#if !defined(ILLEGAL_PARAMETER_H)
#define ILLEGAL_PARAMETER_H

#include <string>
#include <iostream>

class IllegalParameter {
public:
  IllegalParameter() : message_("Illegal parameter value") {}
  IllegalParameter(std::string message) : message_(message) {}
  void outputMessage() { std::cout << message_ << std::endl; }

private:
  std::string message_;
};

#endif // ILLEGAL_PARAMETER_H
