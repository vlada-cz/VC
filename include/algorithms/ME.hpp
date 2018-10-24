#ifndef ME_HPP
#define ME_HPP

/*
 * Max Edge
 *
 */

#include "algorithms.hpp"

class ME : public Algorithms
{
  public:
    ME() : Algorithms(){}
    std::vector<int> Run(Graph graph, bool removePendant, bool removeRedundant);
    Graph RemoveMaxEdge(Graph &graph);
    std::pair<int, int> GetMaxEdge(Graph &graph);
    std::vector<int> cover;
};

#endif
