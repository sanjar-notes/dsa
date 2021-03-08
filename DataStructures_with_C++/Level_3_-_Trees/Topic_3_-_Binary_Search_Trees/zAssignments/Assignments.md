# Assignments

<details> <summary><strong> 1. Create & Insert Duplicate Node </strong></summary>

# 1. Create & Insert Duplicate Node

    Given a Binary Tree with N number of nodes, for each node create a new duplicate node, and insert that duplicate as left child of the original node.

    Note : Root will remain same. So you just need to insert nodes in the given Binary Tree and no need to print or return anything.

**Input format**

    Elements in level order form (separated by space)
    (If any node does not have left or right child, take -1 in its place)

**Output format**

    Level order traversal of updated tree. (Every level in new line)

**Sample Input**

    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

**Sample Output**

    8
    8 10
    5 10
    5 6
    2 6 7
    2 7

**Constraints** :

    1 <= N <= 1000

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    ***************/

    void insertDuplicateNode(BinaryTreeNode<int> *root)
    {
        if(root==NULL)
            return;

        if(root->left==NULL) // only possible if trav is NULL for the first time
            root->left = new BinaryTreeNode<int>(root->data);
        else
        {
            BinaryTreeNode<int>* trav = root->left;
            while(trav!=NULL && trav->right!=NULL)
                trav = trav->right;
            trav->right = new BinaryTreeNode<int>(root->data);
        }

        // recursive steps
        insertDuplicateNode(root->left);
        insertDuplicateNode(root->right);
    }

</details>

---

</details>

<details> <summary><strong> 2. Pair sum BInary Tree </strong></summary>

# 2. Pair sum BInary Tree

    Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.

    Assume binary tree contains all unique elements.

    Note : In a pair, print the smaller element first. Order of different pair doesn't matter.

**Input Format**

    Line 1 : Elements in level order form (separated by space)
    (If any node does not have left or right child, take -1 in its place)
    Line 2 : Integer S

**Output Format**

    Each pair in different line (pair elements separated by space)

**Constraints**:

    1 <= N <= 1000

**Sample Input 1**

    5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    15

**Sample Output 1**

    5 10
    6 9

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    ***************/

    void insertDuplicateNode(BinaryTreeNode<int> *root)
    {
        // we need to start from the leaves, otherwise, the recursion will end up looping forever. As the total nodes are increasing.

        // edge case
        if(root==NULL)
            return;

        // base case
        if(root->left==NULL && root->right==NULL)
        {
            root->left = new BinaryTreeNode<int>(root->data);
            return;
        }

        insertDuplicateNode(root->left);    // for traversing to the left

        // make the child on the left, no need to disturb the right subtree
        BinaryTreeNode<int>* leftsubtree = root->left;
        root->left = new BinaryTreeNode<int>(root->data);
        root->left->left = leftsubtree;

        insertDuplicateNode(root->right);    // for traversing to the right
    }

</details>

---

</details>

<details> <summary><strong> 3. LCA of Binary Tree </strong></summary>

# 3. LCA of Binary Tree

    Given a binary tree and two nodes, find LCA (Lowest Common Ancestor) of the given two nodes in Binary Tree. Read about LCA if you are having doubts about the definition.

    If out of 2 nodes only one node is present, return that node.
    If both are not present, return -1.

**Input Format**

    Line 1 :  Elements in level order form (separated by space)
    (If any node does not have left or right child, take -1 in its place)
    Line 2 : Two integers, Node 1 and Node 2 (separated by space)

**Output Format**

    LCA

**Constraints**:

    1 <= N <= 1000

**Sample Input 1**

    5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    2 10

**Sample Output 1**

    10

**Sample Input 2**

    5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    2 6

**Sample Output 2**

    5

**Sample Input 3**

    5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
    12 78

**Sample Output 3**

    -1

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    ***************/

    // bool lca_helper(BinaryTreeNode<int>* root, int val1, int val2)
    // {
    //     if(root==NULL)
    //         return false;

    //     if(root->data==val1 || root->data==val2)    // base case
    //         return true;

    //     bool left = lca_helper(root->left, val1, val2);
    //     bool right = lca_helper(root->right, val1, val2);

    //     if(left==true && right==true)
    //         return true; // found the node


    // }

    int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2)
    {
        if(root==NULL)
            return -1;

        if(root->data==val1 || root->data==val2)
            return root->data;    // search complete

        int left = lcaBinaryTree(root->left, val1, val2); // search in Left subtree
        int right = lcaBinaryTree(root->right, val1, val2); // search in right subtree

        if(left!=-1 && right!=-1) // if found in both search trees
                return root->data; // found the LCA

        if(left!=-1)    // found only the left, return virtual true
            return left;

        if(right!=-1)    // return virtual true
            return right;

        return -1;    // found nothing in both subtrees, end this direction
    }

</details>

---

</details>

<details> <summary><strong> 4. LCA of BST </strong></summary>

# 4. LCA of BST

    Given a binary search tree and two nodes, find LCA(Lowest Common Ancestor) of the given two nodes in the BST. Read about LCA if you are having doubts about the definition.

    If out of 2 nodes only one node is present, return that node.

    If both are not present, return -1.

