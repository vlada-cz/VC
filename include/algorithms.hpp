#ifndef ALGORITHM_HPP
#define ALGORITHM_HPP

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

  protected:
    std::vector<int> RemoveRedundantVertices(Graph &graph, std::vector<int> cover);
    bool CheckAdjacentsInCover(Graph &graph, int vertex, std::list<int> coverList);
    void RemoveVertexFromCover(std::list<int> &coverList, int vertexToRemove);

};

#endif
