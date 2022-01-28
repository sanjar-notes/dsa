# 3. Depth of a Node
Created Wednesday 29 January 2020

Depth: Level wise distance from root. 
hence depth(root) = 0.

* Height = depth + 1
* Depth is the level, starting from zero.


Q) Print all node at depth d.
A) Recursion for 95 %. Whenever is seems intractable, use what we know. 
f(k, root) = for i in root.children:
f(k-1, root->children.at(i));
if(k==0)
cout << root->data << " ";
// if it is a leaf node for is not executed. Returned.
	
for(int i=0; i < root->children.size(); i++)
f(root->children.at(i), k-1);


* Doubt: Can we ever have a negative value, no, because 
	1. If we reach a leaf midway(i.e cannot go further), the for loop is not executed, hence we return without making any further calls
	2. If we don't reach a leaf, we print and then return at k ==0.  i.e this is a **controlled recursion.**
* Tip: We may have a an edge case where k is passed as negative.


