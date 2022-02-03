# 3. Hussain Set
Created Monday 04 May 2020


* Using priority queue, O(N) space, heapify, O(NlogN), O(QlogN) time for queries.
* Another solution is to sort the set and use a normal queue.
	1. To get the maxium element, we'll the end of our array and queue.front()
	2. We'll take the maximum, and then insert in the queue if it is greater than 0.
	3. Max will always be at the start of our queue, coz, if a>b then a/2>b/2. If not we discard the value out of the system.
	4. T.C = O(NlogN) + O(Q)
	5. Space O(N)

Lesson Learnt: First try to make a solution, and then use a data structure.
exit

