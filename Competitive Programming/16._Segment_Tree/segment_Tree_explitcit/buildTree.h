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
    tree[rootNode] = tree[2 * rootNode] + tree[2 * rootNode + 1]; // value stored
}
// OK
