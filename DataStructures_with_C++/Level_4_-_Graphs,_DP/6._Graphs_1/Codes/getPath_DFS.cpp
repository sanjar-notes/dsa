#include <iostream>
#include <vector> // has vector in it
#include <unordered_set>
using namespace std;

vector<int> *getPath_dfs(bool **edges, int V, int sv, int key, unordered_set<int> *);

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
    if (sv >= V || key >= V || sv == key) // we need sv==key also otherwise our function will return a vector with sv.
        return 0;

    unordered_set<int> *visited = new unordered_set<int>; // this is universal

    // no need for connectedness check
    vector<int> *path = getPath_dfs(edges, V, sv, key, visited);

    if (path == NULL)
        return 0;

    int n = path->size();
    for (int i = 0; i < n; i++)
        cout << path->at(i) << " ";

    // deallocating the space
    for (int i = 0; i < V; i++)
        delete[] edges[i];
    delete[] edges;
    delete visited;

    return 0;
}

// this functions returns the path including sv
vector<int> *getPath_dfs(bool **edges, int V, int sv, int key, unordered_set<int> *visited)
{
    // anchor condition
    if (sv == key) // found return
    {
        vector<int> *ret = new vector<int>;
        ret->push_back(sv);
        return ret;
    }

    // make the return path
    vector<int> *ret = NULL;

    // not putting sv as we don't know if sv is a path starter
    visited->insert(sv); // mark as visited

    // check the possiblilty
    for (int i = 0; i < V && ret == NULL && visited->size() < V; i++)
    {
        // if it is a neighbour and has not been visited, disconnected will be false always
        if (edges[sv][i] == true && visited->count(i) == 0)
        {
            visited->insert(i);
            ret = getPath_dfs(edges, V, i, key, visited);

            // include the sv
            if (ret != NULL)
            {
                ret->push_back(sv);
                return ret;
            }
        }
    }
    return ret; // either found or just NULL
}
