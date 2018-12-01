#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP


#include "graph.hpp"
#include <set>
#include <algorithm>

class Algorithms
{
  public:
    Algorithms(){}
    std::vector<int> virtual Run(Graph graph, bool removePendant, bool removeRedundant){}
    virtual ~Algorithms(){}
    std::vector<int> RemovePendantVertices(Graph &graph);
    std::vector<int> RemoveRedundantVertices(Graph &graph, std::vector<int> cover);
    bool CheckCover(Graph origGraph, std::vector<int> cover);

  protected:
    bool CheckAdjacentsInCover(Graph &graph, int vertex, std::list<int> coverList);
    void RemoveVertexFromCover(std::list<int> &coverList, int vertexToRemove);
    std::vector<int> cover;

};

#endif
