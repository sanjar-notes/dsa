# 1. Pre and In
Created Saturday 01 February 2020

Pre has the first element as the root. **Root finder**
In has all left to the root as left subtree. **Space segregator.**

Are both needed, yes. Why?

1. Root finder helps find nodes.
2. Space segregator helps in giving them correct left and right subtrees.

1 and 2 are sufficient for making the tree.
Removing any of these, makes the construction impossible(due to muliple different having the same 1 or 2). 
Hence 1 and 2 are necessary.

Proof by contradiction.
Proved: 1 and 2 are necessary and sufficient for a unique tree, as each step of the recursion is unique for all trees, a yielding unique tree. 

// This is the best way, coz we get a node at each activation record. Which the best any algorithm can do. It has to be recursive as we need to work on more than one level.

**Caveat: No duplicate nodes should be present when using this method.**
 Code in exercise no.
