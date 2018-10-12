#include "algorithms/dummy.hpp"

using namespace std;

vector<shared_ptr<size_t>> Dummy::Run(Graph graph)
{
  return graph.GetVertices();
}
