// #include "segTree.h"

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
