#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "algorithm.hpp"

class Dummy : public Algorithm
{
  public:
    Dummy() : Algorithm(){}
    std::vector<std::shared_ptr<size_t>> Run(Graph graph);
};

#endif
