
#include <iostream>
#include <vector>
#include <functional>

#ifndef OPERATIONS_H
#define OPERATIONS_H

class Operation {
 public:
  int Successor(int arg);
  int Predecessor(int arg);
  int Composition(int firstArg, int secondArg, std::function<int(int)> firstFunction,
                  std::function<int(int, int)> secondFunction);
  std::vector<int> Combination(std::vector<int> firstArg, std::vector<int> secondArg);
    
};

#endif