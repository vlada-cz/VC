#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "algorithm.hpp"

class Dummy : public Algorithm
{
  public:
    Dummy() : Algorithm(){}
    std::vector<int> Run(Graph graph);
};

#endif
