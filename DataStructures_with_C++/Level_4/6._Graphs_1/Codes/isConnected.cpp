#include <iostream>
#include <unordered_set>
using namespace std;

void dfs(bool **edges, int V, int sv, unordered_set<int> *visited);

int main()
{
    int V, E;
    cin >> V >> E;

    if (V == 0 || E == 0)
        return 0;

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
        edges[a][b] = edges[b][a] = true;
    }

    unordered_set<int> *visited = new unordered_set<int>;

    // start from any vertex, we do from 0

    dfs(edges, V, 0, visited);

    if (visited->size() == V)
        cout << "true";
    else
        cout << "false";

    for (int i = 0; i < V; i++)
        delete[] edges[i];
    delete edges;

    delete visited;
    return 0;
}

void dfs(bool **edges, int V, int sv, unordered_set<int> *visited)
{
    visited->insert(sv);
    // visited

    for (int i = 0; i < V && visited->size() < V; i++)
    {
        // select an unvisited neighbouring edge
        if (edges[sv][i] == true && visited->count(i) == 0)
            dfs(edges, V, i, visited);
    }
}
