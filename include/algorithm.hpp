#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

#include "graph.hpp"

class Algorithm
{
  public:
    Algorithm(){}
    std::vector<std::shared_ptr<size_t>> virtual Run(Graph graph){}
    virtual ~Algorithm(){}
};

#endif
