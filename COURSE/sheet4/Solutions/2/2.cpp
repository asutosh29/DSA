#include <iostream>
#include <cstring>
using namespace std;

struct Stack
{
    int size;
    int top;
    char *S;

    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->S = new char[size];
    }
};

// checks if the stack is empty
bool underflow(Stack *st)
{
    return st->top == -1;
}

// checks if the stack is full
bool overflow(Stack *st)
{
    return st->top == st->size - 1;
}

// saves an item on top of the stack
void push(Stack *st, char x)
{
    if (overflow(st))
    {
        cout << "Stack is full" << endl;
        return;
    }
    st->top++;
    st->S[st->top] = x;
}

// retrieves the top item from the stack
char pop(Stack *st)
{
    if (underflow(st))
    {
        cout << "Stack is empty" << endl;
        return '?';
    }
    char x = st->S[st->top];
    st->top--;
    return x;
}

// returns the top item without removing it
char stackTop(Stack *st)
{
    if (underflow(st))
    {
        return '?';
    }
    return st->S[st->top];
}

// performs one arithmetic operation
int calculate(char op, int x1, int x2)
{
    int result = 0;
    switch (op)
    {
    case '+':
        result = x1 + x2;
        break;
    case '-':
        result = x1 - x2;
        break;
    case '*':
        result = x1 * x2;
        break;
    case '/':
        result = x1 / x2;
        break;
    default:
        break;
    }
    return result;
}

// returns the precedence of an operator
int precedence(char op)
{
    if (op == '*' || op == '/')
        return 2;
    if (op == '+' || op == '-')
        return 1;
    return -1;
}

// is the character one of + - * / ?
bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// reverses a string in place
void reverseStr(char *str)
{
    int i = 0, j = strlen(str) - 1;
    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
}

// core shunting-yard conversion
// popOnEqual = true  -> left-associative  (used for postfix)
// popOnEqual = false -> right-associative (used for the reversed infix when building prefix)
// parentheses are handled here
char *convertToPostfix(char *infix, bool popOnEqual)
{
    Stack *st = new Stack(strlen(infix));
    char *output = new char[strlen(infix) + 1];
    int j = 0;
    int i = 0;
    while (infix[i] != '\0')
    {
        char c = infix[i];
        if (c >= '0' && c <= '9')
        {
            output[j++] = c;
        }
        else if (c == '(')
        {
            push(st, c);
        }
        else if (c == ')')
        {
            while (!underflow(st) && stackTop(st) != '(')
                output[j++] = pop(st);
            pop(st); // discard the '('
        }
        else if (isOperator(c))
        {
            while (!underflow(st) && stackTop(st) != '(')
            {
                char topOp = stackTop(st);
                if (precedence(c) < precedence(topOp) ||
                    (precedence(c) == precedence(topOp) && popOnEqual))
                    output[j++] = pop(st);
                else
                    break;
            }
            push(st, c);
        }
        i++;
    }
    while (!underflow(st))
    {
        output[j++] = pop(st);
    }
    output[j] = '\0';
    return output;
}

// converts an infix expression (single-digit operands) to postfix
char *Inf_T_postF(char *infix)
{
    return convertToPostfix(infix, true);
}

// converts an infix expression (single-digit operands) to prefix
char *Inf_T_preF(char *infix)
{
    char *rev = new char[strlen(infix) + 1];
    strcpy(rev, infix);
    // reverse and flip brackets
    reverseStr(rev);
    for (int i = 0; rev[i] != '\0'; i++)
    {
        if (rev[i] == '(')
            rev[i] = ')';
        else if (rev[i] == ')')
            rev[i] = '(';
    }
    // right-associative scan of the reversed infix gives a proper postfix
    char *pst = convertToPostfix(rev, false);
    reverseStr(pst);
    return pst;
}

// evaluates a postfix expression (single-digit operands)
int PostF_Eval(char *postfix)
{
    Stack *st = new Stack(strlen(postfix));
    int i = 0;
    while (postfix[i] != '\0')
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(st, postfix[i] - '0'); // store digits as their int value
            i++;
        }
        else
        {
            int x2 = pop(st);
            int x1 = pop(st);
            int result = calculate(postfix[i], x1, x2);
            push(st, result);
            i++;
        }
    }
    return stackTop(st);
}

// evaluates a prefix expression (single-digit operands)
int PreF_Eval(char *prefix)
{
    Stack *st = new Stack(strlen(prefix));
    int i = strlen(prefix) - 1;
    while (i >= 0)
    {
        if (prefix[i] >= '0' && prefix[i] <= '9')
        {
            push(st, prefix[i] - '0');
            i--;
        }
        else
        {
            int x1 = pop(st);
            int x2 = pop(st);
            int result = calculate(prefix[i], x1, x2);
            push(st, result);
            i--;
        }
    }
    return stackTop(st);
}

// checks whether an infix string is valid for this converter:
// single-digit operands, + - * / operators, parentheses, spaces
bool isValidInfix(char *infix)
{
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];
        bool ok = (c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' ||
                  c == '/' || c == '(' || c == ')' || c == ' ';
        if (!ok)
            return false;
    }
    return true;
}

int main()
{
    char infix[100];
    cout << "Enter an infix expression (single-digit operands, e.g. 1+2-3*9): ";
    cin.getline(infix, 100);

    if (!isValidInfix(infix))
    {
        cout << "Invalid input! Use (0-9), + - * / , parentheses, and spaces only (e.g. 1+2-3*9)" << endl;
        return 0;
    }

    char *postfix = Inf_T_postF(infix);
    cout << "Postfix: " << postfix << endl;
    cout << "Postfix value: " << PostF_Eval(postfix) << endl;

    char *prefix = Inf_T_preF(infix);
    cout << "Prefix: " << prefix << endl;
    cout << "Prefix value: " << PreF_Eval(prefix) << endl;
    return 0;
}
