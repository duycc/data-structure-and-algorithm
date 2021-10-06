//===--------------------------- dtl/Exception.h - [tinyDTL] --------------------------------------------*- C++ -*-===//
// Brief :
//   Exception-impl
//
// Author: YongDu
// Date  : 2021-10-06
//===--------------------------------------------------------------------------------------------------------------===//

#if !defined(EXCEPTION_H)
#define EXCEPTION_H

#include <string>
#include <iostream>

namespace dtl {

class Exception {
public:
  Exception() = default;
  Exception(std::string msg) : message(msg) {}
  virtual void outputMessage() { std::cout << message << std::endl; }

protected:
  std::string message;
};

class IllegalParameter : public Exception {
public:
  IllegalParameter(std::string msg) : Exception(msg) {}
  void outputMessage() override { std::cout << message << std::endl; }
};

class IllegalIndex : public Exception {
public:
  IllegalIndex(std::string msg) : Exception(msg) {}
  void outputMessage() override { std::cout << message << std::endl; }
};

} // namespace dtl

#endif // EXCEPTION_H
