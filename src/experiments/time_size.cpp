#include "experiments/time_size.hpp"

using namespace std;

pair<double, int> TimeSize::Run(int numberOfInterations, Algorithms &algorithm, Graph &graph, bool removePendant, bool removeRedundant)
{
  if (numberOfInterations < 1)
  {
    return make_pair(0.0, 0);
  }
  int sum = 0;
  auto start = chrono::high_resolution_clock::now();
  for (int i = 0; i < numberOfInterations; ++i)
  {
    vector<int> cover = algorithm.Run(graph, removePendant, removeRedundant);
    this->CheckCover(graph, cover);
    sum += cover.size();
  }
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, std::milli> duration = end - start;
  double t = duration.count() / numberOfInterations;
  int coverSize = sum / numberOfInterations;
  cout << t << " " << coverSize << endl;
  return make_pair(t, coverSize);
}
