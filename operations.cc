#include <functional>

#include "operations.h"



/**
 * @brief Construct the Operation for Successor
 * @param arg
 * @return int
 */
int Operation::Successor(int arg) {
  return arg + 1;
}

/**
 * @brief Construct the Operation for Composition
 * @param args
 * @return int
 */
int Operation::Composition(int firstArg, int secondArg, std::function<int(int)> firstFunction,
                           std::function<int(int, int)> secondFunction) {
  std::cout << "Composicion de las funciones: " << firstArg << " y " << secondArg << std::endl;
  return firstFunction(secondFunction(firstArg, secondArg));
}

/**
 * @brief Construct the Operation for Predecessor
 * @param arg
 * @return int
 */
int Operation::Predecessor(int arg) {
  return arg - 1;
}

/**
 * @brief Construct the Operation for Combination
 * @param firstArg
 * @param secondArg
 * @return std::vector<int>
 */
std::vector<int> Operation::Combination(std::vector<int> firstArg, std::vector<int> secondArg) {
  std::cout << "Combinacion de los vectores: " << firstArg[0] << " y " << secondArg[0] << std::endl;
  std::vector<int> result;
  result.push_back(secondArg[0]);
  result.push_back(firstArg[0]);
  return result;
}