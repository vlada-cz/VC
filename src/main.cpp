#include <iostream>
#include <getopt.h>
#include <string>

#include "graph.hpp"
#include "algorithms/dummy.hpp"
#include "algorithms/GIC.hpp"
#include "experiments/time.hpp"
#include "experiments/space.hpp"
#include "experiments/cover_size.hpp"

using namespace std;

int main(int argc, char **argv)
{
  static struct option long_options[] = {
  {"graph", required_argument, 0, 'g'},
  {"param2", required_argument, 0, 'd'},
  {0, 0, 0, 0}};

  string graphFilePath;
  string param2;

  cout << endl;
  cout << "Params" << endl;
  cout << "#############################################################" << endl;
  int option_index = 0;
  int opt = 0;
  while ((opt = getopt_long(argc, argv, "g:d:", long_options, &option_index)) != -1)
  {
    switch (opt)
    {
      case 'g':
        graphFilePath = optarg;
        cout << "Graph file path: " << optarg << endl;
        break;

      case 'd':
        param2 = optarg;
        cout << "Param 2: " << optarg << endl;
        break;

      default:
        break;
    }
  }
  cout << "#############################################################" << endl;
  cout << endl;
  cout << endl;

  Graph graph;
  graph.Load(graphFilePath);

  Graph graph2 = graph;

  int maxDegreeVertex = graph.GetMinDegreeVertex();
  cout << maxDegreeVertex << endl;

  list<int> adjacents = graph.GetAdjacents(maxDegreeVertex);
  for (auto const& vertex : adjacents)
  {
    cout << vertex << " ";
  }
  cout << endl;

  graph.RemoveVertices(adjacents);

  graph.Print();
  graph2.Print();

  cout << endl;
  cout << endl;

  Dummy dummy;
  GIC gic;

  Time timeExperiment;
  CoverSize coverSizeExperiment;

  cout << "Dummy" << endl;
  timeExperiment.Run(100, dummy, graph);
  coverSizeExperiment.Run(100, dummy, graph);
  cout << endl;

  cout << "GCI" << endl;
  timeExperiment.Run(100, gic, graph);
  coverSizeExperiment.Run(100, gic, graph);
  cout << endl;

  /*
  if (param1.empty() || param2.empty())
  {
    cout << "Params have to be set." << endl;
    return -1;
  }
  */

  return 0;
}
