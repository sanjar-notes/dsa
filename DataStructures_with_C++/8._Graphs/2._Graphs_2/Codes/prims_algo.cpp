#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void prims_algo(vector<pair<int, int>> *table, int **G, int V);

int main()
{
    int V, E;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    cin >> V >> E;

    if (E > V * (V + 1) / 2)
        return 0;

    // we need an matrix now
    int **G = new int *[V];
    for (int i = 0; i < V; i++)
    {
        G[i] = new int[V];
        for (int j = 0; j < V; j++)
            G[i][j] = 0; // to keep the weight
    }

    int source, destination, weight;
    for (int i = 0; i < E; i++)
    {
        cin >> source >> destination >> weight;
        G[destination][source] = G[source][destination] = weight;
    }

    // for (int i = 0; i < V; i++)
    // {
    //     for (int j = 0; j < V; j++)
    //         cin >> G[i][j];
    // }

    // make the table
    vector<pair<int, int>> *table = new vector<pair<int, int>>(V);
    for (int i = 0; i < V; i++)
        table->at(i).first = -1, table->at(i).second = INT_MAX;

    table->at(0).second = 67; // does not matter as this is visited in one go
    // populate the table
    prims_algo(table, G, V);

    // print the MST table
    int start, end;

    // avoid the root and it's parent, doesn't have a parent
    for (int i = 1; i < V; i++)
    {
        if (i < table->at(i).first)
            cout << i << " " << table->at(i).first << " " << table->at(i).second << "\n";
        else
            cout << table->at(i).first << " " << i << " " << table->at(i).second << "\n";
    }

    // dealloc
    for (int i = 0; i < V; i++)
        delete G[i];
    delete[] G;

    delete table;

    return 0;
}

void prims_algo(vector<pair<int, int>> *table, int **G, int V)
{
    bool *is_visited = new bool[V];
    // initialize it
    for (int i = 0; i < V; i++)
        is_visited[i] = false;

    int minweight, curr_vertex = 0, next_vertex; // start ith 0

    // traverse each vertex once
    for (int i = 0; i < V; i++)
    {
        // keep minimum weight 0(self) - keeping it infinity in order to start determine vertex

        minweight = INT_MAX;
        for (int i = 0; i < V; i++)
        {
            if (table->at(i).second < minweight && is_visited[i] == false)
                curr_vertex = i;
        }

        // traverse it's neighbours
        for (int j = 0; j < V; j++)
        {
            // we find next_vertex implicitly - it is among the unvisited

            // for a an unvisited neighbours
            if (G[curr_vertex][j] != 0 && is_visited[j] == false)
            {
                // update if distance at present is greater.
                if (G[curr_vertex][j] < table->at(j).second)
                {
                    // update the parent and the weight
                    table->at(j).first = curr_vertex; // parent
                    table->at(j).second = G[curr_vertex][j];

                }
            }
        }

        // mark as visited
        is_visited[curr_vertex] = true;
        curr_vertex = next_vertex;
    }
    delete is_visited;
}
