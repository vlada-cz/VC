/*
 authors: Jan Kohút (xkohut08), Vladimír Jeřábek (xjerab21)
 date: 5. 12. 2018
 */

#include "algorithms/GIC.hpp"

using namespace std;

vector<int> GIC::Run(Graph graph, bool removePendant, bool removeRedundant)
{
  this->cover.clear();
  Graph origGraph = graph;
  if (removePendant)
  {
    this->cover = this->RemovePendantVertices(graph);
  }
  while (graph.HaveEdges())
  {
    graph.CountDegrees();
    int minDegreeVertex = graph.GetNonZeroMinDegreeVertex();
    if (minDegreeVertex == -1)
    {
      break;
    }
    list<int> adjacents = graph.GetAdjacents(minDegreeVertex);
    this->PushNeighboursToCover(adjacents);
    graph.RemoveVertices(adjacents);
  }
  if (removeRedundant)
  {
    this->cover = this->RemoveRedundantVertices(origGraph, this->cover);
  }
  return this->cover;
}

void GIC::PushNeighboursToCover(list<int> &adjacents)
{
  list<int>::iterator vertexIterator = adjacents.begin();
  //skip first vertex to get only neighbours
  ++vertexIterator;
  while (vertexIterator != adjacents.end())
  {
    this->cover.push_back(*vertexIterator);
    ++vertexIterator;
  }
}
