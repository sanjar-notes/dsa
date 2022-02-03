#include <bits/stdc++.h>
using namespace std;

class segTree
{
private:
    int *arr, *tree;
    int (*func)(int, int);

public:
    segTree(
        int *arr, int n = 1, int (*func)(int, int) = [](int x, int y) -> int { return x + y; })
    {
        this->arr = arr;
        tree = new int[4 * n];
        this->func = func;
    }

    int *getTree();

    void buildTree(int start, int end, int rootNode);
    void updateTree(int start, int end, int rootNode, int idx, int value);

    int queryTree(int start, int end, int rootNode, int left, int right);
};

int *segTree::getTree()
{
    return tree;
}

void segTree::buildTree(int start, int end, int rootNode) // using param start, end, rootNode to avoid using helper function
{
    if (start == end) // base case
    {
        tree[rootNode] = arr[start];
        return;
    }

    // this is recursive
    int mid = (start + end) / 2; // for the two children
    // building tree symmetrically, so that implicit structure is followed
    buildTree(start, mid, 2 * rootNode);       // left tree, start - mid of array
    buildTree(mid + 1, end, 2 * rootNode + 1); // right tree, mid+1 - end of array

    // calculate for the current case
    tree[rootNode] = func(tree[2 * rootNode], tree[2 * rootNode + 1]); // value stored
}
// OK

void segTree::updateTree(int start, int end, int currentTreeNode, int idx, int value)
{
    // got to the leaf, start==end==idx
    if (start == end)
    {
        arr[idx] = tree[idx] = value;
        return;
    }

    int mid = (start + end) / 2;
    if (idx > mid) // right
        updateTree(mid + 1, end, 2 * currentTreeNode + 1, idx, value);
    else
        updateTree(start, mid, 2 * currentTreeNode, idx, value);
    tree[currentTreeNode] = func(tree[2 * currentTreeNode], tree[2 * currentTreeNode + 1]); // recalculate the value
}
// OK

int segTree::queryTree(int start, int end, int currentTreeNode, int left, int right) // using start, end and currentTreeNode for storage, to avoid helper functions
{
    // completely outside
    if (start > right || end < left)
        return 0;

    // completely inside
    if (left <= start && right <= end)
        return tree[currentTreeNode];

    // partially inside, partially outside
    int mid = (start + mid) / 2;
    int l = queryTree(start, mid, 2 * currentTreeNode, left, right);
    int r = queryTree(mid + 1, end, 2 * currentTreeNode + 1, left, right);
    return func(l, r); // returns l + r
}

int main()
{
    int N, T;
    cin >> T >> N;
    int *arr = new int[N];
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    segTree tree1(arr, N, [](int x, int y) -> int { return min(x, y); });
    tree1.buildTree(0, N, 1);    // start with the first index
    int *tree = tree1.getTree(); // start with the first index
                                 /*----------------------------------------------------*/
    char mode;
    int a, b;
    // for (int i = 0; i < T; i++)
    // {
    //     cin >> mode >> a >> b;
    //     if (mode == 'q')
    //         cout << tree1.queryTree(0, N, 1, a, b);
    //     else
    //         tree1.updateTree(0, N, 1, a, b);
    // }
    return 0;
}
