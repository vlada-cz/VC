#include "graph.hpp"

using namespace std;


void Graph::DeleteVertices(list<shared_ptr<size_t>>)
{
  return;
}


list<shared_ptr<size_t>> Graph::GetAdjacents(size_t vertex)
{
  for (auto const& adjacents : adjacencyList)
  {
    if (*adjacents.front() == vertex)
    {
      return adjacents;
    }
  }
  cerr << "Vertex is not in the graph." << endl;
  list<shared_ptr<size_t>> adjacents;
  return adjacents;
}


size_t Graph::GetMinDegreeVertex()
{
  size_t vertex;
  size_t minDegree;
  bool firstIteration = true;
  for (auto const& adjacents : adjacencyList)
  {
    if (firstIteration)
    {
      firstIteration = false;
      vertex = *adjacents.front();
      minDegree = adjacents.size() - 1;
    }
    else
    {
      size_t currentMinDegree = adjacents.size() - 1;
      if (currentMinDegree < minDegree)
      {
        vertex = *adjacents.front();
        minDegree = currentMinDegree;
      }
    }
  }
  return vertex;
}


size_t Graph::GetMaxDegreeVertex()
{
  size_t vertex = 0;
  size_t maxDegree = 0;
  for (auto const& adjacents : adjacencyList)
  {
    size_t currentMaxDegree = adjacents.size() - 1;
    if (currentMaxDegree > maxDegree)
    {
      vertex = *adjacents.front();
      maxDegree = currentMaxDegree;
    }
  }
  return vertex;
}


//If any adjacents is bigger than 2 than the graph have at least one edge
//list.size() take O(n) so this should be faster
bool Graph::HaveEdges()
{
  for (auto const& adjacents : adjacencyList)
  {
    size_t i = 0;
    for (auto const& vertex : adjacents)
    {
      ++i;
      if (i > 1)
      {
        return true;
      }
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
  vector<shared_ptr<size_t>> vertices;
  for (size_t i = 0; i < numberOfVertices; ++i)
  {
    vertices.push_back(shared_ptr<size_t>(new size_t(i)));
  }
  size_t i = 0;
  string adjacentsString;
  while (getline(graphStream, adjacentsString))
  {
    cout << i << " -> ";
    stringstream adjacentsStream(adjacentsString);
    size_t adjacent;
    this->adjacencyList.push_back(list<shared_ptr<size_t>>());
    this->adjacencyList.back().push_back(vertices[i]);
    while(adjacentsStream >> adjacent)
    {
      cout << adjacent << " ";
      this->adjacencyList.back().push_back(vertices[i]);
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
