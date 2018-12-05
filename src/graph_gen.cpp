/*
 authors: Jan Kohút (xkohut08), Vladimír Jeřábek (xjerab21)
 date: 5. 12. 2018
 */

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>


using namespace std;


/*
 * Function for printing usage massage
 *
 * args:
 *      arg0: name of the running program
 */
void printUsageMsg(char* argv0) {
    string arg0 = argv0;

    cerr << "Usage: " << arg0 << " [OPTION]..." << " GRAPH_NAME"  << endl << endl;

    cerr << "Possible options:" << endl;
    cerr << "    -v NUM \tset number of vertices of the result graph otherwise is a random number" << endl;
    cerr << "    -e NUM \tset number of edges of the result graph otherwise is a random number" << endl << endl;

    cerr << "Example:" << endl;
    cerr << arg0 << " -v 25" << " -e 50" << " graph0" << endl;
}


/*
 * Function for generate realy random numbers in specific range
 *
 * args:
 *      min: the lowest generated number
 *      max: the highest generated number
 */
unsigned int RNG (unsigned int min, unsigned int max)  {
    random_device rd;

    unsigned int modulo = max - min + 1; //range of generated number
    unsigned int result = (rd() % modulo) + min;

    return  result;
}


/*
 * Function for generating edges between vertices
 *
 * args:
 *      NoE: number of edges (no more than v*(v-1)/2)
 *      NoV: number of vertices
 */
void GenerateRandGraphs(unsigned int NoE, unsigned int NoV) {
    //array of all generated edges
    unsigned int u, v, i, j, tmp;

    vector<unsigned int> edge[NoV];

    i = 0;

    //filling edge array
    while(i < NoE)
    {
        u = RNG(0, NoV-1);
        v = RNG(0, NoV-1);

        //If the vertices are the same it is not correct edge
        if(u == v)
            continue;

        //lower number is has to be in u
        if(u > v){
            tmp = u;
            u = v;
            v = tmp;
        }

        //looking for vertex v in adjacent of u
        if (find(edge[u].begin(), edge[u].end(), v) == edge[u].end()) {

            //element not found => we can add
            edge[u].push_back(v);
        } else {
            continue;
        }

        i++;
    }


    // Print the random graph.
    for(i = 0; i < NoV; i++)
    {
        for(j = 0; j < edge[i].size(); ++j) {

            tmp = edge[i][j];

            cout << tmp << " ";
            edge[tmp].push_back(i);
        }

        cout << endl;
    }
}


int main(int argc, char* argv[]) {

    string name;
    unsigned int v = RNG(2, 10000);
    unsigned int e = RNG(0, v*(v-1)/2);


    // check the params
    for (int i = 1; i < argc ; i++) {

        //check if arg is an option
        if (argv[i][0] == '-') {

            //which option
            switch (argv[i][1]) {
                case 'v':
                    v = static_cast<unsigned int> (stoul(argv[i + 1]));
                    break;

                case 'e':
                    e = static_cast<unsigned int> (stoul(argv[i + 1]));
                    break;

                default:
                    printUsageMsg(argv[0]);
                    return 1;
            }
        } else {
            //it is not option => it is graph name => save it
            name = argv[i];
        }
    }

    //if there wasn't assignment of graph name -> it is error
    if(name.empty()) {
        printUsageMsg(argv[0]);
        return 1;
    }

    // Print the graph name
    cout << name << endl;
    // Print number of vertices
    cout << v << endl;

    //checking number of edges -> no more than (v*(v-1))/2
    if(e > (v*(v-1)/2)) {
        e = RNG(0, v*(v-1)/2);
    }


	// A function to generate a random undirected graph with e edges and v vertexes.
	GenerateRandGraphs(e, v);
}
