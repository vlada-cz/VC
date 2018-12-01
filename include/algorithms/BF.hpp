#ifndef BF_HPP
#define BF_HPP

#include "algorithms.hpp"

class BF : public Algorithms
{
  public:
    BF() : Algorithms(){}
    std::vector<int> Run(Graph graph, bool removePendant, bool removeRedundant);
    std::vector<std::vector<int>> GetCombinations(int n, int r);
};

#endif
