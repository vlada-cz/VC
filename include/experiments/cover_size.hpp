#ifndef COVER_SIZE_HPP
#define COVER_SIZE_HPP

#include "experiment.hpp"

class CoverSize : public Experiment
{
  public:
    CoverSize() : Experiment(){}
    void Run(int numberOfInterations, Algorithm &algorithm, Graph &graph);
    ~CoverSize(){}
};

#endif
