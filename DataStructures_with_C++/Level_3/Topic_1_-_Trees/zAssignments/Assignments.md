# Assignments

<details> <summary><strong> 1. Contains x </strong></summary>

# 1. Contains x

    Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.

**Input format**

    Line 1 : Integer x

    Line 2 : Elements in level order form separated by space (as per done in class).
    Order is - Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

**Output format**

    true or false

**Sample Input 1**

    40
    10 3 20 30 40 2 40 50 0 0 0 0

**Sample Output 1**

    true

**Sample Input 2**

    4
    10 3 20 30 40 2 40 50 0 0 0 0

**Sample Output 2**

    false

<details> <summary><strong>Code</strong></summary>

    // Following is the given Tree node structure.
    /**************
    template <typename T>
    class TreeNode {
    public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };
    ***************/

    bool containsX(TreeNode<int> *root, int x)
    {
        // random search is the only option as none of the children provide any clue
        // approach: preOrder traversal

        //edge case
        if (root == NULL)
            return false;

        if (root->data == x)
            return true;

        bool ret = false; // this is for exiting when we find the match, no nee to search further

        // checks
        for (int i = 0; i < root->children.size() && ret == false; i++)
            ret = containsX(root->children.at(i), x);

        return ret;
    }


    // approach 2 - level order traversal, iterative as it uses queue

    #include <queue>
    bool containsX(TreeNode<int> *root, int x)
    {
        // random search is the only option as none of the children provide any clue
        // approach: level traversal

        //edge case
        if (root == NULL)
            return false;

        // not possible after a queue is made, coz all things pushed in the queue
        // have not been able to match
        // i.e we scan only children. And root is nobody's child
        if (root->data == x)
            return true;

        queue<TreeNode<int> *> nodesPending;
        nodesPending.push(root);
        TreeNode<int> *temp = nodesPending.front();

        while (nodesPending.size() != 0)
        {
            for (int i = 0; i < temp->children.size(); i++)
            {
                if (temp->children.at(i)->data == x)
                    return true;
                nodesPending.push(temp->children.at(i));    // push the subtree source atleast
            }
            // took all the children, none of them match
            nodesPending.pop();
            temp = nodesPending.front();
        }

        // nothing found
        return false;
    }

</details>

---

</details>

<details> <summary><strong> 2. Count nodes </strong></summary>

# 2. Count nodes

    Given a tree and an integer x, find and return the number of Nodes which are greater than x.

**Input Format**

    Line 1 : Integer x

    Line 2 : Elements in level order form separated by space (as per done in class).
    Order is - Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

**Output Format**

    Count of nodes greater than x

**Sample Input**

    35
    10 3 20 30 40 2 40 50 0 0 0 0

**Sample Output**

    3

**Sample Input**

    10
    10 3 20 30 40 2 40 50 0 0 0 0

**Sample Output**

    5

<details> <summary><strong>Code</strong></summary>

    // Following is the given Tree node structure
    /**************

    template <typename T>
    class TreeNode {
    public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };
    ***************/

    int nodesGreaterThanX(TreeNode<int> *root, int x)
    {
        // need to traverse all the nodes

        // using recursion, preorder traversal

        if (root == NULL)
            return 0;

        int ans = 0;

        //recursive logic
        // f(root, x) = status of root vs x(1 or 0) + f(for all subtrees)

        if (root->data > x)
            ans = 1;
        for (int i = 0; i < root->children.size(); i++)
            ans += nodesGreaterThanX(root->children.at(i), x);
        return ans;
    }

</details>

---

</details>

<details> <summary><strong> 3. Node with maximum child sum </strong></summary>

# 3. Node with maximum child sum

    Given a tree, find and return the node for which sum of data of all children and the node itself is maximum. In the sum, data of node itself and data of immediate children is to be taken.

**Input Format**

    Line 1 : Elements in level order form separated by space (as per done in class).
    Order is - Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

**Output Format**

    Node with maximum sum.

**Sample Input 1**

    5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0

**Sample Output 1**

    1

