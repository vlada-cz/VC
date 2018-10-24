#include "algorithms/ME.hpp"

using namespace std;

vector<int> ME::Run(Graph graph, bool removePendant, bool removeRedundant)
{
  this->cover.clear();
  while (graph.HaveEdges())
  {
    graph.Print();
    this->RemoveMaxEdge(graph);
  }
  graph.Print();
  return this->cover;
}

Graph ME::RemoveMaxEdge(Graph &graph)
{
  pair<int, int> maxEdge = this->GetMaxEdge(graph);
  if (maxEdge.first != -1 && maxEdge.second != -1)
  {
    cout << maxEdge.first << ", " << maxEdge.second << endl;
    list<int> verticesToRemove = {maxEdge.first, maxEdge.second};
    this->cover.push_back(maxEdge.first);
    this->cover.push_back(maxEdge.second);
    graph.RemoveVertices(verticesToRemove);
  }
  return graph;
}

pair<int, int> ME::GetMaxEdge(Graph &graph)
{
  graph.CountDegrees();
  vector<pair<int, int>> edges = graph.GetEdges();
  pair<int, int> maxEdge = make_pair(-1, -1);
  size_t maxDegree = 0;
  for (auto const& edge : edges)
  {
    size_t currentMaxDegree = graph.GetDegree(edge.first) + graph.GetDegree(edge.second);
    if (currentMaxDegree > maxDegree)
    {
      maxEdge = edge;
      maxDegree = currentMaxDegree;
    }
  }
  return maxEdge;
}
