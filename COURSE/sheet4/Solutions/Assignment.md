# EEO-101: Data Structures — Worksheet 4 (Stack)
**Department of Electrical Engineering, IIT Roorkee — Autumn 2026-2027**

## Tasks

1. Write functions to implement the following operations w.r.t. a **Stack**:
   - `underflow()` — To check if the stack is empty
   - `overflow()` — To check if the stack is full
   - `push()` — To save a single item on the stack
   - `pop()` — To retrieve a single item from the stack

   Implement these when the stack is represented by:
   - (i) Linear array
   - (ii) Dynamic variable representation as a linked list
   - (iii) Linked array representation

2. Write a function `INF_T_PostF()` which converts a given **infix** expression to its equivalent **postfix** expression.

3. Write a function `PostFE_Value()` which receives a postfix expression as input and returns its value.

4. Write a function `INF_T_PreF()` which converts a given **infix** expression to its equivalent **prefix** expression.

5. Write a function `PreFE_Value()` which receives a prefix expression as input and returns its value.

6. Write a **main program** that receives an infix expression and, using the functions from tasks 2 & 4 (and their value functions), computes its value.

7. Define a stack that can store data items whose data type may vary from time to time (a **heterogeneous stack**). Write functions to implement `push` and `pop` for such a stack, and test these functions.

8. Write a function `Tower()` to demonstrate the **Tower of Hanoi** problem using **recursion**.

9. Write a **non-recursive** function `Tower_NR()` to implement the Towers of Hanoi problem.

10. Write a function `QUICKSORT()` implementing the **Quicksort algorithm** to sort a given array. The function should receive a flag `ORDER` indicating sort order and handle accordingly:
    - `ORDER = 0` → Ascending
    - `ORDER = 1` → Descending

**Note:** Test all the above functions by writing a suitable main program.