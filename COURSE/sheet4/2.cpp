#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    char data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    };
    Node()
    {
        this->data = 0;
        this->next = nullptr;
    };
};

struct Stack
{
    Node *top;
    Stack()
    {
        this->top = nullptr;
    }
};

bool underflow(Stack *st)
{
    if (st->top == nullptr)
    {
        return true;
    }

    return false;
}

bool overflow(Stack *st)
{
    Node *temp = new Node();
    if (temp == nullptr)
    {
        return true;
    }
    delete temp;
    return false;
}

char pop(Stack *st)
{
    if (underflow(st))
    {
        cout << "Stack is empty" << endl;
        return '?';
    }
    int x = st->top->data;
    Node *temp = st->top;
    st->top = st->top->next;
    delete temp;
    return x;
}

void push(Stack *st, char x)
{
    if (overflow(st))
    {
        cout << "Stack is full" << endl;
        return;
    }
    Node *newNode = new Node(x);
    newNode->next = st->top;
    st->top = newNode;
}

char stackTop(Stack *st)
{
    if (underflow(st))
    {
        return '?';
    }
    return st->top->data;
}
Stack *create()
{
    Stack *st = new Stack();
    while (!overflow(st))
    {
        cout << "Input Element: (-99 to exit): ";
        int elem;
        cin >> elem;
        if (elem == -99)
        {
            break;
        }
        push(st, elem);
    }
    return st;
}
Stack *create(int *nums, int n)
{
    Stack *st = new Stack();
    for (int i = 0; i < n; i++)
    {
        push(st, nums[i]);
    }
    return st;
}

void __print(Stack *st)
{
    Node *current = st->top;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "\n";
}

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

void reverse(char *str)
{
    int i = 0, j = strlen(str) - 1;
    while (i < j)
    {
        swap(str[i], str[j]);
        i++;
        j--;
    }
}

void flipBrackets(char *str)
{
    int i = 0, j = strlen(str) - 1;
    while (i < j)
    {

        if (str[i] == '(')
        {
            str[i] = ')';
        }
        if (str[i] == ')')
        {
            str[i] = '(';
        }
        i++;
        j--;
    }
}

int precedance(char op)
{
    if (op == '*' || op == '/')
    {
        return 2;
    }
    if (op == '+' || op == '-')
    {
        return 1;
    }
    // invalid operator
    cout << "invalid operator" << endl;
    return -1;
}

char *Inf_T_postF(char *infix)
{
    Stack *st = new Stack();
    char *postfix = new char[strlen(infix) + 1];
    int i = 0;
    int j = 0;
    while (infix[i] != '\0')
    {
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            postfix[j++] = infix[i++];
        }
        else
        {
            // Push to stack if higher precedance operator
            char top = stackTop(st);
            if (top == '?' || precedance(infix[i]) > precedance(top))
            {
                push(st, infix[i++]);
            }
            // Transfer into postfix if lesser precedance
            else
            {
                postfix[j++] = pop(st);
            }
        }
    }
    while (!underflow(st))
    {
        postfix[j++] = pop(st);
    }
    postfix[j] = '\0';
    return postfix;
}

int PostF_Eval(char *postfix)
{
    Stack *st = new Stack();
    int i = 0;
    while (postfix[i] != '\0')
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(st, postfix[i++]);
        }
        else
        {
            char x2 = pop(st) - '0';
            char x1 = pop(st) - '0';
            char op = postfix[i];
            int result = calculate(op, x1, x2);
            push(st, result);
            i++;
        }
    }
    return stackTop(st);
}

char *Inf_T_preF(char *infix)
{
    // Reverse the infix expression
    reverse(infix);
    flipBrackets(infix);
    // Convert to postfix
    char *pst = Inf_T_postF(infix);
    // Reverse the postfix expression to get prefix
    reverse(pst);
    reverse(infix); // undo reversal
    return pst;
}

int PreF_Eval(char *postfix)
{
    Stack *st = new Stack();
    int i = strlen(postfix) - 1;
    while (i >= 0)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(st, postfix[i--]);
        }
        else
        {
            char x1 = pop(st) - '0';
            char x2 = pop(st) - '0';
            char op = postfix[i];
            int result = calculate(op, x1, x2);
            push(st, result);
            i--;
        }
    }
    return stackTop(st);
}

int main()
{
    char infix[] = "1+2-3*9";
    cout << infix << endl;
    char *postfix = Inf_T_postF(infix);
    cout << postfix << endl;
    cout << PostF_Eval(postfix) << endl;
    cout << "---" << endl;
    cout << infix << endl;
    char *prefix = Inf_T_preF(infix);
    cout << prefix << endl;
    cout << PreF_Eval(prefix) << endl;
    return 0;
}