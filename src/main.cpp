#include <iostream>
#include <getopt.h>
#include <string>

#include "graph.hpp"
#include "algorithms.hpp"
#include "algorithms/dummy.hpp"
#include "algorithms/GIC.hpp"
#include "algorithms/ME.hpp"
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
  graph.CountDegrees();
  int maxDegreeVertex = graph.GetMaxDegreeVertex();
  cout << "MAX:" << graph.GetDegree(maxDegreeVertex) << endl;
  int minDegreeVertex = graph.GetNonZeroMinDegreeVertex();
  cout << "MIN:" << minDegreeVertex << endl;

  vector<pair<int, int>> edges = graph.GetEdges();
  for (auto const& edge : edges)
  {
    cout << "(" << edge.first << ", " << edge.second << ")" << endl;
  }

  cout << endl;


  Dummy dummy;
  GIC gic;
  ME me;
  vector<int> cover = me.RemovePendantVertices(graph);
  for (auto const& vertex : cover)
  {
    cout << vertex << " ";
  }
  cout <<  endl;
  graph.Print();

  /*

  Time timeExperiment;
  CoverSize coverSizeExperiment;

  cout << "Dummy" << endl;
  timeExperiment.Run(100, dummy, graph, false, false);
  coverSizeExperiment.Run(100, dummy, graph, false, false);
  cout << endl;

  cout << "GCI" << endl;
  timeExperiment.Run(100, gic, graph, false, false);
  coverSizeExperiment.Run(100, gic, graph, false, false);
  cout << endl;

  cout << "ME" << endl;
  //timeExperiment.Run(1, me, graph);
  coverSizeExperiment.Run(1, me, graph, false, false);
  cout << endl;

  */
  /*
  if (param1.empty() || param2.empty())
  {
    cout << "Params have to be set." << endl;
    return -1;
  }
  */

  return 0;
}
