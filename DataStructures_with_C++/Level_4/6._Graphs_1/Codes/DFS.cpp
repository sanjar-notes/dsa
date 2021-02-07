#include <iostream>
#include <unordered_set>
using namespace std;

void dfs(bool **edges, int V, int sv, unordered_set<int> *visited);

int main()
{
    int V;
    int E;
    cout << "Enter number of V and E: ";
    cin >> V >> E;

    bool **edges = new bool *[V]; //n *n array
    for (int i = 0; i < V; i++)
    {
        edges[i] = new bool[V];
        for (int j = 0; j < V; j++)
            edges[i][j] = false;
    }

    int x, y;
    for (int i = 0; i < E; i++)
    {
        cout << "Enter edge: ";
        cin >> x >> y;
        edges[x][y] = true; // 0 to n-1
        edges[y][x] = true;
    }

    unordered_set<int> *visited = new unordered_set<int>; // we should use if self loop is allowed or for a multigraph

    // looping to handle disconnectedness
    // vertex 0 0 is unvisited
    for (int i = 0; visited->size() < V && i < V; i++)
    {
        // call DFS for nodes which are not yet visited
        if (visited->count(i) == 0)
        {
            dfs(edges, V, i, visited);
            cout << "Graph ends here\n";
        }
    }

    // free the memory
    for (int i = 0; i < V; i++)
        delete[] edges[i];
    delete[] edges;

    delete visited;
    cout << endl;
    return 0;
}

void dfs(bool **edges, int V, int sv, unordered_set<int> *visited)
{
    // sv is unvisited print it - for the root node
    cout << sv << " ";
    visited->insert(sv); // added to the visited set

    // check the neighbours, print all the unvisited ones
    for (int i = 0; visited->size() < V && i < V; i++)
    {
        // if the node at hand is a neighbour and that it is unvisited
        if (i != sv && edges[sv][i] == true && visited->count(i) == 0) // self case is also handled here, loops not allowed
            dfs(edges, V, i, visited);
        // works for disjoints also
    }
    // all connected componenets of sv visited here
}

// Proof of correctness -  using PMI
/*
    We assume that DFS prints the whole graph.

    DFS works for n==1.

    DFS now is at a node and prints all the neighbours and traverses the graph starting from it.

    If the whole graph were accessible from it, It's already printed.
    else if some parts were missing.
    They'll be printed by neighbours of the predecessors for sure. Coz they are reachable by somebody. And we traverse everybody.
*/
