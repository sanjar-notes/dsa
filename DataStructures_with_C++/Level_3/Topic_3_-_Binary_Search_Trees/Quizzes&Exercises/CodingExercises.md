<details> <summary><strong> 1. Search in BST </strong></summary>

# 1. Search in BST

    Given a BST and an integer k. Find if the integer k is present in given BST or not. Return the node with data k if it is present, return null otherwise.

    Assume that BST contains all unique elements.

**Input format**

    Line 1 : Elements in level order form (separated by space)
    (If any node does not have left or right child, take -1 in its place)
    Line 2 : Integer k

**Output Format**

    Node with data k

**Sample Input 1**

    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    2

**Sample Output 1**

    2

**Sample Input 2**

    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    12

**Sample Output 2**

    (empty)

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

    BinaryTreeNode<int> *searchInBST(BinaryTreeNode<int> *root, int k)
    {
        if (root == NULL)
            return NULL;
        if (root->data == k)
            return root;
        return k > root->data ? searchInBST(root->right, k) : searchInBST(root->left, k);
    }

</details>

---

</details>

<details> <summary><strong> 2. Code: Print Elements in Range </strong></summary>

# 2. Code: Print Elements in Range

    Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).
    Print the elements in increasing order.

**Input Format**

    Line 1 : Elements in level order form (separated by space)
    (If any node does not have left or right child, take -1 in its place)
    Line 2 : Two Integers k1 and k2

**Output Format**

    Required elements (separated by space)

**Sample Input**

    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    6 10

**Sample Output**

    6 7 8 10

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

    void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2)
    {
        if (root == NULL)
            return;

        // as we need to print in increasing order we need to do inorder traversal
        // check left subtree
        if (root->data >= k1)
            elementsInRangeK1K2(root->left, k1, k2);

        // check the node's value
        if (root->data >= k1 && root->data <= k2)
            cout << root->data << " ";

        // check right subtree
        if (root->data <= k2)
            elementsInRangeK1K2(root->right, k1, k2);
    }

</details>

---

</details>

<details> <summary><strong> 3. Check if a Binary Tree is BST </strong></summary>

# 3. Check if a Binary Tree is BST

    Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree) or not. If yes, return true, return false otherwise.
    Duplicate elements should be in right subtree.

**Input Format**

    Line 1 : Nodes in level order form (separated by space). If any node does not have left or right child, take -1 in its place

**Output Format**

    true or false

**Constraints**

    1 <= N <= 10^5

**Sample Input 1**

    3 1 5 -1 2 -1 -1 -1 -1

**Sample Output 1**

    true

**Sample Input 2**

    5 2 10 0 1 -1 15 -1 -1 -1 -1 -1 -1

**Sample Output 2**

    false

<details> <summary><strong>Code: Approach 1</strong></summary>

    // Following is the Binary Tree node structure

    /**************
    class BinaryTreeNode
    {
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

    int maxBT(BT *root)
    {
        if (root == NULL)
            return INT_MIN;
        return max((root->data), maxBT(root->left), maxBT(root->right));
    }

    int minBT(BT *root)
    {
        if (root == NULL)
            return INT_MAX;
        return min((root->data), minBT(root->left), minBT(root->right));
    }

    bool isBST(Bt *root)
    {
        if (root == NULL || root->left && root - right == NULL)
            return true; // leaf and no node
        if (root->data > min(root->left) && root->data < max(root->right) && isBST(root->left) && isBST(root->right))
            return true; // Joining two Binary Search trees by a node is not neccessarily a Binary Search tree. Because we need to check the subtree property.
                        // remember by checking for min and max only, we are still oblivious of the fact whether the left and right are Binary Search Trees.
        return false;
    }

    /*
    f(n) = 2n+T(n/2) =  nh =  nodes * height
    worst case - O(n2) skewed tree, O(nlog2n)
    Not a good solution as we have to do work again and again.
    */

</details>

<details> <summary><strong>Code: Approach 2</strong></summary>

    pair<pair<int, int>, bool> isBST_h(BT *)
    {
        pair<pair<int, int>, bool> ret;

        ret.first.first = INT_MIN;
        ret.first.second = INT_MAX;
        ret.second = false;

        if (root == NULL)
        {
            ret.second = true;
            return ret;
        }

        if (root->left == NULL && root->right == NULL)
        {
            ret.first.first = root->data; // minimum and maximum are the same
            ret.first.second = root->data;
            ret.second = true;
            return ret;
        }

        if (root->left != NULL)
            ret = isBST_h(root->left);

        if (ret.second) // we are only worried about the minimum
        {
            pair<pair<int, int>, bool> ret2;
            ret2 = isBST_h(root->right);
            ret.first.second = ret2.second.second; // maximum
            ret.second && = re2.second;
            return ret;
        }
    }

    bool isBST(BT* root)
    {
        return isBST_h(root);
    }
    // Time complexity : T(n) = 2T(n / 2) + k, O(n) is independent of height.

</details>

