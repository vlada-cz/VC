#include "experiments/cover_size.hpp"

using namespace std;

void CoverSize::Run(int numberOfInterations, Algorithm &algorithm, Graph &graph)
{
  vector<size_t> coverSizes(numberOfInterations);
  int sum = 0;
  for (int i = 0; i < numberOfInterations; ++i)
  {
    vector<shared_ptr<size_t>> vertices = algorithm.Run(graph);
    coverSizes[i] = vertices.size();
    sum += vertices.size();
  }
  cout << sum / numberOfInterations << endl;
  return;
}
