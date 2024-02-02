#include <iostream>
using namespace std;
#include "BinaryTreeNode.h"

int main()
{
    BinaryTreeNode<int> *root = levelWiseInput<int>();
    cout << "\n-------------------------------------------------------------\n";
    rawLRPrint(root);
    // level_n_print(root, 2);
    /*
    ip
    1 2 3 4 -1 5 6 -1 -1 -1 7 -1 -1 -1 -1

    pre
    1 2 4 3 5 7 6

    post
    4 2 7 5 6 3 1

    in
    4 2 1 5 7 3 6

    level
    1 2 3 4 5 6 7
    */
    cout << "-------------------------------------------------------------\n";
    delete root;
    cout << endl;
    return 0;
}
