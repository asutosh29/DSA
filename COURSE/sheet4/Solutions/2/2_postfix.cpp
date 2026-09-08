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

// infix -> postfix : left-to-right scan.
// an operator is popped to the output while the stack top has precedence >= it
char *Inf_T_postF(char *infix)
{
    Stack *st = new Stack(strlen(infix) + 1);
    char *postfix = new char[strlen(infix) + 1];
    int j = 0;
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];
        if (c >= '0' && c <= '9')
        {
            postfix[j++] = c;
        }
        else if (isOperator(c))
        {
            while (!underflow(st) && precedence(stackTop(st)) >= precedence(c))
                postfix[j++] = pop(st);
            push(st, c);
        }
    }
    while (!underflow(st))
    {
        postfix[j++] = pop(st);
    }
    postfix[j] = '\0';
    return postfix;
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
            push(st, postfix[i] - '0');
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

// checks whether an infix string is valid:
// single-digit operands, + - * / operators, and spaces only
bool isValidInfix(char *infix)
{
    for (int i = 0; infix[i] != '\0'; i++)
    {
        char c = infix[i];
        bool ok = (c >= '0' && c <= '9') || c == '+' || c == '-' || c == '*' ||
                  c == '/' || c == ' ';
        if (!ok)
            return false;
    }
    return true;
}

int main()
{
    char infix[100];
    cout << "Enter an infix expression (single-digit operands, e.g. 1+2-3*9):\n";
    cin.getline(infix, 100);

    if (!isValidInfix(infix))
    {
        cout << "Invalid input! Use (0-9), + - * / and spaces only (e.g. 1+2-3*9)" << endl;
        return 0;
    }

    char *postfix = Inf_T_postF(infix);
    cout << "Postfix: " << postfix << endl;
    cout << "Postfix value: " << PostF_Eval(postfix) << endl;
    return 0;
}
