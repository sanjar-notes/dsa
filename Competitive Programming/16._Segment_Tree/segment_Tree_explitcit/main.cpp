#include <iostream>
using namespace std;
#include "segTree.h"
#include "buildTree.h"
#include "updateTree.h"
#include "queryTree.h"

int main()
{
    int N = 8;
    // int N;
    // cin >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
        arr[i] = i + 1;

    segTree tree1(arr, N);
    tree1.buildTree(0, N, 1);    // start with the first index
    int *tree = tree1.getTree(); // start with the first index
                                 /*----------------------------------------------------*/

    // updateTree(arr, tree, 0, 2 * N, 0, N / 2, 23);
    cout << tree[1]; // 0-15 225
    // cout << tree1.queryTree(0, N, 1, 0, 0);
    // for (int i = 0; i < 17; i++)
    //     cout << tree[i] << "\n";
    return 0;
}
