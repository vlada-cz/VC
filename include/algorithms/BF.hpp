/*
 authors: Jan Kohút (xkohut08), Vladimír Jeřábek (xjerab21)
 date: 5. 12. 2018
 */

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
