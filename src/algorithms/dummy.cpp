#include "algorithms/dummy.hpp"

using namespace std;

vector<int> Dummy::Run(Graph graph)
{
  vector<int> vertices;
  list<list<int>> adjacencyList = graph.GetAdjacencyList();
  for (auto const& adjacency : adjacencyList)
  {
    vertices.push_back(adjacency.front());
  }
  return vertices;
}
