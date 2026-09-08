# Specification: Infix to Postfix & Prefix Converter

Implement two conversion algorithms based on stack operations and verify them against reference test suites.

## 1. Operator Precedence & Associativity
* Exponentiation (`^` or `$`): Precedence 3 (Highest)
* Multiplication (`*`), Division (`/`): Precedence 2
* Addition (`+`), Subtraction (`-`): Precedence 1
* Parentheses (`(`, `)`): Boundaries (Lowest inside stack comparison)

---

## 2. Algorithm 1: Infix to Postfix
* **Signature**: `infix_to_postfix(expression: str) -> str`
* **Procedure**:
  1. Initialize an empty stack and push `(` onto it.
  2. Append `)` to the end of the input string.
  3. Scan the expression from left to right character by character:
     - If the token is alphanumeric (operand): append it to output string.
     - If the token is `(`: push it onto the stack.
     - If the token is an operator `op`:
       - Pop from stack to output while stack top is an operator with `precedence(stack_top) >= precedence(op)`.
       - Push `op` onto the stack.
     - If the token is `)`:
       - Pop from stack to output until `(` is reached.
       - Pop and discard `(`.
  4. Return the output string.

---

## 3. Algorithm 2: Infix to Prefix (Right-to-Left Scan)
* **Signature**: `infix_to_prefix(expression: str) -> str`
* **Procedure**:
  1. Initialize an empty stack and push `)` onto it.
  2. Prepend `(` to the beginning of the expression (scanned last when reading right-to-left).
  3. Scan the expression from right to left character by character:
     - If token is alphanumeric (operand): prepend it to output string (or insert at index 0).
     - If token is `)`: push it onto the stack.
     - If token is an operator `op`:
       - Pop from stack and prepend to output while stack top is an operator with `precedence(stack_top) >= precedence(op)`.
       - Push `op` onto the stack.
     - If token is `(`:
       - Pop from stack and prepend to output until `)` is reached.
       - Pop and discard `)`.
  4. Return the output string.

---

## 4. Test Suite for Verification

Verify your implementation with these test cases:

### Test Case 1
* **Infix**: `(A+B)*C-(D-E)*(F+G)`
* **Expected Postfix**: `AB+C*DE-FG+*-`
* **Expected Prefix**: `-*+ABC*-DE+FG`

### Test Case 2
* **Infix**: `((A+B)*C)`
* **Expected Postfix**: `AB+C*`
* **Expected Prefix**: `*+ABC`

### Test Case 3
* **Infix**: `A+(B*C-(D/E^F)*G)*H`
* **Expected Postfix**: `ABC*DEF^/G*-H*+`

### Test Case 4
* **Infix**: `(K+L-M*N+(O^P)*W/U/V*T+Q)`
* **Expected Postfix**: `KL+MN*-OP^W*U/V/T*+Q+`