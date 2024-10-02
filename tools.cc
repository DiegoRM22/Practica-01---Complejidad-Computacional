/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Complejidad Computacional
  *
  * @author Diego Rodríguez Martín
  * @since 02-10-2024
  * @brief Implementation of the tools
  *
*/

#include "tools.h"

/**
 * @brief Check if a string is a natural number
 * @param str
 * @return bool
 */
bool isANaturalNumber(const std::string& str) {
  for (char c : str) {
    if (!std::isdigit(c)) {
      return false;
    }
  }
  int number = std::stoi(str);
  if (number < 0) {
    return false;
  }
  return true;
}

/**
 * @brief Show the usage of the program
 * @param argc
 * @param argv
 */
void Usage(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " <first number> <second number>" << std::endl;
    exit(1);
  }
  if (!isANaturalNumber(argv[1]) || !isANaturalNumber(argv[2])) {
    std::cout << "Both arguments must be natural numbers" << std::endl;
    exit(1);
  }
}