#include "graph.hpp"

using namespace std;

bool Graph::Load(string graphFilePath)
{
  cout << "Loading graph..." << endl;
  cout << "File path: " << graphFilePath << endl;
  ifstream graphStream(graphFilePath);
  if (graphStream.is_open())
  {
    this->LoadFromStream(graphStream);
    return true;
  }
  else
  {
    cerr << "Unable to open graph file." << endl;
    return false;
  }
}

void Graph::LoadFromStream(ifstream &graphStream)
{
  string sink;
  cout << endl;
  string graphName;
  graphStream >> graphName;
  cout << "Graph: " << graphName << endl;
  cout << "#############################################################" << endl;
  int numberOfVertices;
  graphStream >> numberOfVertices;
  graphStream >> sink;
  for (int i = 0; i < numberOfVertices; ++i)
  {
    this->vertices.push_back(i);
  }
  this->adjacents = vector<vector<int *>>(numberOfVertices);
  int i = 0;
  string adjacentsString;
  while (getline(graphStream, adjacentsString))
  {
    cout << i << " -> ";
    stringstream adjacentsStream(adjacentsString);
    int adjacent;
    while(adjacentsStream >> adjacent)
    {
      cout << adjacent << " ";
      this->adjacents[i].push_back(&this->vertices[i]);
    }
    cout << endl;
    ++i;
  }
  graphStream.close();
  cout << "#############################################################" << endl;
  cout << endl;
  cout << endl;
  return;
}
