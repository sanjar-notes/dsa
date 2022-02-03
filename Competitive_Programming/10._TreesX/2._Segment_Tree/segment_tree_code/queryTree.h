// #include "segTree.h"
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
