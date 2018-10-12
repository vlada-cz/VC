#include "graph.hpp"

using namespace std;


void Graph::DeleteVertexes(vector<shared_ptr<size_t>>)
{
  return;
}


vector<shared_ptr<size_t>> Graph::GetNeighbours(size_t vertex)
{
  if (vertex < this->adjacents.size())
  {
    return this->adjacents[vertex];
  }
  else
  {
    cerr << "Vertex is not in the graph." << endl;
    vector<shared_ptr<size_t>> neighbours;
    return neighbours;
  }
}


size_t Graph::GetMinDegree()
{
  size_t minDegree = this->adjacents[0].size();
  for (size_t i = 1; i < this->adjacents.size(); ++i)
  {
    size_t currentMinDegree = this->adjacents[i].size();
    if (currentMinDegree < minDegree)
    {
      minDegree = currentMinDegree;
    }
  }
  return minDegree;
}


size_t Graph::GetMaxDegree()
{
  size_t maxDegree = 0;
  for (size_t i = 0; i < this->adjacents.size(); ++i)
  {
    size_t currentMaxDegree = this->adjacents[i].size();
    if (currentMaxDegree > maxDegree)
    {
      maxDegree = currentMaxDegree;
    }
  }
  return maxDegree;
}


bool Graph::HaveEdges()
{
  for (size_t i = 0; i < this->adjacents.size(); ++i)
  {
    if (not this->adjacents[i].empty())
    {
      return true;
    }
  }
  return false;
}


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
  size_t numberOfVertices;
  graphStream >> numberOfVertices;
  graphStream >> sink;
  for (size_t i = 0; i < numberOfVertices; ++i)
  {
    this->vertices.push_back(shared_ptr<size_t>(new size_t(i)));
  }
  this->adjacents = vector<vector<shared_ptr<size_t>>>(numberOfVertices);
  size_t i = 0;
  string adjacentsString;
  while (getline(graphStream, adjacentsString))
  {
    cout << i << " -> ";
    stringstream adjacentsStream(adjacentsString);
    size_t adjacent;
    while(adjacentsStream >> adjacent)
    {
      cout << adjacent << " ";
      this->adjacents[i].push_back(this->vertices[i]);
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
