/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Complejidad Computacional
  *
  * @author Diego Rodríguez Martín
  * @since 02-10-2024
  * @brief Implementation of the operations
  *
*/

#include <functional>

#include "operations.h"
#include "PrimitiveRecursiveFunction.h"



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
  return firstFunction(secondFunction(firstArg, secondArg));
}

/**
 * @brief Construct the Operation for Predecessor
 * @param arg
 * @return int
 */
int Operation::Predecessor(int arg) {
  if (arg == 0) {
    return PrimitiveRecursiveFunction().Zero();
  }
  return arg - 1;
}

/**
 * @brief Construct the Operation for Combination
 * @param firstArg
 * @param secondArg
 * @return std::vector<int>
 */
std::vector<int> Operation::Combination(std::vector<int> firstArg, std::vector<int> secondArg) {
  std::vector<int> result;
  result.push_back(secondArg[0]);
  result.push_back(firstArg[0]);
  return result;
}