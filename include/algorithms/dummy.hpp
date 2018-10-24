#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "algorithms.hpp"

class Dummy : public Algorithms
{
  public:
    Dummy() : Algorithms(){}
    std::vector<int> Run(Graph graph, bool removePendant, bool removeRedundant);
};

#endif
