/*
 authors: Jan Kohút (xkohut08), Vladimír Jeřábek (xjerab21)
 date: 5. 12. 2018
 */

#ifndef ME_HPP
#define ME_HPP

/*
 * Max Edge
 *
 * Get edge which vertices have total maximum degree, remove these vertices
 * and add them to cover
 */

#include "algorithms.hpp"

class ME : public Algorithms
{
  public:
    ME() : Algorithms(){}
    std::vector<int> Run(Graph graph, bool removePendant, bool removeRedundant);
    Graph RemoveMaxEdge(Graph &graph);
    std::pair<int, int> GetMaxEdge(Graph &graph);
};

#endif
