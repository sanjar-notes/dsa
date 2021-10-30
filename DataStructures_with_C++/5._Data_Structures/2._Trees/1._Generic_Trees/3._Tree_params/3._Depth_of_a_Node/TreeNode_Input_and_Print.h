#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class TreeNode
{
public:
    T data;
    vector<TreeNode<T> *> children; // we could also write <TreeNode*>

    TreeNode(T data = 0)
    {
        this->data = data;
        // children is NULL by default
    }

    ~TreeNode()
    {
        //recursive destructor
        for (int i = 0; i < children.size(); i++)
            delete children.at(i);
        cout << "Node deleted\n";
    }
};

template <typename T>
void difficult_printTree(TreeNode<T> *root)
{
    // if (root == NULL || root->children.size() == 0)
    //     return;
    cout << root->data << "\n";
    for (int i = 0; i < root->children.size(); i++)
        incompletprintTree(root->children.at(i));
}

template <typename T>
void printTree(TreeNode<T> *root)
{
    static string disp = "Tree\n";
    cout << disp;
    disp = "";
    cout << root->data << ": ";

    int n = root->children.size();

    for (int i = 0; i < n; i++)
        cout << root->children[i]->data << ", ";

    if (n == 0)
        cout << "Leaf\n";
    else
        cout << "\b\b  \n";

    for (int i = 0; i < n; i++)
        printTree(root->children.at(i));
}

template <typename T>
TreeNode<T> *difficult_Input()
{
    cout << "Enter root data: ";
    int data;
    cin >> data;
    TreeNode<T> *root = new TreeNode<T>(data);

    cout << "Number of children: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        TreeNode<T> *child = difficult_Input<T>();
        root->children.push_back(child);
    }
    return root;
    /*
        Insights:
        Takes in a DFS way, uses pure recursion, hence stack.
        Hard to write code, difficult to use the function.
    */
}

template <typename T>
TreeNode<T> *levelwise_Input()
{
    //make the root
    cout << "Data for root node: ";
    int data;
    cin >> data;

    TreeNode<T> *root = new TreeNode<T>(data);

    queue<TreeNode<T> *> nodesPending;
    nodesPending.push(root); // obviously pending

    while (nodesPending.size() != 0)
    {
        data = nodesPending.front()->data; // cureent root's data
        cout << "Number of children for " << data << " : ";
        int n;
        cin >> n; // if user enters negative, we return. Assuming that it has no children. As if n were 0.
        for (int i = 0; i < n; i++)
        {
            cout << "Data for " << data << "'s " << i << "th child: ";
            TreeNode<T> *child = new TreeNode<T>;
            cin >> child->data;
            nodesPending.front()->children.push_back(child);
            nodesPending.push(child);
        }
        nodesPending.pop();
    }
    return root;
    // When you are a leaf
    /*
        Insights: Takes in a BFS way, is an implicit queue.
        Easy to use.
        Maid: Do things in the order of arrival, queue
        Description:
            Goes to a node, takes all data for its children.
            Then starts from the first child. When that is over goes to the second child. Ans so on.
    */
}

template <typename T>
void levelwise_printTree(TreeNode<T> *root)
{
    //prank check
    if (root == NULL)
        return;

    queue<TreeNode<T> *> nodesPending;

    nodesPending.push(root); // obviously pending, we have not printed it's children.

    // Another reason is that if we don't do this, then queue will not be systematic.

    // for optimization
    T data;                   // for relevance
    int n;                    // number of children
    TreeNode<T> *node = NULL; // the parent node

    // start printing the children
    while (nodesPending.size() != 0)
    {
        node = nodesPending.front(); // current root's data
        n = node->children.size();
        data = node->data;

        if (n == 0)
            cout << node->data << ": Leaf\n";
        else
        {
            cout << "Children of " << data << ": ";
            for (int i = 0; i < n; i++)
            {
                cout << node->children.at(i)->data << ", ";
                nodesPending.push(node->children.at(i));
            }
            cout << "\b\b  \n";
        }

        nodesPending.pop();
    }
}

template <typename T>
int countNodes(TreeNode<T> *root)
{
    // prank check
    if (root == NULL)
        return 0;

    // // base case
    // if (root->children.size() == 0)
    //     return 1; // leaf node
    // base case is redundant

    // recursion, return nodes for all children
    int sum = 1; // root counted
    int children_num = root->children.size();
    for (int i = 0; i < children_num; i++)
        sum += (countNodes(root->children.at(i)));

    return sum; // i.e the root node
}

template <typename T>
void print_nodes_at_depth(TreeNode<T> *root, int d)
{
    //edge case
    if (root == NULL)
        return;

    if (d == 0) // base case
    {
        cout << root->data << " ";
        return; // at doeth node
    }

    // otherwise ignored
    for (int i = 0; i < root->children.size(); i++)
        print_nodes_at_depth(root->children.at(i), d - 1); // leaf node has to skip this
}
