#ifndef SPACE_HPP
#define SPACE_HPP

#include "experiment.hpp"

class Space : public Experiment
{
  public:
    Space() : Experiment(){}
    void Run(int numberOfInterations, Algorithm &algorithm, Graph &graph);
    ~Space(){}
};

#endif
