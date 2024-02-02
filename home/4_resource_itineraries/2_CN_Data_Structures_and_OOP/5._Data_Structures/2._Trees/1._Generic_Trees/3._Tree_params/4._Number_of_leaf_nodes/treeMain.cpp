#include <iostream>
using namespace std;
#include "TreeNode_Input_and_Print.h"

int main()
{
    TreeNode<int> *root = levelwise_Input<int>();
    cout << "Leaves: " << numNodesLeaves(root);
    // 1 3 2 3 4 2 5 6 1 7 1 8 0 0 0 1 9 0
    cout << endl;
    return 0;
}
