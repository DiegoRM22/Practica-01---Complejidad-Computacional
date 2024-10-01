
#include <iostream>

#include "operations.h"

#ifndef PRIMITIVE_RECURSIVE_FUNCTION_H
#define PRIMITIVE_RECURSIVE_FUNCTION_H

class PrimitiveRecursiveFunction {
 public:
  int Zero();
  int One();
  int Sum(int firstArg, int secondArg);
  int Projection(std::vector<int> args, int position);

 private:
  int numberOfCalls;
  Operation operationManager;
};

#endif