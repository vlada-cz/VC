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
    ~Graph(){}
  private:
    std::vector<int> vertices;
    std::vector<std::vector<int *>> adjacents;
};

#endif