<details> <summary><strong>Code</strong></summary>

    // Following is the given Tree node structure
    /**************

    template <typename T>
    class TreeNode {
    public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };
    ***************/
    #include <queue>
    TreeNode<int> *maxSumNode(TreeNode<int> *root)
    {
        // avoid using recursion. Use queue

        // edge case + obvious case
        if (root == NULL || root->children.size() == 0)
            return root;

        queue<TreeNode<int> *> nodesPending;

        nodesPending.push(root);

        int currSum = 0, prevSum = -1;
        TreeNode<int> *trav = root;
        TreeNode<int> *max_node;
        while (nodesPending.size() != 0)
        {
            trav = nodesPending.front();
            nodesPending.pop();
            currSum = trav->data; // node itself

            //sum of the chilren
            for (int i = 0; i < trav->children.size(); i++)
            {
                currSum += trav->children.at(i)->data;
                nodesPending.push(trav->children.at(i));
            }

            // we need to hold sum to record it
            if (currSum > prevSum)
            {
                max_node = trav;
                prevSum = currSum;
            }
            // got the value for trav
        }
        return max_node;
    }

</details>

---

</details>

<details> <summary><strong> 4. Structurally identical </strong></summary>

# 4. Structurally identical

    Given two Generic trees, return true if they are structurally identical i.e. they are made of nodes with the same values arranged in the same way.

**Input Format**

    Line 1 : Tree 1 elements in level order form separated by space (as per done in class).
    Order is - Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

    Line 2 : Tree 2 elements in level order form separated by space (as per done in class).
    Order is - Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

**Output Format**

    true or false

**Constraints**

    Time Limit: 1 second
    Size of input array lies in the range: [1, 1000000]

**Sample Input 1**

    10 3 20 30 40 2 40 50 0 0 0 0
    10 3 20 30 40 2 40 50 0 0 0 0

**Sample Output 1**

    true

**Sample Input 2**

    10 3 20 30 40 2 40 50 0 0 0 0
    10 3 2 30 40 2 40 50 0 0 0 0

**Sample Output 2**

    false

<details> <summary><strong>Code</strong></summary>

    // Following is the Tree node structure
    /**************
    template <typename T>
    class TreeNode {
    public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };
    ***************/

    bool isIdentical(TreeNode<int> *root1, TreeNode<int> *root2)
    {
        // doing recursively
        // What is the thing which makes two trees identical?
        // A: Each corresponding node has the same property, assuming the corresponding nodes exist. i.e we don't run out of children.

        // observable quantities are
        // a. root->data
        // b. root->children.size()
        // a && b should be true for at all times

        if (root1 == NULL || root2 == NULL) // both or one is NULL
        {
            if (root1 == NULL && root2 == NULL) // both are NULL
                return true;
            return false; // only one of them is NULL
        }                 // both are non NULL

        // a. data must be equal
        if (root1->data != root2->data)
            return false;

        // b. data is the same but number of children vary
        if (root1->children.size() != root2->children.size())
            return false;

        // base case for recursion
        // data and size both are same and Leaf
        if (root1->children.size() == 0)
            return true;

        // we can write recursion directly, or can save some
        // activation records by checking the children
        // But this would be redundant to the base case. So avoiding it

        bool ret = false; // required coz we want to stop when a mismatch is found, we don't want to and every output, that is unrealistic

        for (int i = 0; i < root1->children.size() && ret == false; i++)
            ret = isIdentical(root1->children.at(i), root2->children.at(i));

        // if ret is found true it is returned
        // if nothing is found
        // then ret remains false, returned.
        return ret;
    }

</details>

---

</details>

<details> <summary><strong> 5. Next larger </strong></summary>

# 5. Next larger

    Given a generic tree and an integer n. Find and return the node with next larger element in the Tree i.e. find a node with value just greater than n.

    Return NULL if no node is present with the value greater than n.

**Input Format**

    Line 1 : Integer n
    Line 2 : Elements in level order form separated by space (as per done in class).
    Order is - Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

**Output Format**

    Node with value just greater than n.

**Sample Input 1**

    18
    10 3 20 30 40 2 40 50 0 0 0 0

**Sample Output 1**

    20

**Sample Input 2**

    21
    10 3 20 30 40 2 40 50 0 0 0 0

**Sample Output 2**

    30

