#include <iostream>
using namespace std;
#include "TreeNode_Input_and_Print.h"

template <typename T>
void preOrder(TreeNode<T> *root);

template <typename T>
void inOrder(TreeNode<T> *root);

template <typename T>
void postOrder(TreeNode<T> *root);

int main()
{
    TreeNode<int> *root = levelwise_Input<int>();
    // 1 3 2 3 4 2 5 6 1 7 1 8 0 0 0 1 9 0
    postOrder(root);
    delete root;
    cout << endl;
    return 0;
}

template <typename T>
void preOrder(TreeNode<T> *root)
{
    if (root == NULL)
        return;
    //NLR
    cout << root->data << " ";

    for (int i = 0; i < root->children.size(); i++)
        preOrder(root->children.at(i));
    // for loop takes care of the right ones
    // left means nothing but the immediate children.
}

template <typename T>
void inOrder(TreeNode<T> *root)
{
    if (root == NULL)
        return;
    //NLR

    if (root->children.size() == 0)
    {
        cout << root->data << " ";
        return;
    }
    //else
    inOrder(root->children.at(0)); // this will have no effect for zero children
    cout << root->data << " ";
    for (int i = 1; i < root->children.size(); i++)
        inOrder(root->children.at(i));
    // for loop takes care of the right ones
}

template <typename T>
void postOrder(TreeNode<T> *root)
{
    if (root == NULL)
        return;

    // print all the subtrees of the children, if nothing for is not executed
    for (int i = 0; i < root->children.size(); i++)
        postOrder(root->children.at(i));

    // print the node
    cout << root->data << " ";
}
