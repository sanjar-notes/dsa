#include <iostream>
using namespace std;
#include "TreeNode.h"

int main()
{
    TreeNode<int> *root = new TreeNode<int>(1);
    TreeNode<int> *c1 = new TreeNode<int>(11);
    TreeNode<int> *c2 = new TreeNode<int>(12);
    root->children.push_back(c1);
    root->children.push_back(c2);

    cout << endl;
    return 0;
}
