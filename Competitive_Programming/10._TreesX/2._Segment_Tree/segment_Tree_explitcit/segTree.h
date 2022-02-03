class segTreeNode
{
public:
    int value, start, end;
    segTreeNode *left, *right;
};

class segTree
{
private:
    int *arr, *tree;
    int start, end;

public:
    segTree(int *arr, int n = 1)
    {
        this->arr = arr;
        tree = new int[4 * n];
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
