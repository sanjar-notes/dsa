#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool safeConnect(pair<pair<int, int>, int> edge, vector<int> *parent, vector<pair<pair<int, int>, int>> *G, int &sum)
{
    int a = edge.first.first, b = edge.first.second;

    int sup_a = parent->at(a), sup_b = parent->at(b);

    // find the superparent of a
    while (parent->at(sup_a) != sup_a)
        sup_a = parent->at(sup_a);
    // same for b
    while (parent->at(sup_b) != sup_b)
        sup_b = parent->at(sup_b);

    // if this is true, we have two disconnected graphs, connect them
    if (sup_a != sup_b)
    {
        parent->at(sup_a) = sup_b;
        sum += edge.second;
        return true;
    }
    return false;
}

int main()
{
    int V, E;
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    // cout << "Number of vertices: ";
    cin >>
        V; // number of vertices

    // cout << "Number of edges: ";
    cin >> E;

    if (E > V * (V - 1) / 2)
    {
        // cout << "Invalid Graph\n";
        return 0;
    }

    // make an adjacency list, size = edges
    vector<pair<pair<int, int>, int>> *G = new vector<pair<pair<int, int>, int>>(E);

    int source, destination, weight;
    for (int i = 0; i < E; i++)
    {
        cin >> source >> destination >> weight;

        while (source > V || destination > V || source < 0 || destination < 0)
        {
            // cout << "Invalid input, please enter again ...\n";
            cin >> source >> destination >> weight;
        }

        if (source > destination)
        {
            int temp = source;
            source = destination;
            destination = temp;
        }
        G->at(i).first.first = source;
        G->at(i).first.second = destination;
        G->at(i).second = weight;
    }

    // sort the edges w.r.t weight
    sort(G->begin(), G->end(), [](const pair<pair<int, int>, int> &x, const pair<pair<int, int>, int> &y) { return x.second < y.second; });

    // make the parent vector -  for union find
    vector<int> *parent = new vector<int>(V);
    for (int i = 0; i < V; i++)
        parent->at(i) = i;

    int e = 0, wsum = 0;

    // store the MST
    vector<pair<pair<int, int>, int>> *MST = new vector<pair<pair<int, int>, int>>(V - 1);

    int i = 0;
    for (i = 0; i < E && e != V - 1; i++) // stop at e = V-1
    {
        // check if the edge can be connected
        if (safeConnect(G->at(i), parent, G, wsum))
        {
            MST->at(e) = G->at(i);
            e++;
        }
    }
    // cout << "Steps required: " << i;
    // cout << "\nMST Sum: " << wsum << endl;

    for (auto edge : *MST)
        cout << edge.first.first << " " << edge.first.second << " " << edge.second << "\n";

    delete G, parent, MST;
    return 0;
}

/*
1 3 1
0 1 2
0 3 3
0 2 4
4 5 5
2 3 6
3 5 7
2 1 8
2 4 9
2 5 10
3 4 11
*/