**Input Format**

    Line 1 :  Elements in level order form (separated by space)
    (If any node does not have left or right child, take -1 in its place)

    Line 2 : Two integers, Node 1 and Node 2 (separated by space)

**Output Format**

    LCA

**Constraints**:

    1 <= N <= 1000

**Sample Input 1**

    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    2 10

**Sample Output 1**

    8

**Sample Input 2**

    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    2 6

**Sample Output 2**

    5

**Sample Input 3**

    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    12 78

**Sample Output 3**

    -1

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    ***************/

    int lcaInBST(BinaryTreeNode<int>* root , int val1 , int val2)
    {
        if(root==NULL)
            return -1;

        if(root->data==val1 || root->data==val2)
            return root->data;    // search complete, no need to go forward

        // search in both subtrees, but here we can optimize it here it
        if(root->data > val1 && root->data > val2)
            return lcaInBST(root->left, val1, val2); // in left subtree, no chance in the right

        if(root->data < val1 && root->data < val2)    // in right subtree, no chance in the left
            return lcaInBST(root->right, val1, val2);

        // both are from different subtrees
        int first, second;

        if(val1 > root->data)    // checking which subtree to go to got val1
            first = lcaInBST(root->right, val1, val2);
        else
            first = lcaInBST(root->left, val1, val2);


        if(val2 > root->data)    // checking which subtree to go to got val1
            second = lcaInBST(root->right, val1, val2);
        else
            second = lcaInBST(root->left, val1, val2);

        if(first!=-1 && second!=-1)    // if both found something, i.e both true, we are 'at' the LCA
            return root->data;


        // we have false, i.e -1 from one side
        if(first!=-1)
            return first;

        if(second!=-1)
            return second;

        return -1;
    }

</details>

---

</details>

<details> <summary><strong> 5. Largest BST </strong></summary>

# 5. Largest BST

    Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree.

    Return the height of largest BST.

**Input Format**

    Line 1 : Elements in level order form (separated by space)

    (If any node does not have left or right child, take -1 in its place)

**Output Format**

    Each level linked list is printed in new line (elements separated by space).

**Sample Input 1**

    5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

**Sample Output 1**

    2

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    ***************/

    int largestBSTSubtree(BinaryTreeNode<int> *root)
    {
        // return pair<bool isBSt, and height>
        // return y
    }

</details>

---

</details>

<details> <summary><strong> 6. Replace with Sum of greater nodes </strong></summary>

# 6. Replace with Sum of greater nodes

    Given a binary search tree, replace each nodes' data with the sum of all nodes' which are greater or equal than it. You need to include the current node's data also.

    That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.

    You don't need to return or print, just change the data of each node.

**Input Format**

    Line 1 : Elements in level order form (separated by space)

    (If any node does not have left or right child, take -1 in its place)

**Output Format**

    Elements are printed in level order wise, every level in new line

**Sample Input 1**

    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

**Sample Output 1**

    18
    36 10
    38 31
    25

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    ***************/

    void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
        // Write your code here

    }

</details>

---

</details>

<details> <summary><strong> 7. Path Sum Root to Leaf </strong></summary>

# 7. Path Sum Root to Leaf

    Given a binary tree and a number k, print out all root to leaf paths where the sum of all nodes value is same as the given number k.

**Input Format**

    Line 1 : Elements in level order form (separated by space)

    (If any node does not have left or right child, take -1 in its place)

    Line 2 : k

**Output Format**

    Print each path in new line, elements separated by space

**Sample Input 1**

    5 6 7 2 3 -1 1 -1 -1 -1 9 -1 -1 -1 -1
    13

**Sample Output 1**

    5 6 2
    5 7 1

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    ***************/

    int helper(BinaryTreeNode<int> *root, int k);
    {
        if(root==NULL)
            return 0;
    }
    void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)
    {

    }

</details>

---

</details>

<details> <summary><strong> 7. Print nodes at distance k from node </strong></summary>

# 8. Path Sum Root to Leaf

    Given a binary tree, a node and an integer K, print nodes which are at K distance from the the given node.

**Input Format**

    Line 1 : Elements in level order form (separated by space)

    (If any node does not have left or right child, take -1 in its place)

    Line 2 : Node

    Line 3 : K

**Output Format**

    Answer nodes in different line

**Sample Input**

    5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
    3
    1

**Sample Output**

    9
    6

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    ***************/

    void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
        // Write your code here

    }

</details>

---

</details>

<details> <summary><strong> 9. Pair sum in a BST </strong></summary>

# 9. Pair sum in a BST

    Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space only O(log n).

    Assume BST contains all unique elements.
    Note: In a pair, print the smaller element first.

**Input Format**

    Line 1: Elements in the level order form (separated by space)

    (If any node does not have left or right child, take -1 in its place)

    Line 2: S

**Output Format**

    Each pair in a different line (pair elements separated by space)

**Sample Input**

    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    12

**Sample Output**

    2 10
    5 7

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    ***************/

    void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
        // Write your code here

    }

</details>

---

</details>
