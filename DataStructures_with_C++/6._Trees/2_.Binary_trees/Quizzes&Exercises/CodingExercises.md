<details> <summary><strong> 1. Print Level Wise </strong></summary>

# 1. Print Level Wise

    Given a binary tree, print the tree in level wise order.
    For printing a node with data N, you need to follow the exact format -
    N:L:x,R:y
    wherer, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print -1. if any child is null.
    There is no space in between.
    You need to print all nodes in the level order form in different lines.

**Input format**

    Elements in level order form (separated by space)
    (If any node does not have left or right child, take -1 in its place)

**Sample Input**

    8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

**Sample Output**

    8:L:3,R:10
    3:L:1,R:6
    10:L:-1,R:14
    1:L:-1,R:-1
    6:L:4,R:7
    14:L:13,R:-1
    4:L:-1,R:-1
    7:L:-1,R:-1
    13:L:-1,R:-1

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

        #include <queue>
        void printLevelWise(BinaryTreeNode<int> *root)
        {
            if (root == NULL)
                return;
            // using a queue
            queue<BinaryTreeNode<int> *> nodesPending;

            nodesPending.push(root);

            while (nodesPending.size() != 0)
            {
                root = nodesPending.front();
                cout << root->data << ":";
                if (root->left != NULL)
                {
                    nodesPending.push(root->left);
                    cout << "L:" << root->left->data << ",";
                }
                else
                    cout << "L:-1,";

                if (root->right != NULL)
                {
                    nodesPending.push(root->right);
                    cout << "R:" << root->right->data << "\n";
                }
                else
                    cout << "R:-1\n";

                nodesPending.pop();
            }
        }

</details>

---

</details>

<details> <summary><strong> 2. Find a node </strong></summary>

# 2. Find a node

    Given a Binary Tree and an integer x, check if node with data x is present in the input binary tree or not. Return true or false.

**Input Format**

    Line 1 : Elements in level order form (separated by space)
    (If any node does not have left or right child, take -1 in its place)
    Line 2 : Integer x

**Output Format**

    true or false

**Sample Input**

    8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1
    7

**Sample Output**

    true

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

    bool isNodePresent(BinaryTreeNode<int> *root, int x)
    {
        // preorder traversal
        if (root == NULL)
            return false;
        if (root->data == x)
            return true;
        return isNodePresent(root->left, x) || isNodePresent(root->right, x); // it may be present in either. It will be shortcircuited, so it's quick.
    }

s

</details>

---

</details>

<details> <summary><strong> 3. Height of Binary Tree </strong></summary>

# 3. Height of Binary Tree

    Given a binary tree, find and return the height of given tree.

**Input Format**

    Nodes in the level order form (separated by space). If any node does not have left or right child, take -1 in its place

**Output Format**

    Height

**Constraints**

    1 <= N <= 10^5

**Sample Input**

    10
    9
    4
    -1
    -1
    5
    8
    -1
    6
    -1
    -1
    3
    -1
    -1
    -1

**Sample Output**

    5

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

    int height(BinaryTreeNode<int> *root)
    {
        // height = max(height lt, height rt) + 1;
        if (root == NULL)
            return 0;
        return max(height(root->left), height(root->right)) + 1;
    }

</details>

---

</details>

<details><summary><strong> 4. Mirror </strong></summary>

# 4. Mirror

    Mirror the given binary tree. That is, right child of every nodes should become left and left should become right.

![Mirroring](./mirrored.png)

    Note : You don't need to print or return the tree, just mirror it.

**Input Format**

    Line 1 : Elements in level order form (separated by space)

    (If any node does not have left or right child, take -1 in its place)

**Output Format**

    Elements in level order form (Every level in new line)

**Sample Input 1**

    1 2 3 4 5 6 7 -1 -1 -1 -1 -1 -1 -1 -1

**Sample Output 1**

    1
    3 2
    7 6 5 4

**Sample Input 2**

    5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1

**Sample Output 2**

    5
    6 10
    3 2
    9

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

    void mirrorBinaryTree(BinaryTreeNode<int> *root)
    {
        // mirror the left and right address, do for the same rest.

        if (root == NULL)
            return;

        if (root->left == NULL)
        {
            root->left = root->right;
            root->right = NULL;
            mirrorBinaryTree(root->left);
            return;
        }

        if (root->right == NULL)
        {
            root->right = root->left;
            root->left = NULL;
            mirrorBinaryTree(root->right);
            return;
        }

        // both are non-null
        BinaryTreeNode<int> *temp = root->left;
        root->left = root->right;
        root->right = temp;
        mirrorBinaryTree(root->left);
        mirrorBinaryTree(root->right);
    }

</details>

---

</details>

<details> <summary><strong> 5. Preorder Binary Tree </strong></summary>

# 5. Preorder Binary Tree

    Given a binary tree, print the preorder traversal of given tree.

    Pre-order traversal is: Root LeftChild RightChild

**Input Format**

    Elements in level order form (separated by space)
    (If any node does not have left or right child, take -1 in its place)

**Output Format**

    Pre-order traversal, elements separated by space

**Sample Input**

    8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

