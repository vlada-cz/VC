#ifndef GIC_HPP
#define GIC_HPP

/*
 * Greedy Independent Cover
 *
-*/

#include "algorithm.hpp"

class GIC : public Algorithm
{
  public:
    GIC() : Algorithm(){}
    std::vector<int> Run(Graph graph);
    void PushNeighboursToCover(std::vector<int> &cover, std::list<int> &adjacents);
};

#endif
