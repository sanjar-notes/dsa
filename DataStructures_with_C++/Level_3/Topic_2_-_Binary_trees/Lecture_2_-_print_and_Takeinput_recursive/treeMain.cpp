#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"

int main()
{
    // BinaryTreeNode<int> *root = new BinaryTreeNode<int>(1);
    // root->left = new BinaryTreeNode<int>(2);
    // root->right = new BinaryTreeNode<int>(3);
    rawLRPrint(takeInput<int>());
    cout << endl;
    return 0;
}
