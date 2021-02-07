#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void dijkstras_algo(vector<pair<int, int>> *table, int **G, int V);

// can do this because the algo is greedy
void print_shortest_path(int goal_vertex, vector<pair<int, int>> *table);

int main()
{
    int V, E;
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);

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

    table->at(0).second = 0; // does not matter as this is visited in one go
    // populate the table
    dijkstras_algo(table, G, V);

    // avoid the root and it's parent, inexistent
    int sum = 0;
    for (int i = 0; i < V; i++)
    {
        // print path to each
        print_shortest_path(i, table);
        cout << " Sum: " << table->at(i).second << endl;

        // if (i < table->at(i).first)
        //     cout << i << " " << table->at(i).first << " " << table->at(i).second << "\n";
        // else
        //     cout << table->at(i).first << " " << i << " " << table->at(i).second << "\n";
    }

    // dealloc
    for (int i = 0; i < V; i++)
        delete G[i];
    delete[] G;

    delete table;

    return 0;
}

void dijkstras_algo(vector<pair<int, int>> *table, int **G, int V)
{
    bool *is_visited = new bool[V];
    // initialize it
    for (int i = 0; i < V; i++)
        is_visited[i] = false;

    int next_vertex, curr_vertex = 0, min_weigh;

    for (int i = 0; i < V; i++)
    {
        // select the least weight one, the start initially

        // for the curr_vertex, explore it
        min_weigh = INT_MAX;
        for (int j = 0; j < V; j++)
        {
            // update all the unvisited neighbors
            if (G[curr_vertex][j] != 0 && is_visited[j] == false)
            {
                if (table->at(j).second > table->at(curr_vertex).second + G[curr_vertex][j])
                {
                    table->at(j).second = table->at(curr_vertex).second + G[curr_vertex][j];
                    table->at(j).first = curr_vertex; //predecessor updated
                }

                // may it won't update but can be the next one
                if (table->at(j).second < min_weigh)
                {
                    next_vertex = j;
                    min_weigh = table->at(j).second;
                }
            }
        }

        is_visited[curr_vertex] = true;
        curr_vertex = next_vertex;
    }
}

void print_shortest_path(int goal_vertex, vector<pair<int, int>> *table)
{
    // print the rest of the path
    if (goal_vertex == 0)
    {
        cout << "Start";
        return;
    }

    // print the path of the parent
    print_shortest_path(table->at(goal_vertex).first, table);
    cout << " -> " << goal_vertex;
    // print the destination
}
