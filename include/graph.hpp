#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

class Graph
{
  public:
    Graph(){}
    bool Load(std::string graphFilePath);
    void LoadFromStream(std::ifstream &graphStream);
    std::vector<size_t> GetVertices() const { return vertices; }
    std::vector<std::vector<size_t *>> GetAdjacents() const { return adjacents; }
    bool HaveEdges();
    size_t GetMinDegree();
    size_t GetMaxDegree();
    std::vector<size_t *> GetNeighbours(size_t vertex);
    void DeleteVertexes(std::vector<size_t *>);
    ~Graph(){}
  private:
    std::vector<size_t> vertices;
    std::vector<std::vector<size_t *>> adjacents;
};

#endif
