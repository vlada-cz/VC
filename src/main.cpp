#include <iostream>
#include <getopt.h>
#include <string>

#include "graph.hpp"
#include "algorithms.hpp"
#include "algorithms/dummy.hpp"
#include "algorithms/GIC.hpp"
#include "algorithms/MDG.hpp"
#include "algorithms/ME.hpp"
#include "experiments/time_size.hpp"

using namespace std;

int main(int argc, char **argv)
{
  static struct option long_options[] = {
  {"graph", required_argument, 0, 'g'},
  {"method", required_argument, 0, 'm'},
  {"iter", required_argument, 0, 'i'},
  {"pendant", no_argument, 0, 'p'},
  {"redundant", no_argument, 0, 'r'},
  {0, 0, 0, 0}};

  string graphFilePath;
  string outFileName;
  string method;
  int numberOfInterations = 1;
  bool removePendant = false;
  bool removeRedundant = false;

  cout << endl;
  cout << "Params" << endl;
  cout << "#############################################################" << endl;
  int option_index = 0;
  int opt = 0;
  while ((opt = getopt_long(argc, argv, "g:m:i:pr", long_options, &option_index)) != -1)
  {
    switch (opt)
    {
      case 'g':
        graphFilePath = optarg;
        outFileName = graphFilePath + ".out";
        cout << "Graph file path: " << optarg << endl;
        break;

      case 'm':
        method = optarg;
        cout << "Method: " << optarg << endl;
        break;

      case 'i':
        numberOfInterations = stoi(optarg);
        cout << "Number of iterations: " << optarg << endl;
        break;

      case 'p':
        removePendant = true;
        cout << "RemovePendantVertices set" << endl;
        break;

      case 'r':
        removeRedundant = true;
        cout << "RemoveRedundantVertices set" << endl;
        break;

      default:
        break;
    }
  }
  cout << "#############################################################" << endl;
  //cout << endl;
  //cout << endl;

  //Load graph and remember the original
  Graph graph;
  graph.Load(graphFilePath);
  Graph origGraph = graph;

  TimeSize timeSizeExperiment;

  pair<double, int> result;

  if (!method.compare("GIC"))
  {
    GIC gic;
    result = timeSizeExperiment.Run(numberOfInterations, gic, graph, removePendant, removeRedundant);
  }

  if (!method.compare("MDG"))
  {
    MDG mdg;
    result = timeSizeExperiment.Run(numberOfInterations, mdg, graph, removePendant, removeRedundant);
  }

  if (!method.compare("ME"))
  {
    ME me;
    result = timeSizeExperiment.Run(numberOfInterations, me, graph, removePendant, removeRedundant);
  }

  if (!method.compare("DUMMY"))
  {
    Dummy dummy;
    result = timeSizeExperiment.Run(numberOfInterations, dummy, graph, removePendant, removeRedundant);
  }

  ofstream outStream(outFileName);
  outStream << result.first << " " << result.second;
  outStream.close();

  return 0;
}
