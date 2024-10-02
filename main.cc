/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Complejidad Computacional
  *
  * @author Diego Rodríguez Martín
  * @since 02-10-2024
  * @brief Main file to execute the pow function
  *
*/

#include <iostream>

#include "PrimitiveRecursiveFunction.h"
#include "operations.h"
#include "tools.h"


int main(int argc, char** argv) {
  Usage(argc, argv);
  PrimitiveRecursiveFunction prf;
  Operation operation;
  int  firstArg = std::stoi(argv[1]);
  int  secondArg = std::stoi(argv[2]);

  std::vector<int> args = {firstArg, prf.Zero()};

  std::cout << "Pow of " << firstArg << " and " << secondArg << " is " << prf.Pow(firstArg, secondArg) << std::endl;
  std::cout << "Number of calls: " << prf.getNumberOfCalls() << std::endl;
    


  return 0;
}