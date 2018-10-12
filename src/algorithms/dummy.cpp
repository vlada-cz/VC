#include "algorithms/dummy.hpp"

using namespace std;

vector<shared_ptr<size_t>> Dummy::Run(Graph graph)
{
  vector<shared_ptr<size_t>> vertices;
  list<list<shared_ptr<size_t>>> adjacencyList = graph.GetAdjacencyList();
  for (auto const& adjacency : adjacencyList)
  {
    vertices.push_back(adjacency.front());
  }
  return vertices;
}
