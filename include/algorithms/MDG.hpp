/*
 authors: Jan Kohút (xkohut08), Vladimír Jeřábek (xjerab21)
 date: 5. 12. 2018
 */

#ifndef MDG_HPP
#define MDG_HPP

/*
 * Maximum Degree Greedy
 *
 * Get vertex of maximum degree, remove it and add it to vertex cover
 */

#include "algorithms.hpp"

class MDG : public Algorithms
{
  public:
    MDG() : Algorithms(){}
    std::vector<int> Run(Graph graph, bool removePendant, bool removeRedundant);
};

#endif