<details> <summary><strong>Code: Approach 3</strong></summary>

    bool isBST_h(BinaryTreeNode<int> *root, int min, int max)
    {
        if (root == NULL)
            return true;

        // node's data should be in range of either side of min or max
        if (!(root->data < min && root->data >= max))
            return false;
        // pass the min and max onto the subtrees
        return isBST_h(root->left, root->data, max) && isBST_h(root->right, min, root->data);
    }

    #include <climits>

    bool isBST(BinaryTreeNode<int> *root)
    {
        // top down approacj
        // simulating the creation if the tree
        if (root == NULL)
            return true;

        // initially we have no restrain
        return isBST_h(root, INT_MAX, INT_MIN); // need to start from -infinity and +infinity`
    }

</details>

---

</details>

<details><summary><strong> 4. Code: Construct BST from a Sorted Array </strong></summary>

# 4. Code: Construct BST from a Sorted Array

    Given a sorted integer array A of size n which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
    Note : If array size is even, take first mid as root.

![Mirroring](./mirrored.png)

    Note : You don't need to print or return the tree, just mirror it.

**Input Format**

    Line 1 : Integer n (Size of array)
    Line 2 : Array elements (separated by space)

**Output Format**

    BST elements (in pre order traversal, separated by space)

**Sample Input**

    7
    1 2 3 4 5 6 7

**Sample Output**

    4 2 1 3 6 5 7

<details> <summary><strong>Code</strong></summary>

    // Following is the Binary Tree node structure
    /**************
    class BinaryTreeNode
    {
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

    BinaryTreeNode<int> *constructTree(int *input, int n)
    {
        if (n == 0)
            return NULL; // i.e no node

        // somewhat left skewed
        BinaryTreeNode<int> *newnode = new BinaryTreeNode<int>(input[(n - 1) / 2]);

        // took the (n-1)/2 because we have take the first mid
        newnode->left = constructTree(input, (n - 1) / 2);  // all the numbers on the left of the array
        newnode->right = constructTree(input + (n - 1) / 2 + 1, n - (n - 1) / 2 - 1);   // all the numbers on the right - 1. i.e except the newode. + 1 and -1 are for that.
        return newnode;
    }

</details>

---

</details>

<details> <summary><strong> 5. Code: BST to Sorted LL </strong></summary>

# 5. Code: BST to Sorted LL

    Given a BST, convert it into a sorted linked list. Return the head of LL.

**Input Format**

    Elements in level order form (separated by space)
    (If any node does not have left or right child, take -1 in its place)

**Output Format**

    Linked list elements (separated by space)

**Sample Input**

    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1

**Sample Output**

    8 3 1 6 4 7 10 14 13

<details> <summary><strong>Code: Naive approach</strong></summary>

    /**************
    template <typename T>
    class Node
    {
        public:
        T data;
        Node<T> *next;

        Node(T data)
        {
            this -> data = data;
            this -> next = NULL;
        }
    };

    class BinaryTreeNode
    {
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

    Node<int> *constructBST(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
            return NULL; // base case

        Node<int> *newnode = new Node<int>(root->data);
        newnode->next = constructBST(root->right);

        // traverse to the head
        Node<int> *trav = constructBST(root->left);
        Node<int> *head = trav;

        while (trav != NULL && trav->next != NULL)
            trav = trav->next;
        if (trav == NULL)
            return newnode;
        trav->next = newnode;
        return head;
    }

</details>

<details> <summary><strong>Code: Pair return approach</strong></summary>

    pair<Node<int> *, Node<int> *> constructBST_h(BinaryTreeNode<int> *root)
    {

        if (root == NULL)
        {
            pair<Node<int> *, Node<int> *> p(NULL, NULL);
            return p;
        }

        pair<Node<int> *, Node<int> *> left = constructBST_h(root->left); // got the left subtrees LL;

        if (left.first == NULL)
        {
            left.first = new Node<int>(root->data);
            left.second = left.first;
        }
        else
        {
            left.second->next = new Node<int>(root->data);
            left.second = left.second->next; // current node attached at the end
        }

        // we've got everything ready
        pair<Node<int> *, Node<int> *> right = constructBST_h(root->right); // got the right subtrees LL;

        if (right.first == NULL)
            return left;
        else
        {
            left.second->next = right.first; // attached the whole LL together
            // using left as return value now
            left.second = right.second;
        }

        return left;
    }

    /* Insights:
        1.  We take very less time now. Memory usage has increased though.
        2.  We have a again demonstrated as to how important, multi returning works.
    */

</details>

---

</details>
<details> <summary><strong> 6. Find Path in BST </strong></summary>

# 6. Find Path in BST

    Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST). Return null otherwise.

    Assume that BST contains all unique elements.

**Input Format**

    Line 1 : Elements in level order form (separated by space)
    (If any node does not have left or right child, take -1 in its place)
    Line 2 : Integer k

**Output Format**

    Path from node k to root

**Sample Input**

    8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
    2

