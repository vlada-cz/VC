#include "algorithms/GIC.hpp"

using namespace std;

vector<int> GIC::Run(Graph graph)
{
  vector<int> cover;
  while (graph.HaveEdges())
  {
    int minDegreeVertex = graph.GetNonZeroMinDegreeVertex();
    list<int> adjacents = graph.GetAdjacents(minDegreeVertex);
    this->PushNeighboursToCover(cover, adjacents);
    graph.RemoveVertices(adjacents);
  }
  return cover;
}

void GIC::PushNeighboursToCover(vector<int> &cover, list<int> &adjacents)
{
  list<int>::iterator vertexIterator = adjacents.begin();
  //skip first vertex to get only neighbours
  ++vertexIterator;
  while (vertexIterator != adjacents.end())
  {
    cover.push_back(*vertexIterator);
    ++vertexIterator;
  }
}
