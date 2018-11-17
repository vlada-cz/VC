#include "experiments.hpp"

using namespace std;

/*
 * Check if the vertex cover is valid cover
 * After removing vertices from vertex cover the graph should have no edges
 */
bool Experiments::CheckCover(Graph origGraph, vector<int> cover)
{
  list<int> checkCover;
  for (auto const& vertex : cover)
  {
    checkCover.push_back(vertex);
  }
  origGraph.RemoveVertices(checkCover);
  return !origGraph.HaveEdges();
}
