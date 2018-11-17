#include "algorithms.hpp"

using namespace std;

/*
 * Find edges that have at least one vertex connected only to them
 * Remove the opposite vertices and return them
 * These vertices have to be in the minimal vertex cover
 */
vector<int> Algorithms::RemovePendantVertices(Graph &graph)
{
  set<int> cover_set;
  list<list<int>> adjacencyList = graph.GetAdjacencyList();
  for (auto const& adjacents : adjacencyList)
  {
    //Get vertices with single endge faster
    int counter = 0;
    int opposite_vertex;
    for (auto const& vertex : adjacents)
    {
      ++counter;
      if (counter == 3)
      {
        break;
      }
      else
      {
        opposite_vertex = vertex;
      }
    }
    if (counter == 2)
    {
      cover_set.insert(opposite_vertex);
    }
  }
  vector<int> cover;
  list<int> verticesToRemove;
  for (auto const& vertex : cover_set)
  {
    cover.push_back(vertex);
    verticesToRemove.push_back(vertex);
  }
  graph.RemoveVertices(verticesToRemove);
  return cover;
}

/*
 * Remove vertices from vertex cover that have all neighbours in the vertex cover
 * Incrementally from the smallest number of neighbours
 */
vector<int> Algorithms::RemoveRedundantVertices(Graph &graph, vector<int> cover)
{
  list<int> coverList;
  for (auto const& vertex : cover)
  {
    coverList.push_back(vertex);
  }
  graph.CountDegrees();
  while (true)
  {
    vector<pair<int, size_t>> redundantVertices;
    for (auto const& vertex : coverList)
    {
      if (this->CheckAdjacentsInCover(graph, vertex, coverList))
      {
        redundantVertices.push_back(make_pair(vertex, graph.GetDegree(vertex)));
      }
    }
    if (redundantVertices.size() == 0)
    {
      break;
    }
    pair<int, size_t> minRedundantVertex = redundantVertices[0];
    for (auto const& vertex : redundantVertices)
    {
      size_t currentMinDegree = vertex.second;
      if (currentMinDegree < minRedundantVertex.second)
      {
        minRedundantVertex = vertex;
      }
    }
    this->RemoveVertexFromCover(coverList, minRedundantVertex.first);
  }
  vector<int> reducedVertexCover;
  for (auto const& vertex : coverList)
  {
    reducedVertexCover.push_back(vertex);
  }
  return reducedVertexCover;
}


bool Algorithms::CheckAdjacentsInCover(Graph &graph, int vertex, list<int> coverList)
{
  list<int> adjacents = graph.GetAdjacents(vertex);
  bool adjacentsInCover = true;
  for (auto const& adjacent : adjacents)
  {
    if (not (find(begin(coverList), end(coverList), adjacent) != end(coverList)))
    {
      adjacentsInCover = false;
      break;
    }
  }
  return adjacentsInCover;
}


void Algorithms::RemoveVertexFromCover(list<int> &coverList, int vertexToRemove)
{
  list<int>::iterator coverIterator = coverList.begin();
  while (coverIterator != coverList.end())
  {
    if (*coverIterator == vertexToRemove)
    {
      coverList.erase(coverIterator++);
    }
    else
    {
      ++coverIterator;
    }
  }
}
