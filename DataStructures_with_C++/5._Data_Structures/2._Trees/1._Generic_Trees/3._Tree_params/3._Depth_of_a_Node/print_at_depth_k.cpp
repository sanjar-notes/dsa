#include <iostream>
using namespace std;
#include "TreeNode_Input_and_Print.h"

int main()
{
    TreeNode<int> *root = levelwise_Input<int>();
    print_nodes_at_depth(root, 3);
    cout << endl;
    return 0;
}
