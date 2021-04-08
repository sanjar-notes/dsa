#include <iostream>
#include <queue> // has vector in it
#include <unordered_map>
using namespace std;

void getPath_BFS(bool **edges, int V, int sv, int key, unordered_map<int, int> *);

int main()
{
    int V, E;
    cin >> V >> E;

    if (V == 0 || E == 0)
        return 0;

    // making an adjacency matrix of V*V
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
        cin >> a >> b;
        edges[a][b] = edges[b][a] = true; // marked as visited
    }

    int sv, key;
    cin >> sv >> key;

    // prank test
    if (sv >= V || key >= V || sv == key)
        return 0;

    unordered_map<int, int> *visited = new unordered_map<int, int>; // this is universal

    getPath_BFS(edges, V, sv, key, visited);

    if (visited->count(key) == 0) // key is absent
        return 0;

    int node = key;
    while (node != -1)
    {
        cout << node << " ";
        node = visited->at(node); // the predecessor
    }

    // deallocating the space
    for (int i = 0; i < V; i++)
        delete[] edges[i];
    delete[] edges;
    delete visited;

    return 0;
}

void getPath_BFS(bool **edges, int V, int sv, int key, unordered_map<int, int> *visited)
{
    // Do DFS
    queue<int> tbe;
    tbe.push(sv);
    (*visited)[sv] = -1; // This is sv it has no predecessor

    int curr = sv; // for reducing mem-manager work

    // check the possiblilty
    while (tbe.size() != 0)
    {
        curr = tbe.front();
        tbe.pop();

        // if it is a neighbour and has not been visited, print and put in to be explored
        for (int i = 0; visited->size() < V && i < V; i++)
        {
            if (edges[curr][i] == true && visited->count(i) == 0)
            {
                if (i == key) // found return
                {
                    (*visited)[i] = curr;
                    return;
                }
                (*visited)[i] = curr;
                tbe.push(i);
            }
        }
    }

    // Key was not found return NULL
    // return ret; // either found or just NULL
}
