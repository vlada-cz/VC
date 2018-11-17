#include "experiments/cover_size.hpp"

using namespace std;

void CoverSize::Run(int numberOfInterations, Algorithms &algorithm, Graph &graph, bool removePendant, bool removeRedundant)
{
  vector<int> coverSizes(numberOfInterations);
  int sum = 0;
  for (int i = 0; i < numberOfInterations; ++i)
  {
    vector<int> vertices = algorithm.Run(graph, removePendant, removeRedundant);
    coverSizes[i] = vertices.size();
    sum += vertices.size();
  }
  cout << sum / numberOfInterations << endl;
  return;
}