**Sample Output**

    2
    5
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

    vector<int> *findPath(BinaryTreeNode<int> *root, int data)
    {
        if (root == NULL) // Base case
            return NULL;
        // rather than using empty vector as the sign or bool pair. We avoided it altogether coz vector pointer being NULL is enough evidence that there's no path
        // we'll have to return something

        vector<int> *p = new vector<int>; // empty vector
        // base case 1
        if (root->data == data)
        {
            // create dynamically otherwise we'll have a dangling pointer
            p->push_back(root->data);
            return p;
        }

        // root->data does not match the data

        p = findPath(root->left, data);

        if (p) // p is non null
        {
            p->push_back(root->data);
            return p;
        }

        p = findPath(root->right, data);

        if (p) // p is non null
            p->push_back(root->data);

        return p;
    }

</details>

---

</details>

<details> <summary><strong> 7. Code: BST Class </strong></summary>

# 7. Code: BST Class

    Implement the BST class which includes following functions -
    1. search
    Given an element, find if that is present in BSt or not. Return true or false.

    2. insert -
    Given an element, insert that element in the BST at the correct position. Assume unique elements will be given.

    3. delete -
    Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.

    4. printTree (recursive) -
    Print the BST in ithe following format -
    For printing a node with data N, you need to follow the exact format -

    N:L:x,R:y

    where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.

    There is no space in between.

    You need to print all nodes in the recursive format in different lines.

    Note : main function is given for your reference which we are using internally to test the class.

<details> <summary><strong>Code</strong></summary>

    #include <climits>
    class BST
    {
    public:
        BinaryTreeNode<int> *root;

    private:
        bool hasData(int data, BinaryTreeNode<int> *root)
        {
            if (root == NULL)
                return false; // not found

            if (root->data == data)
                return true;

            if (data < root->data) // look in the left subtree
                return hasData(data, root->left);
            return hasData(data, root->right); // looking in the right subtree

            // or just
            // root->data==data || hasData(data, root->left) || hasData(data, root->right);
        }

        BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> *root)
        {
            if (root == NULL)
            {
                root = new BinaryTreeNode<int>(data);
                return root;
            }

            //assign to the correct subtree, we do this coz one of them could be NULL
            if (root->data < data) // in the left subtree
                root->right = insert(data, root->right);
            // if (root->data > data) // in the right subtree
            else
                root->left = insert(data, root->left);
            return root; // required where we try to insert duplicate data
        }

        BinaryTreeNode<int> *deleteData(int data, BinaryTreeNode<int> *root)
        {
            if (root == NULL)
                return NULL;

            // root is definitely not NULL

            if (data > root->data)
                root->right = deleteData(data, root->right);

            else if (data < root->data)
                root->left = deleteData(data, root->left);

            else // base case, i.e found the node
            {
                if (root->left == NULL) // no left subtree or leaf case
                {
                    BinaryTreeNode<int> *newroot = root->right;
                    root->right = NULL; // disconnecting the parent first. So that deallocation does not kill the whole tree.
                    delete root;
                    return newroot;
                }

                if (root->right == NULL) // Left tree is there but no right subtree
                {
                    BinaryTreeNode<int> *newroot = root->left;
                    root->left = NULL; // removing the parent first. So that deallocation does not kill the whole tree.
                    delete root;
                    return newroot;
                }

                // both left and right subtrees exist
                // doing in an iterative way
                // min in the right subtree

                BinaryTreeNode<int> *minNode = root->right; // root of right subtree, this is not NULL

    //             if (minNode->left == NULL) // the right subtree is just one node
    //             {
    //                 root->right = NULL;
    //                 delete minNode;
    //                 return root;
    //             }

    //             while (minNode->left != NULL && minNode->left->left != NULL)
    //                 minNode = minNode->left;

    //             // we are now on the parent of minNode
    //             root->data = minNode->left->data;

    //             // delete the minNode->left
    //             // deallocate
    //             delete minNode->left;
    //             minNode->left = NULL;

                while(minNode->left!=NULL)
                    minNode = minNode->left;
                // we have reached the minNode
                root->data = minNode->data;
                root->right = deleteData(root->data, root->right);
                return root;
            }

            return root;
        }

        void printTree(BinaryTreeNode<int> *root)
        {
            if (root == NULL)
                return;
            cout << root->data << ":";

            if (root->left != NULL)
                cout << "L:" << root->left->data << ",";
            if (root->right != NULL)
                cout << "R:" << root->right->data;

            cout << endl;

            printTree(root->left);
            printTree(root->right);
        }

    public:
        BST()
        {
            root = NULL;
        }

        bool hasData(int data)
        {
            return hasData(data, root);
        }

        int max(BinaryTreeNode<int> *root)
        {
            if (root == NULL)
                return INT_MIN;
            return max(root->right);
        }

        int min(BinaryTreeNode<int> *root)
        {
            if (root == NULL)
                return INT_MAX;
            return min(root->left);
        }

        void insert(int data)
        {
            // how to, just insert give the data to the tree which has to have it
            // it will attach itself
            // somewhat like c onstructing the tree again
            root = insert(data, root); // The root changes when the tree is empty
        }

        void deleteData(int data)
        {
            root = deleteData(data, root);
        }

        void printTree()
        {
            printTree(root);
        }

        ~BST()
        {
            delete root;
        }
    };

</details>

---

</details>
