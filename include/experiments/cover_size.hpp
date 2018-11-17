#ifndef COVER_SIZE_HPP
#define COVER_SIZE_HPP

#include "experiment.hpp"

class CoverSize : public Experiment
{
  public:
    CoverSize() : Experiment(){}
    void Run(int numberOfInterations, Algorithms &algorithm, Graph &graph, bool removePendant, bool removeRedundant);
    ~CoverSize(){}
};

#endif
