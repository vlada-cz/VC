#include "algorithms/dummy.hpp"

using namespace std;

vector<size_t> Dummy::Run(Graph graph)
{
  return graph.GetVertices();
}
