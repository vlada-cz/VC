#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include "graph.hpp"

class Algorithm
{
  public:
    Algorithm(){}
    std::vector<int> virtual Run(Graph graph){}
    virtual ~Algorithm(){}
};

#endif
