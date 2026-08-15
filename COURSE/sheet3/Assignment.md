# EEO-101: Data Structures — Worksheet 3 (Linked List)

**Department of Electrical Engineering**
**Indian Institute of Technology Roorkee, Roorkee**
**Autumn 2026–2027**

> **Important:** All functions must be implemented **twice** — once using the **linked array representation** and once using the **pointer representation**.

---

## Q1. Basic Linked List Operations

Write the following functions:

- `create()` — Create a linear linked list.
- `print()` — Print the above list.
- `count()` — Count the number of nodes in the above list.
- `modify()` — Manipulate the record of each node (design left up to you).

## Q2. Create a Sorted List

Write a function `create_sort()` which creates a **sorted list**. A single data item may be an `integer` or `float`, and each item is received from the standard input device. Print the resulting list.

## Q3. Search for a Key Item

Write a function to search for a key item in a linked list named `LIST`. The function receives a head pointer to the list and the key item, and returns a pointer to the record containing the key.

## Q4. Search with Previous Pointer

Modify the function from **Q3** so it also makes available, to the calling function, two pointers:

- A pointer to the **key node**.
- A pointer to the **node previous to** the key node.

## Q5. Insert After a Key Node

Write a function `insert_after()` which receives:

- A head pointer to the first node of a linear linked list of integer items.
- An integer data item to insert.
- A key item.

The function inserts the given integer data item **after** the node containing the given key.

## Q6. Insert Before a Key Node

Modify the function from **Q5** to create `insert_before()`, which inserts the integer data item **before** the key node instead of after.

## Q7. Insert at a Given Position

If the position `K` of the data item to be inserted is provided **instead of** a key item, modify the above function accordingly so that the data item is inserted as the **Kth node**.

## Q8. Insert into a Sorted List

Further modify the above function so that it receives the head pointer to a **sorted list** and a data item, and inserts the data item at its **appropriate place** in the sorted list (maintaining sort order).

## Q9. Josephus Problem

Write and test a function `Josephus()` to implement the Josephus problem using a linked list.

## Q10. Doubly Linked List Insertion

Write and test a function `insert_DLL()` to implement insertion in a **doubly linked list**. Incorporate **all variations** of insertion (at head, at tail, before a node, after a node, at a given position, etc.) and list them clearly.

## Q11. Intersection of Two Sorted Lists

Given two sorted linked lists, write a function to find their **intersection**.

## Q12. Delete a Given Node (No Head Pointer)

Write a function to delete a **given node** (a pointer to the node is provided), **without knowing the head pointer** of the list.

## Q13. Swap Kth Node from Beginning and End

Write a function to **swap** the `k`th node from the beginning with the `k`th node from the end of a given linked list.

## Q14. Count Occurrences of a Key

Write a function to find the **number of occurrences** of a given key data item in the linked list.

---

## Note

Test **all** of the above functions by writing a suitable `main()` program.