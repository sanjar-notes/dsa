#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void dfs(vector<int> *edges, int start, unordered_set<int> *components, bool *visited)
{
    visited[start] = true;
    components->insert(start);
    for (int i = 0; i < edges[start].size(); i++)
    {
        int next = edges[start][i];
        if (!visited[next])
            dfs(edges, next, components, visited);
    }
}

unordered_set<unordered_set<int> *> *getComponents(vector<int> *edges, int n)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;

    unordered_set<int> *ret = new unordered_set<int>;
    for (int i = 0; i < n; i++)
    {
        if (!visited)
            dfs(edges, i, ret, visited); // ret gets filled
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> *edges = new vector<int>;
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int j, k;
        cin >> j >> k;
        edges[j - 1].push_back(k - 1);
        edges[k - 1].push_back(j - 1);
    }
    cout << endl;
    return 0;
}
