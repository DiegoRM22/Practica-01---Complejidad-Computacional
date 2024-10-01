#include <iostream>

#include "PrimitiveRecursiveFunction.h"
#include "operations.h"


int main(int argc, char** argv) {
  PrimitiveRecursiveFunction prf;
  Operation operation;
  int  firstArg = std::stoi(argv[1]);
  int  secondArg = std::stoi(argv[2]);

  std::vector<int> args = {firstArg, prf.Zero()};

  std::cout << "Sum of " << firstArg << " and " << secondArg << " is " << prf.Sum(firstArg, secondArg) << std::endl;
    


  return 0;
}