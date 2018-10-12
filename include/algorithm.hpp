#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include "graph.hpp"

class Algorithm
{
  public:
    Algorithm(){}
    std::vector<size_t> virtual Run(Graph graph){}
    virtual ~Algorithm(){}
};

#endif
