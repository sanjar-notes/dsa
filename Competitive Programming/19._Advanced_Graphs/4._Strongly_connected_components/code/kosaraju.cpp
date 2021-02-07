#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Kosraju's Algorithm - Get all SCCs

vector<vector<int>*> *get_scc_kosraju(int V, int **G);
void dfs1(int V, int **G, bool *visited, int current, stack<int> *st);
void dfs2(int V, int **G, bool *visited, int current, stack<int> *st, vector<vector<int>*> *scc);

int main()
{
    int V, E;
    cout << "Enter number of edges and vertices: ";
    cin >> V >> E;
    int **G = new int *[V];
    for (int i = 0; i < V; i++)
    {
        G[i] = new int[V];
        for (int j = 0; j < V; j++)
            G[i][j] = false;
    }
    cout << "Enter the edges: \n";
    int a, b;
    for (int i = 0; i < E; i++)
    {
        cin >> a >> b;
        G[a - 1][b - 1] = G[b - 1][a - 1] = true;
    }
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
            cout << G[i][j];
        cout << endl;
    }
    cout << endl;
    return 0;
}

vector<vector<int>*> *get_scc_kosraju(int V, int **G)
{
    stack<int> *st = new stack<int>;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    // for (int i = 0; i < V; i++) // intially go w.r.t vertex set
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs1(V, G, visited, i, st);
    }
    // DFS complete - stack filled

    //* Reset visited
    for (int i = 0; i < V; i++)
        visited[i] = false;

    vector<vector<int>*> *scc = new vector<vector<int>*>;
    while (st->size() != 0)
    {
    }
}

void dfs1(int V, int **G, bool *visited, int current, stack<int> *st)
{
    visited[current] = 1;
    bool all_done = false;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && G[i][current])
            dfs1(V, G, visited, i, st);
    }
    st->push(current);
}

void dfs2(int V, int **G, bool *visited, int current, stack<int> *st, vector<vector<int>*> *scc)
{
    int newNode = st->top();
    st->pop();
    if (!visited[newNode])
    {
        vector<int> newv* = new vector<int>;
        scc->push_back(newv);
    }
    bool all_done = false;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && G[i][current])
        {
            dfs2(V, G, visited, i, st, scc);
        }
    }
    st->push(current);
}
