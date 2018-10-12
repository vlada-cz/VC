#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "algorithm.hpp"

class Dummy : public Algorithm
{
  public:
    Dummy() : Algorithm(){}
    std::vector<size_t> Run(Graph graph);
};

#endif
