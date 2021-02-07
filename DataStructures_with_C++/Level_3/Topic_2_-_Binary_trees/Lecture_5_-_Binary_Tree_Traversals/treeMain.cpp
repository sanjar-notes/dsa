#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"

int main()
{
    BinaryTreeNode<int> *root = levelWiseInput<int>();
    // rawLRPrint(root);
    /*
    1 2 3 4 -1 5 6 -1 -1 -1 7 -1 -1 -1 -1
    */
    inOrder(root);
    delete root;
    cout << endl;

    return 0;
}
