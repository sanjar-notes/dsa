# zAssignments
Created Wednesday 05 February 2020

Why do we use a queue?

* Because it shows us when to stop, and there's no such thing in a vector(required precomputation of the entire tree). Using vector is the same, except that we get a chanec to see our nodes.
* A queue takes up less space then a vector. O(n) in both the cases. But it is a difference of 50%.



* For level wise things do the following, make root and push null. When we hit null, we are done with pushing all the childre. So push a NULL.
* This way we can very easily do level wise stuff.
* This method is the **fastest** way to do this.
* Why don't we use the depth criteria? That can be done, but this is also a property of the system. Which we exploit here.


For choosing the data structure: Think about the fundamental operations and the philosophy. We can combine things.

* min and max are in the iostream class.


For minimizing work, we can return pair of objects when needed. So that we don't have to do work again and again. **Kind of a dynamic programming approach.**

 int diameterOfBinaryTree(TreeNode* root) 
{
return diameterOfBinaryTreehelper(root).first;
}
    
pair<int, int> diameterOfBinaryTreehelper(TreeNode* root) 
{
if(root==NULL)
{
pair<int, int> ret(0, 0);
return ret;
}
pair<int, int> dhleft = diameterOfBinaryTreehelper(root->left); 
pair<int, int> dhright = diameterOfBinaryTreehelper(root->right); 
        
// check if max diameter is > h1 + h2
// diameter = max(diameter1, diameter2, h1+h2)
// height = max
pair <int, int> ret;
ret.first = max(dhleft.first, max(dhright.first, dhleft.second+dhright.second));// diameter
ret.second = 1+max(dhleft.second, dhright.second);
return ret;
}

