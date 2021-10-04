//===--------------------------- src\illegal_param.h - [data-structure-and-algorithm] -------------------*- C++ -*-===//
// brief :
//
//
// author: YongDu
// date  : 2021-10-04
//===--------------------------------------------------------------------------------------------------------------===//

#if !defined(ILLEGAL_PARAM_H)
#define ILLEGAL_PARAM_H

#include <string>
#include <iostream>

class IllegalParameterValue {
public:
  IllegalParameterValue() : message("Illegal Parameter Value") {}
  IllegalParameterValue(char *theMessage) { message = theMessage; }
  void outputMessage() { std::cout << message << std::endl; }

private:
  std::string message;
};

#endif // ILLEGAL_PARAM_H
