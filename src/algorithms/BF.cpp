/*
 authors: Jan Kohút (xkohut08), Vladimír Jeřábek (xjerab21)
 date: 5. 12. 2018
 */

#include "algorithms/BF.hpp"

using namespace std;

vector<int> BF::Run(Graph graph, bool removePendant, bool removeRedundant)
{
  this->cover.clear();
  list<list<int>> adjacencyList = graph.GetAdjacencyList();
  int numberOfVertices = (int) adjacencyList.size();
  for (int i = 1; i <= numberOfVertices; ++i)
  {
    vector<vector<int>> combinations = this->GetCombinations(numberOfVertices, i);
    for (auto const& cover : combinations)
    {
      if (this->CheckCover(graph, cover))
      {
        this->cover = cover;
        return this->cover;
      }
    }
  }
  return this->cover;
}

/*
mitchnull, http://mitchnull.blogspot.com
https://stackoverflow.com/questions/9430568/generating-combinations-in-c
*/
vector<vector<int>> BF::GetCombinations(int n, int r)
{
  vector<vector<int>> combinations;
  vector<bool> v(n);
  std::fill(v.begin(), v.begin() + r, true);
  do
  {
    vector<int> combination;
    for (int i = 0; i < n; ++i) {
      if (v[i])
      {
        combination.push_back(i);
      }
    }
    if (!(combination.empty()))
    {
      combinations.push_back(combination);
    }
  } while (std::prev_permutation(v.begin(), v.end()));
  return combinations;
}
