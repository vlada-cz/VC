#include "experiments/space.hpp"

using namespace std;

void Space::Run(int numberOfInterations, Algorithms &algorithm, Graph &graph, bool removePendant, bool removeRedundant)
{
  for (int i = 0; i < numberOfInterations; ++i)
  {
    algorithm.Run(graph, removePendant, removeRedundant);
  }
  return;
}
