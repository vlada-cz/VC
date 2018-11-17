#ifndef TIME_SIZE_HPP
#define TIME_SIZE_HPP

#include "experiments.hpp"

class TimeSize : public Experiments
{
  public:
    TimeSize() : Experiments(){}
    std::pair<double, int> Run(int numberOfInterations, Algorithms &algorithm, Graph &graph, bool removePendant, bool removeRedundant);
    ~TimeSize(){}
};

#endif
