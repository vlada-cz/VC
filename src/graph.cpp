/*
 authors: Jan Kohút (xkohut08), Vladimír Jeřábek (xjerab21)
 date: 5. 12. 2018
 */

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
  bool vertexFound = false;
  list<list<int>>::iterator adjacentsIterator = this->adjacencyList.begin();
  while(adjacentsIterator != this->adjacencyList.end())
  {
    if (adjacentsIterator->front() == vertexToRemove)
    {
      vertexFound = true;
      this->adjacencyList.erase(adjacentsIterator++);
    }
    else
    {
      list<int>::iterator vertexIterator = adjacentsIterator->begin();
      while (vertexIterator != adjacentsIterator->end())
      {
        if (*vertexIterator == vertexToRemove)
        {
          vertexFound = true;
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
  if (!vertexFound)
  {
    cerr << "Vertex to remove " << vertexToRemove << " was not found." << endl;
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
  cerr << "Adjacents for vertex " << vertex << " are not in the graph." << endl;
  list<int> adjacents;
  return adjacents;
}


vector<pair<int, int>> Graph::GetEdges()
{
  vector<pair<int, int>> edges;
  for (auto const& adjacents : this->adjacencyList)
  {
    int first_vertex = adjacents.front();
    list<int>::const_iterator vertexIterator = adjacents.begin();
    ++vertexIterator;
    while (vertexIterator != adjacents.end())
    {
      if (*vertexIterator >= first_vertex)
      {
        edges.push_back(make_pair(first_vertex, *vertexIterator));
      }
      ++vertexIterator;
    }
  }
  return edges;
}


void Graph::CountDegrees()
{
  this->degrees.clear();
  for (auto const& adjacents : this->adjacencyList)
  {
    this->degrees[adjacents.front()] = adjacents.size() - 1;
  }
}


size_t Graph::GetDegree(int vertex)
{
  map<int, size_t>::iterator vertexIterator = this->degrees.find(vertex);
  if(vertexIterator != this->degrees.end())
  {
    return vertexIterator->second;
  }
  else
  {
    cerr << "Degree for vertex" << vertex << " doesnt exist." << endl;
    return -1;
  }
}


int Graph::GetNonZeroMinDegreeVertex()
{
  int vertex = -1;
  size_t minDegree;
  bool firstNotSet = true;
  for (const auto& vertexDegree : this->degrees)
  {
    size_t currentMinDegree = vertexDegree.second;
    if (currentMinDegree > 0)
    {
      if (firstNotSet)
      {
        firstNotSet = false;
        vertex = vertexDegree.first;
        minDegree = currentMinDegree;
      }
      else
      {
        if (currentMinDegree < minDegree)
        {
          vertex = vertexDegree.first;
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
  for (auto const& vertexDegree : this->degrees)
  {
    size_t currentMinDegree = vertexDegree.second;
    if (firstIteration)
    {
      firstIteration = false;
      vertex = vertexDegree.first;
      minDegree = currentMinDegree;
    }
    else
    {
      if (currentMinDegree < minDegree)
      {
        vertex = vertexDegree.first;
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
  for (auto const& vertexDegree : this->degrees)
  {
    size_t currentMaxDegree = vertexDegree.second;
    if (currentMaxDegree > maxDegree)
    {
      vertex = vertexDegree.first;
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
  //cout << "Loading graph..." << endl;
  //cout << "File path: " << graphFilePath << endl;
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
  //cout << endl;
  string graphName;
  graphStream >> graphName;
  this->name = graphName;
  //cout << "Graph: " << graphName << endl;
  //cout << "#############################################################" << endl;
  int numberOfVertices;
  graphStream >> numberOfVertices;
  getline(graphStream, sink);
  int i = 0;
  string adjacentsString;
  while (getline(graphStream, adjacentsString))
  {
    //cout << i << " -> ";
    stringstream adjacentsStream(adjacentsString);
    int adjacent;
    this->adjacencyList.push_back(list<int>());
    this->adjacencyList.back().push_back(i);
    while(adjacentsStream >> adjacent)
    {
      //cout << adjacent << " ";
      this->adjacencyList.back().push_back(adjacent);
    }
    //cout << endl;
    ++i;
  }
  graphStream.close();
  //cout << "#############################################################" << endl;
  //cout << endl;
  //cout << endl;
  return;
}
