template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left, *right;
    BinaryTreeNode(T data = 0)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
    ~BinaryTreeNode()
    {
        //delete NULL is ignored, not an error
        delete left;
        delete right;
        cout << "\nNode cleared";
    }
};

template <typename T>
void rawLRPrint(BinaryTreeNode<T> *root)
{
    // preorder traveral
    //here base case is required, as there's no for loop. Base case is required here. Coincidently, edge case is the same.
    if (root == NULL)
        return;

    cout << "Node: " << root->data << " "; // print the node

    if (root->left != NULL)
        cout << "Left:" << root->left->data << " "; // print the  left pointer if possible

    if (root->right != NULL)
        cout << "Right:" << root->right->data << " ";

    if (root->left == NULL && root->right == NULL)
        cout << "Leaf";

    cout << endl;

    rawLRPrint(root->left);  // no effect if this is NULL
    rawLRPrint(root->right); // same
}

template <typename T>
void rawPrint(BinaryTreeNode<T> *root)
{
    //here base case is required, as there's no for loop. Base case is required here. Coincidently, edge case is the same.
    if (root == NULL)
        return;
    cout << root->data << " ";
    rawPrint(root->left);
    rawPrint(root->right);
}

template <typename T>
BinaryTreeNode<T> *takeInput()
{
    int ip_data;
    cout << "Enter node data: ";
    cin >> ip_data;

    if (ip_data == -1)
        return NULL;

    BinaryTreeNode<T> *ret = new BinaryTreeNode<T>(ip_data);

    ret->left = takeInput<T>();
    ret->right = takeInput<T>();
    return ret;
}

#include <queue>
template <typename T>
BinaryTreeNode<T> *levelWiseInput()
{
    //iterative
    T ip;
    cout << "Enter root data: ";
    cin >> ip;
    if (ip == -1)
        return NULL;

    BinaryTreeNode<T> *root = new BinaryTreeNode(ip);

    queue<BinaryTreeNode<T> *> nodesPending;
    nodesPending.push(root);

    BinaryTreeNode<T> *trav = new BinaryTreeNode(ip);

    //
    while (nodesPending.size() != 0)
    {
        trav = nodesPending.front();
        nodesPending.pop();
        // left node
        cout << "Left of " << trav->data << ": ";
        cin >> ip;

        if (ip != -1)
        {
            BinaryTreeNode<T> *left = new BinaryTreeNode<T>(ip);
            trav->left = left; // connected
            nodesPending.push(left);
        }
        else
            trav->left = NULL;

        // right node
        cout << "Right of " << trav->data << ": ";
        cin >> ip;

        if (ip != -1)
        {
            BinaryTreeNode<T> *right = new BinaryTreeNode<T>(ip);
            trav->right = right; // connected
            nodesPending.push(right);
        }
        else
            trav->right = NULL;
    }
    cout << "\n";
    return root;
}
