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
  IllegalParameter() : message("Illegal parameter value") {}
  IllegalParameter(std::string msg) : message(msg) {}
  void outputMessage() { std::cout << message << std::endl; }

private:
  std::string message;
};

#endif // ILLEGAL_PARAMETER_H
