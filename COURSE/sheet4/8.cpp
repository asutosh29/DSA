#include <iostream>
#include<cstring>
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

void Tower(int n, Stack *beg, Stack *end, Stack *aux)
{
    // base case
    if (n == 1)
    {
        int x = pop(beg);
        push(end, x);
        cout << "Moved " << x << " from beg to end" << endl;
        return;
    }

    Tower(n - 1, beg, aux, end);
    int x = pop(beg);
    push(end, x);
    cout << "Moved " << x << " from beg to end" << endl;
    Tower(n - 1, aux, end, beg);
}

void test_tower(int n)
{
    Stack *beg = new Stack(n);
    Stack *end = new Stack(n);
    Stack *aux = new Stack(n);

    for (int i = n; i >= 1; i--)
    {
        push(beg, i);
    }

    Tower(n, beg, end, aux);
}

int main()
{
    test_tower(3);
    return 0;
}