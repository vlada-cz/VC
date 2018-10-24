#include "experiments/time.hpp"

using namespace std;


void Time::Run(int numberOfInterations, Algorithms &algorithm, Graph &graph, bool removePendant, bool removeRedundant)
{
  auto start = chrono::high_resolution_clock::now();
  for (int i = 0; i < numberOfInterations; ++i)
  {
    algorithm.Run(graph, removePendant, removeRedundant);
  }
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, std::milli> duration = end - start;
  cout << duration.count() / numberOfInterations << endl;
  return;
}
