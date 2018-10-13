#include "graph.hpp"

using namespace std;


void Graph::RemoveVertices(list<int> verticesToRemove)
{
  for (auto const& vertex : verticesToRemove)
  {
    this->RemoveVertex(vertex);
  }
  return;
}


void Graph::RemoveVertex(int vertexToRemove)
{
  list<list<int>>::iterator adjacentsIterator = this->adjacencyList.begin();
  while(adjacentsIterator != this->adjacencyList.end())
  {
    if (adjacentsIterator->front() == vertexToRemove)
    {
      this->adjacencyList.erase(adjacentsIterator++);
    }
    else
    {
      list<int>::iterator vertexIterator = adjacentsIterator->begin();
      while (vertexIterator != adjacentsIterator->end())
      {
        if (*vertexIterator == vertexToRemove)
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


list<int> Graph::GetAdjacents(int vertex)
{
  for (auto const& adjacents : this->adjacencyList)
  {
    if (adjacents.front() == vertex)
    {
      return adjacents;
    }
  }
  cerr << "Vertex is not in the graph." << endl;
  list<int> adjacents;
  return adjacents;
}


int Graph::GetNonZeroMinDegreeVertex()
{
  int vertex = -1;
  size_t minDegree;
  bool firstNotSet = true;
  for (auto const& adjacents : this->adjacencyList)
  {
    size_t currentMinDegree = adjacents.size() - 1;
    if (currentMinDegree > 0)
    {
      if (firstNotSet)
      {
        firstNotSet = false;
        vertex = adjacents.front();
        minDegree = currentMinDegree;
      }
      else
      {
        if (currentMinDegree < minDegree)
        {
          vertex = adjacents.front();
          minDegree = currentMinDegree;
        }
      }
    }
  }
  return vertex;
}


int Graph::GetNonZeroMaxDegreeVertex()
{
  pair<int, int> result = this->GetMaxDegreeVertexImpl();
  if (result.second > 0)
  {
    return result.first;
  }
  else
  {
    return -1;
  }
}


int Graph::GetMinDegreeVertex()
{
  int vertex = -1;
  size_t minDegree;
  bool firstIteration = true;
  for (auto const& adjacents : this->adjacencyList)
  {
    if (firstIteration)
    {
      firstIteration = false;
      vertex = adjacents.front();
      minDegree = adjacents.size() - 1;
    }
    else
    {
      size_t currentMinDegree = adjacents.size() - 1;
      if (currentMinDegree < minDegree)
      {
        vertex = adjacents.front();
        minDegree = currentMinDegree;
      }
    }
  }
  return vertex;
}


int Graph::GetMaxDegreeVertex()
{
  pair<int, int> result = this->GetMaxDegreeVertexImpl();
  return result.first;
}

pair<int, int> Graph::GetMaxDegreeVertexImpl()
{
  int vertex = -1;
  size_t maxDegree = 0;
  for (auto const& adjacents : this->adjacencyList)
  {
    size_t currentMaxDegree = adjacents.size() - 1;
    if (currentMaxDegree > maxDegree)
    {
      vertex = adjacents.front();
      maxDegree = currentMaxDegree;
    }
  }
  return make_pair(vertex, maxDegree);
}


//If any adjacents is bigger than 2 than the graph have at least one edge
//list.size() take O(n) so this should be faster
bool Graph::HaveEdges()
{
  for (auto const& adjacents : this->adjacencyList)
  {
    int i = 0;
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
      cout << vertex << " ";
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
  int numberOfVertices;
  graphStream >> numberOfVertices;
  getline(graphStream, sink);
  int i = 0;
  string adjacentsString;
  while (getline(graphStream, adjacentsString))
  {
    cout << i << " -> ";
    stringstream adjacentsStream(adjacentsString);
    int adjacent;
    this->adjacencyList.push_back(list<int>());
    this->adjacencyList.back().push_back(i);
    while(adjacentsStream >> adjacent)
    {
      cout << adjacent << " ";
      this->adjacencyList.back().push_back(adjacent);
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
