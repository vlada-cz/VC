#include "experiments/time.hpp"

using namespace std;

void Time::Run(int numberOfInterations, Algorithm &algorithm, Graph &graph)
{
  auto start = chrono::high_resolution_clock::now();
  for (int i = 0; i < numberOfInterations; ++i)
  {
    algorithm.Run(graph);
  }
  auto end = chrono::high_resolution_clock::now();
  chrono::duration<double, std::milli> duration = end - start;
  cout << duration.count() / numberOfInterations << endl;
  return;
}
