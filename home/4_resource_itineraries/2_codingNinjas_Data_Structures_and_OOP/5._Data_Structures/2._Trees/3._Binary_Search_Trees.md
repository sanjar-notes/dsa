# 3. Binary Search Trees
Created Friday 07 February 2020


* The simplest definition: A binary tree where all the nodes in the left **subtree** and smaller than the root and all the nodes in the **right subtree** are greater than the root. i.e the root specifies the max for the left subtree, and min for the right subtree. This is true for all nodes.
* We can use **duplicates too**, but make sure that the equality is decided for left or for right subtree(but not both).
* The subtree is very important. Merely having root->left->data < root->data && root->right->data > root->data is **wrong, **as it does not talk about the whole tree. Root decides the min and max for right and left respectively.


[Exercises.md](./3._Binary_Search_Trees/Quizzes&Exercises/Exercises.md)
[CodingExercises.md](./3._Binary_Search_Trees/Quizzes&Exercises/CodingExercises.md)
[Assignments.md](./3._Binary_Search_Trees/zAssignments/Assignments.md)

