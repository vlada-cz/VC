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
    std::vector<int> GetVertices() const { return vertices; }
    std::vector<std::vector<int *>> GetAdjacents() const { return adjacents; }
    ~Graph(){}
  private:
    std::vector<int> vertices;
    std::vector<std::vector<int *>> adjacents;
};

#endif
