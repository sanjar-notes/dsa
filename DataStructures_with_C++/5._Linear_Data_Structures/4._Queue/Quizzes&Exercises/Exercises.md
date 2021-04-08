# Lectures - 1. Queue Intro, 2. Queue using Array, 3. Queue using dynamic array

**1. Queue**

    A Queue is a ?

**Options**

    a. FIFO (First In First Out) list
    b. LIFO (Last In First Out) list
    c. Ordered array
    d. Linear tree

<details> <summary><strong>Correct Answer</strong></summary>

    b. FIFO (First In First Out) list.
    Reason: Basics

</details>

---

**2. Correct order**

    If the elements “p”, “q”, “r” and “s” are placed in a queue and are deleted one at a time, in what order will they be removed?

**Options**

    a. srqp
    b. pqrs
    c. srpq
    d. qrsp

<details> <summary><strong>Correct Answer</strong></summary>

    b. pqrs
    Reason: FIFO

</details>

---

**3. Insert element**

    In optimized linked list implementation of a queue, where does a new element be inserted?

**Options**

    a. At the head of linked list
    b. At the tail of the linked list
    c. At the centre position in the linked list
    d. None

<details> <summary><strong>Correct Answer</strong></summary>

    b. At the tail of the linked list
    Reason: Head has the head element, which needs to removed in O(1). And insertion has to be O(1) too.
    In a queue the entry and exit are two different points, so the tail is the only place where we can insert the new element.

</details>

---

**4. Worst case operation**

    In linked list implementation of queue, if only front pointer is maintained, which of the following operation take worst case time (i.e. O(n) )?

**Options**

    a. Insertion from rear
    b. Deletion from front
    c. Both
    d. None

<details> <summary><strong>Correct Answer</strong></summary>

    a. Insertion from rear
    Reason: For deleting the last node and to update the entry point, we need to traverse throughout the list.

</details>

---

**5. Insert in queue**

    In linked list implementation of a queue, front and rear pointers are tracked. Which of these pointers will change during an insertion into EMPTY queue?

**Options**

    a. Only front pointer
    b. Only rear pointer
    c. Both front and rear pointer
    d. None

<details> <summary><strong>Correct Answer</strong></summary>

    c. Both front and rear pointer
    Reason: Initially both are NULL, and for the first step, both will be pointing to head. Remember in LL implementaion of queue, the head points to the element, and the tail points to the element ready for insertion, hence we have to sit at the last element. This is what is specified in the interface.

</details>

---
