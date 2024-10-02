/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Complejidad Computacional
  *
  * @author Diego Rodríguez Martín
  * @since 02-10-2024
  * @brief Implementation of the Primitive Recursive Functions
  *
*/

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
  return Operation().Successor(Zero());
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

/**
 * @brief Construct the Primitive Recursive Function for sum
 * @param firstArg
 * @param secondArg
 * @return int
 */
int PrimitiveRecursiveFunction::Sum(int firstArg, int secondArg) {
  ++numberOfCalls;
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
 * @brief Construct the Primitive Recursive Function for product
 * @param firstArg
 * @param secondArg
 * @return int
 */
int PrimitiveRecursiveFunction::Product(int firstArg, int secondArg) {
  ++numberOfCalls;
  if (secondArg == 0) {
    return this->Zero();
  } else {
    int rightProjection = this->Projection({firstArg, secondArg, this->Product(firstArg, operationManager.Predecessor(secondArg))}, 2);
    int leftProjection = this->Projection({firstArg, secondArg}, 0);
    std::vector<int> combination = operationManager.Combination({rightProjection}, {leftProjection});
    return this->Sum(leftProjection, rightProjection);
  }
}

/**
 * @brief Construct the Primitive Recursive Function for power
 * @param firstArg
 * @param secondArg
 * @return int
 */
int PrimitiveRecursiveFunction::Pow(int firstArg, int secondArg) {
  ++numberOfCalls;
  if (secondArg == 0) {
    return this->One();
  } else {
    int rightProjection = this->Projection({firstArg, secondArg, this->Pow(firstArg, operationManager.Predecessor(secondArg))}, 2);
    int leftProjection = this->Projection({firstArg, secondArg}, 0);
    std::vector<int> combination = operationManager.Combination({rightProjection}, {leftProjection});
    return this->Product(leftProjection, rightProjection);
  }
}




  