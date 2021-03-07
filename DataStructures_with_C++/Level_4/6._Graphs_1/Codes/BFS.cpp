#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

void bfs(bool **, int, int, unordered_set<int> *);

int main()
{
    int V, E;
    cout << "Enter number of V and E: ";
    cin >> V >> E;

    if (V == 0 || E == 0)
        return 0;

    // making an adjacency matrix of V * V

    bool **edges = new bool *[V];
    for (int i = 0; i < V; i++)
    {
        edges[i] = new bool[V];
        for (int j = 0; j < V; j++)
            edges[i][j] = false;
    }

    int a, b;
    for (int i = 0; i < E; i++)
    {
        cout << "Enter edge: ";
        cin >> a >> b;
        edges[a][b] = edges[b][a] = true; // marked as visited
    }

    // starting from the node

    unordered_set<int> *visited = new unordered_set<int>; // this is universal
    visited->clear();
    // for disconnected graph

    // we call bfs for each unvisited edge.
    // the completed ones will be ignored due to universal visited

    // looping to handle disconnectedness
    for (int i = 0; i < V && visited->size() < V; i++)
    {
        // call bfs for nodes which are not visited
        if (visited->count(i) == 0)
        {
            bfs(edges, V, i, visited);

            // we used a for loop because this ensures all vertices are passed through,
            // even disconnected ones.
            cout << "Graph ends here\n";
        }
    }

    // deallocating the space
    for (int i = 0; i < V; i++)
        delete[] edges[i];
    delete[] edges;
    delete visited;

    return 0;
}

void bfs(bool **edges, int V, int sv, unordered_set<int> *visited)
{
    // make the queue and the visited list
    queue<int> tbe; // TO BE EXPLORED

    // sv has special treatment, as it is the our unvisited neighbour in the graph :)

    visited->insert(sv); // mark as visited-> We do this outside
    tbe.push(sv);        // the start, if tbv is zero we stop.
    cout << sv << " ";   // we print this ourselves, as it is the users unvisited neighbour :)

    int curr = 0;           // this is done so that OS does not need frequent memory alloc lookups
    while (tbe.size() != 0) // tbe.size() is 1 initially
    {
        curr = tbe.front();
        tbe.pop();

        // check the possiblilty
        for (int i = 0; i < V && visited->size() < V; i++)
        {
            // if it is a neighbour and has not been visited, disconnected will be false always
            if (edges[curr][i] == true && visited->count(i) == 0)
            {
                // print the neighbour
                cout << i << " ";

                // put in to be explored and visited->
                tbe.push(i);
                visited->insert(i);
            }
        }
        // printed all the neighbours
    }
    // All vertices printed
}
