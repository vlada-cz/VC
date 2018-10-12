#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <list>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>

class Graph
{
  public:
    Graph(){}
    bool Load(std::string graphFilePath);
    void LoadFromStream(std::ifstream &graphStream);
    std::list<std::list<std::shared_ptr<size_t>>> GetAdjacencyList() const { return adjacencyList; }
    bool HaveEdges();
    size_t GetMinDegreeVertex();
    size_t GetMaxDegreeVertex();
    std::list<std::shared_ptr<size_t>> GetAdjacents(size_t vertex);
    void RemoveVertices(std::list<std::shared_ptr<size_t>> verticesToRemove);
    void RemoveVertex(size_t vertexToRemove);
    ~Graph(){}
  private:
    std::list<std::list<std::shared_ptr<size_t>>> adjacencyList;
};

#endif
