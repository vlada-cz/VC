#ifndef EXPERIMENT_HPP
#define EXPERIMENT_HPP

#include "graph.hpp"
#include "algorithm.hpp"
#include <chrono>

class Experiment
{
  public:
    void virtual Run(int numberOfInterations, Algorithm &algorithm, Graph &graph) = 0;
    virtual ~Experiment(){}

  protected:
    Experiment(){}
};


#endif
