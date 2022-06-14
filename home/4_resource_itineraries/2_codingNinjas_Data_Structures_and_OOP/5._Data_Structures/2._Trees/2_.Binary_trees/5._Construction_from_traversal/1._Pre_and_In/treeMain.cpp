#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"

int main()
{
    BinaryTreeNode<int> *root = levelWiseInput<int>();
    rawLRPrint(root);
    delete root;
    cout << endl;
    return 0;
}
