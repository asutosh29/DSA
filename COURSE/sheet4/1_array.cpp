#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *S;
    Stack(int size)
    {
        if (size <= 0)
        {
            cout << "Invalid size" << endl;
            return;
        }
        this->size = size;
        this->top = -1;
        this->S = new int[size];
    }
};

bool underflow(Stack *st)
{
    if (st->top == -1)
    {
        return true;
    }

    return false;
}

bool overflow(Stack *st)
{
    if (st->top == st->size - 1)
    {
        return true;
    }
    return false;
}

int pop(Stack *st)
{
    if (underflow(st))
    {
        cout << "Stack is empty" << endl;
        return -99;
    }
    int x = st->S[st->top];
    st->top--;
    return x;
}

void push(Stack *st, int x)
{
    if (overflow(st))
    {
        cout << "Stack is full" << endl;
        return;
    }
    st->top++;
    st->S[st->top] = x;
}

Stack *create()
{
    cout << "Stack size: ";
    int size;
    cin >> size;
    if (size <= 0)
    {
        cout << "Invalid size\n";
        return nullptr;
    }
    Stack *st = new Stack(size);

    while (!overflow(st))
    {
        cout << "Input Element: (-99 to exit): ";
        int elem;
        cin >> elem;

        push(st, elem);
    }

    return st;
}

void __print(Stack *st)
{
    for (int i = 0; i < st->size; i++)
    {
        cout << st->S[i] << " ";
    }
    cout << "\n";
}

int main()
{
    Stack *st = create();
    __print(st);

    return 0;
}