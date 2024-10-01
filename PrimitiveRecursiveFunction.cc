#include "PrimitiveRecursiveFunction.h"

/**
 * @brief Construct the Primitive Recursive Function for zero
 * @return int
 */
int PrimitiveRecursiveFunction::Zero() {
  ++numberOfCalls;
  return 0;
}

/**
 * @brief Construct the Primitive Recursive Function for one
 * @return int
 */
int PrimitiveRecursiveFunction::One() {
  ++numberOfCalls;
  return this->Zero() + 1;
}

/**
 * @brief Construct the Primitive Recursive Function for sum
 * @param firstArg
 * @param secondArg
 * @return int
 */
int PrimitiveRecursiveFunction::Sum(int firstArg, int secondArg) {
  std::cout << "Sum of " << firstArg << " and " << secondArg << std::endl;
  if (secondArg == 0) {
    return this->Projection({firstArg, this->Zero()}, 0);
  } else {
    PrimitiveRecursiveFunction primitiveFunction;
    auto successorFunc = std::bind(&Operation::Successor, &operationManager, std::placeholders::_1);
    auto sumFunc = std::bind(&PrimitiveRecursiveFunction::Sum, &primitiveFunction, std::placeholders::_1, std::placeholders::_2);
    return operationManager.Composition(firstArg, operationManager.Predecessor(secondArg), successorFunc, sumFunc);
  }
}

/**
 * @brief Construct the Operation for Projection
 * @param args
 * @param position
 * @return int
 */
int PrimitiveRecursiveFunction::Projection(std::vector<int> args, int position) {
  return args[position];
}


  