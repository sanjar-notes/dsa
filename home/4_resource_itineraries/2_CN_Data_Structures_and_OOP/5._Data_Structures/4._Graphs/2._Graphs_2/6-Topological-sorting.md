---
tags:
  - graphs
  - topsort
---
# 6. Topological sorting
Created Wed Jul 17, 2024 at 11:16 AM

Source: https://youtu.be/eL-KzMXSXXI?si=vt6YhmMje70VjATv
## #DAG
DAG means a directed acyclic graph, i.e. a graph with no cycles.

Note:
- But doesn't this just mean a tree? no, the directions may be messed up (not all are down), compared to a tree.
- If we ignore the directions, would it be a tree? No, since its directed there could be undirected cycles.
- A tree is a DAG of course. But not all DAGs are trees.
- DAG is applicable to directed graphs only, of course.

## Topological sorting
This is the most important operation on DAGs.
A DAG may have multiple topological sortings. Any DAG has at least one.

### Applications
Many real world situations can be modeled
as a graph with directed edges 
where some events must occur before others.

- Program dependencies
- School class prerequisites
- Event scheduling
- Assembly instructions

Below: G must happen before A.
![](../../../../../../assets/6-Topological-sorting-image-1-1a642cda.png)

### What is topological sort (aka top sort)
![](../../../../../../assets/6-Topological-sorting-image-2-1a642cda.png)
The above is a fancy way to say the above: top sort is a way to arrange nodes linearly such that all edges are towards the right.

### Implies both ways (A <=> B)
A DAG always has a (atleast one) topological sort.
Also, a graph that has a topological sort is a DAG.


## Topological sort - algorithm
- Do a DFS
- When you find a new node, do the usual.
- When you are done with the nbrs of a node, store the node at the back on an array (this is global and of length V).

The array we have been maintaining is the topological sort. And in order, the leftmost has no parent.

### Why this works?
Remember that top sort means arranging nodes linearly and that all edges are towards the right.
What would be the rightmost node in this arrangement? well it would be a node that has no right edge.
w.r.t to a DAG this means a node that's at the end of a trail (long DFS trail). There could be multiple such nodes. Anyway, the second node would be the parent to the first node. So we know that we start populating the array in the recursion back phase, and also after being done with all neighbors (if we didn't, and inserted ourselves before a neighbor, we would have an edge to the left which would not be a topological sort).

## Using top sort
Lets take example of satisfying dependencies.
- To check feasibility - determine if the graph is DAG or not.
- Doing order (i.e. find an order) - Do work in the topological ordering (left to right). This works because when we arrive at a node, we its dependencies (that would have been to the left) have surely been completed.

## Code
https://leetcode.com/problems/course-schedule-ii/
Note that both cycle detect and topological sort can be done in one go.
```cpp
class Solution {
public:
    bool detectCycleAndCollect(int node, vector<vector<int>>& adj,
                               vector<int>& seen, vector<int>& bag) {
        if (seen[node] == 2) {
            // edge going to stable island is fine
            return false;
        }

        if (seen[node] == 1) {
            return true; // cycle (in current path)
        }

        seen[node] = 1; // current path

        for (auto nbr : adj[node]) {
            // parent is also a cycle so no check needed
            if (detectCycleAndCollect(nbr, adj, seen, bag))
                return true;
        }

        seen[node] = 2; // stable down the tree, so mark this too as stable
        bag.push_back(node);

        return false; // no cycles
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> bag;
        vector<vector<int>> adj(numCourses, vector<int>());
        vector<int> seen(numCourses,
                         0); // for cycle detect on a directed graph
        // we need to check if there's a seen element on the current trail
        // and also handle envelopes. so marking current trail is important
        // we can use a boolean definitely, but using a (0, 1, 2) will help
        // avoid unnecessary island traversal

        for (auto pair_ : prerequisites) {
            adj[pair_[0]].push_back(pair_[1]); // 0 needs 1
        }

        for (int i = 0; i < numCourses; i++) {
            // seen[i] == 2 can happen here, and that says its a stable island,
            // ignore seen[i] == 1 never happens, since we'd already ended the
            // algorithm
            if (seen[i] == 0 && detectCycleAndCollect(i, adj, seen, bag))
                return {}; // cycle found so return
        }

        return bag;
    }
};
```