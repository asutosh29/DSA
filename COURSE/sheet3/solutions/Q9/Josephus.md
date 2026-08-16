# Josephus Problem — Algorithm Specification (Circular Linked List)

## 1. Problem Statement

A group of soldiers is surrounded with no hope of survival except for one horse.
They form a circle and pick a number `n` from a hat. Starting from a chosen
soldier, they count clockwise around the circle. Every time the count reaches
`n`, that soldier is eliminated (removed from the circle) and counting restarts
from the next soldier. Eliminated soldiers are no longer counted. This repeats
until only one soldier remains — that soldier takes the horse and escapes.

**Goal:** Given a list of names, a starting name, and a count `n`, determine
the order of elimination and the final survivor.

### Worked example (n = 5, 10 soldiers)
Elimination order: 5, 2, 4, 3, 1, 6, 3(dup shown visually as position), 7, 8, 9, 10 →
survivor is the soldier at the position marked with the green check in the
original diagrams (10th elimination round leaves one survivor). The exact
elimination sequence depends on circle order and starting point — see
Algorithm section for the general procedure.

## 2. Data Structure

Use a **circular singly linked list** (no header/sentinel node needed) with a
node per soldier:

```c
struct c_list {
    char info[20];          // soldier's name
    struct c_list *next;    // pointer to next soldier in the circle
};
typedef struct c_list node;
```

- The list is circular: the `next` pointer of the last-inserted node eventually
  points back to the first node.
- A single external pointer (e.g. `list`) tracks the **last node inserted**,
  so that `list->next` is always the **first (head) node** — this makes
  "insert at end" O(1) without a separate tail pointer.

## 3. High-Level Algorithm

```
1. CREATE the circular linked list from soldier names:
   a. Read name
   b. WHILE name != "end":
        i.   Insert name into circular list
        ii.  Read next name
2. READ the starting soldier's name and the value of n
3. SEARCH the circular list for the node BEFORE the starting node:
   Find ptr such that ptr->next->info == starting name
4. REPEAT while more than one node remains in the list:
   a. Starting from ptr->next, advance the pointer (n - 1) times
      (this counts n-1 nodes, landing on the node BEFORE the nth soldier)
   b. Display the name of the nth node (ptr->next after advancing)
   c. Delete the nth node from the circular list
5. Display the name of the single remaining node — this is the survivor
```

## 4. Detailed Sub-Algorithms

### 4.1 `insert(list, name)` — Insert a new node at the end of circular list
Three cases:

**Case 1 — Empty list (first node):**
```
new = getnode()
new->info = name
if (*list == NULL):
    *list = new
    new->next = new          // points to itself
```

**Case 2 — One node in list:**
```
t = (*list)->next            // = *list itself (self loop)
(*list)->next = new
new->next = t
*list = new                  // list pointer now tracks newest node
```

**Case 3 — General (n-th node insertion), same logic as Case 2:**
```
t = (*list)->next            // old first node
(*list)->next = new          // old last node -> new node
new->next = t                // new node -> old first node
*list = new                  // list now points to newest last node
```
(Cases 2 and 3 are actually identical code — inserting right after `*list`
and re-pointing `*list` to the new node keeps `list->next` as the head.)

### 4.2 `find(list, name)` — Locate node preceding the target
Returns pointer `ptr` such that `ptr->next->info == name`.
```
ptr = list
while (ptr->next != list):        // traverse whole circle
    if (ptr->next->info == name):
        return ptr                 // found
    ptr = ptr->next
return NULL                        // name not found (checked once more for list itself if needed)
```

### 4.3 `delete_after(ptr)` — Remove the node after `ptr`
```
t = ptr->next
ptr->next = ptr->next->next
free(t)
```

## 5. Full Elimination Loop (core Josephus logic)

```
ptr = find(list, start_name)        // ptr->next is the starting soldier

while (ptr->next != ptr):           // more than one node remains
    for i = 1 to n-1:
        ptr = ptr->next             // count n-1 nodes forward
    delete_after(ptr)               // eliminate the nth node
    // (implicitly, ptr->next now becomes the new "next to count from")

print ptr->next->info               // the single remaining node = survivor
```

Notes on the loop invariant:
- `ptr` always trails one node behind the "current counting position" so that
  `delete_after(ptr)` can remove the counted node in O(1) without needing a
  doubly linked list.
- After deletion, `ptr->next` automatically becomes the node that follows the
  eliminated one — counting resumes from there.
- Termination condition: loop continues **while more than one node remains**,
  i.e. `ptr->next != ptr` (a node pointing to itself means only one node left).

## 6. Flowchart Summary (for reference)

```
[Start]
   -> Read Name -> Insert into circular list -> repeat until "end"
   -> Read starting Name and n
   -> Search circular list: ptr->next->info == Name  (ptr = predecessor)
   -> LOOP:
        Count n-1 nodes forward from ptr->next
        Display name at nth node
        Delete nth node
        IF more than 1 node remains -> repeat LOOP
        ELSE -> Display remaining node's name -> [End]
```

## 7. Complexity
- **Time:** O(k × n) where `k` = number of soldiers and `n` = count value
  (each elimination requires traversing up to `n` nodes).
- **Space:** O(k) for the circular linked list.

## 8. Task for the Next Agent
Implement the above algorithm (in any language) with:
1. A circular linked list node structure as described in §2.
2. Functions: `insert`, `find`, `delete_after` (or `deleteAfter`).
3. A `josephus(names, start_name, n)` function implementing the loop in §5,
   returning:
   - The **elimination order** (list of names in the order removed), and
   - The **final survivor's name**.
4. Include a test case matching the lecture example: 10 soldiers arranged in
   a circle, `n = 5`, starting from a given soldier — verify against the
   elimination sequence shown in the source diagrams (5, 2, 4, 3, 1, 6, 7,
   8, 9, then the survivor at position 10 in the count).