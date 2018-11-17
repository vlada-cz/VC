#include "algorithms/MDG.hpp"

using namespace std;

vector<int> MDG::Run(Graph graph, bool removePendant, bool removeRedundant)
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
    int maxDegreeVertex = graph.GetNonZeroMaxDegreeVertex();
    if (maxDegreeVertex == -1)
    {
      break;
    }
    graph.RemoveVertex(maxDegreeVertex);
    this->cover.push_back(maxDegreeVertex);
  }
  if (removeRedundant)
  {
    this->cover = this->RemoveRedundantVertices(origGraph, this->cover);
  }
  return this->cover;
}
