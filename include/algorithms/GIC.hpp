#ifndef GIC_HPP
#define GIC_HPP

/*
 * Greedy Independent Cover
 *
 * Get vertex of minimum degree, remove its neighbours and add them to cover
 */

#include "algorithms.hpp"

class GIC : public Algorithms
{
  public:
    GIC() : Algorithms(){}
    std::vector<int> Run(Graph graph, bool removePendant, bool removeRedundant);
    void PushNeighboursToCover(std::list<int> &adjacents);
};

#endif
