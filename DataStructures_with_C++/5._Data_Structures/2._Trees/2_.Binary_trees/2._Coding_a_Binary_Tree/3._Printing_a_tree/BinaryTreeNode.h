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
        cout << "Node cleared\n";
    }
};

template <typename T>
void rawLRPrint(BinaryTreeNode<T> *root)
{
    //here base case is required, as there's no for loop. Base case is required here. Coincidently, edge case is the same.
    if (root == NULL)
        return;

    cout << "Node: " << root->data << " "; // print the node

    if (root->left != NULL)
        cout << "Left:" << root->left->data << " "; // print the  left pointer if possible

    if (root->right != NULL)
        cout << "Right:" << root->right->data << " ";

    cout << endl;

    rawLRPrint(root->left);   // no effect if this is NULL
    rawLRPrint(root->right);  // same
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
