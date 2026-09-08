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

char *Inf_T_preF(char *infix)
{
    int n = strlen(infix);

    // reversed copy of the infix
    char *rev = new char[n + 1];
    for (int i = 0; i < n; i++)
        rev[i] = infix[n - 1 - i];
    rev[n] = '\0';

    Stack *st = new Stack(n + 1);
    char *pref = new char[n + 1];
    int j = 0;
    for (int i = 0; rev[i] != '\0'; i++)
    {
        char c = rev[i];
        if (c >= '0' && c <= '9')
        {
            pref[j++] = c;
        }
        else if (isOperator(c))
        {
            while (!underflow(st) && precedence(stackTop(st)) > precedence(c))
                pref[j++] = pop(st);
            push(st, c);
        }
    }
    while (!underflow(st))
    {
        pref[j++] = pop(st);
    }
    pref[j] = '\0';

    // reverse the collected string to get the prefix expression
    for (int a = 0, b = j - 1; a < b; a++, b--)
    {
        swap(pref[a], pref[b]);
    }
    return pref;
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

    char *prefix = Inf_T_preF(infix);
    cout << "Prefix: " << prefix << endl;
    cout << "Prefix value: " << PreF_Eval(prefix) << endl;
    return 0;
}
