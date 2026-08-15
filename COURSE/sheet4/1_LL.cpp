#include <iostream>
using namespace std;

struct Node
{
    int data;
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
    Node *head;
    Stack()
    {
        this->top = nullptr;
        this->head = nullptr;
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

int pop(Stack *st)
{
    if (underflow(st))
    {
        cout << "Stack is empty" << endl;
        return -99;
    }
    int x = st->top->data;
    Node *temp = st->top;
    st->top = st->top->next;
    delete temp;
    return x;
}

void push(Stack *st, int x)
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

int main()
{
    Stack *st = create();
    __print(st);

    return 0;
}