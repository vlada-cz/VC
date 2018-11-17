#ifndef SPACE_HPP
#define SPACE_HPP

#include "experiment.hpp"

class Space : public Experiment
{
  public:
    Space() : Experiment(){}
    void Run(int numberOfInterations, Algorithms &algorithm, Graph &graph, bool removePendant, bool removeRedundant);
    ~Space(){}
};

#endif
