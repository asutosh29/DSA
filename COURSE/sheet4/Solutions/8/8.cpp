#include <iostream>
using namespace std;

struct Stack
{
    int size;
    int top;
    int *S;
    Stack(int size)
    {
        this->size = size;
        this->top = -1;
        this->S = new int[size];
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

// retrieves the top item from the stack
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

// saves an item on top of the stack
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

// recursive Tower of Hanoi : moves n disks from the beg stack to the end stack
// using the aux stack
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

// fills the beg stack with n disks (largest at the bottom) and solves it
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
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    if (n <= 0)
    {
        cout << "Number of disks must be positive!" << endl;
        return 0;
    }

    test_tower(n);
    return 0;
}
