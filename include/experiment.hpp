#ifndef EXPERIMENT_HPP
#define EXPERIMENT_HPP

#include "graph.hpp"
#include "algorithms.hpp"
#include <chrono>

class Experiment
{
  public:
    void virtual Run(int numberOfInterations, Algorithms &algorithm, Graph &graph, bool removePendant, bool removeRedundant) = 0;
    virtual ~Experiment(){}

  protected:
    Experiment(){}
};


#endif
