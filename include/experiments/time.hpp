#ifndef TIME_HPP
#define TIME_HPP

#include "experiment.hpp"

class Time : public Experiment
{
  public:
    Time() : Experiment(){}
    void Run(int numberOfInterations, Algorithms &algorithm, Graph &graph, bool removePendant, bool removeRedundant);
    ~Time(){}
};

#endif