**Sample Output**

    8 3 1 6 4 7 10 14 13

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

    void preOrder(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return;

        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

</details>

---

</details>
<details> <summary><strong> 6. PostOrder Traversal </strong></summary>

# 6. PostOrder Traversal

    Given a generic tree, print the post-order traversal of given tree.

    Post-order traversal is : Children and then Root

**Input Format**

    Elements in level order form (separated by space)
    (If any node does not have left or right child, take -1 in its place)

**Output Format**

    Post-order traversal, elements separated by space

**Sample Input**

    8 3 10 1 6 -1 14 -1 -1 4 7 13 -1 -1 -1 -1 -1 -1 -1

**Sample Output**

    1 4 7 6 3 13 14 10 8

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

    void postOrder(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return;

        // go left
        postOrder(root->left);

        // go right
        postOrder(root->right);

        // both and right done, print the node
        // automatically holds for leaves
        cout << root->data << " ";
    }

</details>

---

</details>

<details> <summary><strong> 7.  Construct Tree from Preorder and Inorder </strong></summary>

# 7. Construct Tree from Preorder and Inorder

    Given Preorder and Inorder traversal of a binary tree, create the binary tree associated with the traversals.You just need to construct the tree and return the root.

    Note: Assume binary tree contains only unique elements.

**Input Format**

    Line 1 : n (Total number of nodes in binary tree)
    Line 2 : Pre order traversal
    Line 3 : Inorder Traversal

**Output Format**

    Elements are printed level wise, each level in new line (separated by space).

**Sample Input**

    12
    1 2 3 4 15 5 6 7 8 10 9 12
    4 15 3 2 5 1 6 10 8 7 9 12

**Sample Output**

    1
    2 6
    3 5 7
    4 8 9
    15 10 12

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
    ***************/

    BinaryTreeNode<int> *buildTree(int *preorder, int preLength, int *inorder, int inLength)
    {
        if (preLength == 0) // assuming that preLength and inLength are always the same, they should be.
            return NULL;

        BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[0]);
        // root found

        // find the index where root ocuurs in the inOrder
        int i = 0;
        for (; i < inLength && inorder[i] != root->data; i++)
            ;
        // i  = length of left subtree

        // make a diagram and solve for the following parameters

        int *p_pre_l = 0, *p_pre_r = 0, *p_in_l = 0, *p_in_r = 0;
        int len_pre_l = 0, len_pre_r = 0, len_in_l = 0, len_in_r = 0;

        p_pre_l = preorder + 1;     // after the root
        p_pre_r = preorder + 1 + i; // after root and left subtree
        p_in_l = inorder;           // same as inorder
        p_in_r = inorder + i + 1;   // left + root

        // doubt: Is i useful for both pre and postorder, yes. Beacuse pre gets called on the whole left tree and in also gets called on the whole subtree.
        // so it is the same

        len_pre_l = i;                 // same as i
        len_pre_r = preLength - 1 - i; // right subtree and root
        len_in_l = i;                  // same as i
        len_in_r = inLength - 1 - i;

        root->left = buildTree(p_pre_l, len_pre_l, p_in_l, len_in_l);   // left subtree
        root->right = buildTree(p_pre_r, len_pre_r, p_in_r, len_in_r);  // right subtree

        return root;
    }

</details>

---

</details>

<details> <summary><strong> 8. Construct Tree from Postorder and Inorder </strong></summary>

# 8. Construct Tree from Postorder and Inorder

    Given Postorder and Inorder traversal of a binary tree, create the binary tree associated with the traversals.You just need to construct the tree and return the root.

    Note: Assume binary tree contains only unique elements.

**Input Format**

    Line 1 : n (Total number of nodes in binary tree)
    Line 2 : Post order traversal
    Line 3 : Inorder Traversal

**Output Format**

    Elements are printed level wise, each level in new line (separated by space).

**Sample Input**

    8
    8 4 5 2 6 7 3 1
    4 8 2 5 1 6 3 7

**Sample Output**

    1
    2 3
    4 5 6 7
    8

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

    BinaryTreeNode<int> *getTreeFromPostorderAndInorder(int *postorder, int postLength, int *inorder, int inLength)
    {
        if (postLength == 0)
            return NULL;

        BinaryTreeNode<int> *root = new BinaryTreeNode<int>(postorder[postLength - 1]);

        // compute the following
        int *p_post_l, *p_post_r, *p_in_l, *p_in_r;
        int len_post_l, len_post_r, len_in_l, len_in_r;

        int i = 0;
        while (i < inLength && inorder[i] != root->data)
            i++;

        // found i, the index of root in inorder

        p_post_l = postorder;
        p_post_r = postorder + i;
        p_in_l = inorder;
        p_in_r = inorder + i + 1;

        len_post_l = i;
        len_post_r = postLength - i - 1; // i.e except root and left subtree
        len_in_l = i;
        len_in_r = inLength - i - 1; // i.e except root and left subtree

        root->left = getTreeFromPostorderAndInorder(p_post_l, len_post_l, p_in_l, len_in_l);
        root->right = getTreeFromPostorderAndInorder(p_post_r, len_in_r, p_in_r, len_in_r);

        return root;
    }

</details>

---

</details>
