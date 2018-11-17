#ifndef GIC_HPP
#define GIC_HPP

/*
 * Greedy Independent Cover
 *
 */

#include "algorithms.hpp"

class GIC : public Algorithms
{
  public:
    GIC() : Algorithms(){}
    std::vector<int> Run(Graph graph, bool removePendant, bool removeRedundant);
    void PushNeighboursToCover(std::list<int> &adjacents);
    std::vector<int> cover;
};

#endif
