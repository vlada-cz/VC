#include "experiments/space.hpp"

using namespace std;

void Space::Run(int numberOfInterations, Algorithm &algorithm, Graph &graph)
{
  for (int i = 0; i < numberOfInterations; ++i)
  {
    algorithm.Run(graph);
  }
  return;
}
