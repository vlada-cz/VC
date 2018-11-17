#include "algorithms/dummy.hpp"

using namespace std;

vector<int> Dummy::Run(Graph graph, bool removePendant, bool removeRedundant)
{
  this->cover.clear();
  list<list<int>> adjacencyList = graph.GetAdjacencyList();
  for (auto const& adjacency : adjacencyList)
  {
    this->cover.push_back(adjacency.front());
  }
  if (removeRedundant)
  {
    this->cover = this->RemoveRedundantVertices(graph, this->cover);
  }
  return this->cover;
}