<details> <summary><strong>Code</strong></summary>

    // Following is the given Tree node structure
    /**************

    template <typename T>
    class TreeNode {
    public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };
    ***************/
    #include <climits>
    #include <queue>
    TreeNode<int> *nextLargerElement(TreeNode<int> *root, int n)
    {
        // edge case
        if (root == NULL || root->children.size() == 0)
            return root;

        // scan element and store the max
        queue<TreeNode<int> *> nodesPending;

        int curr = 0, prev_max = INT_MAX; // for finding max
        TreeNode<int> *trav = root;       // optimization

        TreeNode<int> *ret; // node address to be returned

        // consider the root, as only children are a part of the queue process.
        // root is the child of none

        ret = root;
        if (root->data > n)
            prev_max = root->data;

        // have to push as to make it systematic for all nodes
        nodesPending.push(root);

        while (nodesPending.size() != 0)
        {
            trav = nodesPending.front();
            nodesPending.pop();
            for (int i = 0; i < trav->children.size(); i++)
            {
                curr = trav->children.at(i)->data; // child's data
                if (curr > n && curr < prev_max)
                {
                    prev_max = curr;
                    ret = trav->children.at(i); // store the child
                }
                nodesPending.push(trav->children.at(i));
                // pushing child node as subtree source in th queue
            }
        }
        // prev_max hols the maximum array
        // ret hold the node's address
        return ret;
    }

    // Insights: It is is very important to consider the root too.

</details>

---

</details>

<details> <summary><strong> 5. Next larger </strong></summary>

# 6. Second Largest Element In Tree

    Given a generic tree, find and return the node with second largest value in given tree. Return NULL if no node with required value is present.

**Input Format**

    Line 1 : Elements in level order form separated by space (as per done in class).
    Order is - Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

**Output Format**

    Second Largest node data

**Sample Input 1**

    10 3 20 30 40 2 40 50 0 0 0 0

**Sample Output 1**

    40

<details> <summary><strong>Code</strong></summary>

    // Following is the given Tree node structure
    /**************

        template <typename T>
        class TreeNode {
        public:
            T data;
            vector<TreeNode<T>*> children;

            TreeNode(T data) {
                this->data = data;
            }

            ~TreeNode() {
                for (int i = 0; i < children.size(); i++) {
                    delete children[i];
                }
            }
        };
        ***************/
    #include <queue>
    TreeNode<int> *secondLargest(TreeNode<int> *root)
    {
        if (root == NULL)
            return root;

        queue<TreeNode<int> *> nodesPending;

        nodesPending.push(root);

        int curr = root->data, max = root->data, max1 = root->data; //max1 > max1 always except initially
        // but no redundancy is present for pointers

        TreeNode<int> *trav;        // for the traversal variable
        TreeNode<int> *ret = NULL;  // for the 2nd highest node pointer
        TreeNode<int> *ret1 = NULL; // for highest node pointer

        while (nodesPending.size() != 0)
        {
            trav = nodesPending.front();
            nodesPending.pop();
            for (int i = 0; i < trav->children.size(); i++)
            {
                curr = trav->children.at(i)->data;
                if (curr > max1)
                {
                    max = max1;
                    max1 = curr;
                    ret = ret1;
                    ret1 = trav->children.at(i);
                }
                else if (curr > max)
                {
                    max = curr;
                    ret = trav->children.at(i);
                }
                nodesPending.push(trav->children.at(i));
            }
        }
        return ret;
    }

</details>

---

</details>

<details> <summary><strong> 5. Next larger </strong></summary>

# 7. Replace with depth

    In a given Generic Tree, replace each node with its depth value. You need to just update the data of each node, no need to return or print anything.

**Input Format**

    Line 1 : Elements in level order form separated by space (as per done in class).

    Order is - Root_data, n (No_Of_Child_Of_Root), n children, and so on for every element

**Sample Input 1**

    10 3 20 30 40 2 40 50 0 0 0 0

**Sample Output 1**

    0
    1 1 1
    2 2

<details> <summary><strong>Code</strong></summary>

    // Following is the given Tree node structure
    /**************
    template <typename T>
    class TreeNode {
    public:
        T data;
        vector<TreeNode<T>*> children;

        TreeNode(T data) {
            this->data = data;
        }

        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };
    ***************/

    void helper(TreeNode<int>* root, int d);
    void replaceWithDepthValue(TreeNode<int> *root)
    {
        // edge case
        if(root==NULL)
            return;
        root->data = 0;
        helper(root, 0);
    }

    void helper(TreeNode<int>* root, int d)
    {
        // do work only for the children
        if(root->children.size()==0)    //leaves have already been taken care of, as they were children
            return;

        for(int i=0; i<root->children.size(); i++)
        {
            root->children.at(i)->data = d+1;
            helper(root->children.at(i), d+1);
        }
        // okay
    }

</details>

---

</details>
