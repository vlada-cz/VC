/*
 authors: Jan Kohút (xkohut08), Vladimír Jeřábek (xjerab21)
 date: 5. 12. 2018
 */

#ifndef EXPERIMENTS_HPP
#define EXPERIMENTS_HPP

#include "graph.hpp"
#include "algorithms.hpp"
#include <chrono>
#include <utility>

class Experiments
{
  public:
    std::pair<double, int> virtual Run(int numberOfInterations, Algorithms &algorithm, Graph &graph, bool removePendant, bool removeRedundant) = 0;
    virtual ~Experiments(){}

  protected:
    Experiments(){}
};


#endif
