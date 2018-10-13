#include "graph.hpp"

using namespace std;


void Graph::RemoveVertices(list<shared_ptr<size_t>> verticesToRemove)
{
  for (auto const& vertex : verticesToRemove)
  {
    this->RemoveVertex(*vertex);
  }
  return;
}


void Graph::RemoveVertex(size_t vertexToRemove)
{
  list<list<shared_ptr<size_t>>>::iterator adjacentsIterator = this->adjacencyList.begin();
  while(adjacentsIterator != this->adjacencyList.end())
  {
    if (*(adjacentsIterator->front()) == vertexToRemove)
    {
      this->adjacencyList.erase(adjacentsIterator++);
    }
    else
    {
      list<shared_ptr<size_t>>::iterator vertexIterator = adjacentsIterator->begin();
      while (vertexIterator != adjacentsIterator->end())
      {
        if (**vertexIterator == vertexToRemove)
        {
          adjacentsIterator->erase(vertexIterator++);
        }
        else
        {
          ++vertexIterator;
        }
      }
      ++adjacentsIterator;
    }
  }
  return;
}


list<shared_ptr<size_t>> Graph::GetAdjacents(size_t vertex)
{
  for (auto const& adjacents : this->adjacencyList)
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
  for (auto const& adjacents : this->adjacencyList)
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
  for (auto const& adjacents : this->adjacencyList)
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
  for (auto const& adjacents : this->adjacencyList)
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


void Graph::Print()
{
  cout << "Graph: " << this->name << endl;
  cout << "#############################################################" << endl;
  for (auto const& adjacents : this->adjacencyList)
  {
    bool firstIteration = true;
    for (auto const& vertex : adjacents)
    {
      cout << *vertex << " ";
      if (firstIteration)
      {
        firstIteration = false;
        cout << "-> ";
      }
    }
    cout << endl;
  }
  cout << "#############################################################" << endl;
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
  this->name = graphName;
  cout << "Graph: " << graphName << endl;
  cout << "#############################################################" << endl;
  size_t numberOfVertices;
  graphStream >> numberOfVertices;
  getline(graphStream, sink);
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
      this->adjacencyList.back().push_back(vertices[adjacent]);
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
