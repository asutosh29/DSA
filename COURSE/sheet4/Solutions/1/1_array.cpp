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

// saves an item on top of the stack
void push(Stack *st, int x)
{
    if (overflow(st))
    {
        cout << "Stack is full! " << x << " was not pushed." << endl;
        return;
    }
    st->top++;
    st->S[st->top] = x;
    cout << x << " pushed." << endl;
}

// retrieves the top item from the stack
int pop(Stack *st)
{
    if (underflow(st))
    {
        cout << "Stack is empty! Nothing to pop." << endl;
        return -99;
    }
    int x = st->S[st->top];
    st->top--;
    cout << x << " popped." << endl;
    return x;
}

// prints the stack contents from top to bottom
void print(Stack *st)
{
    if (underflow(st))
    {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack (top -> bottom): ";
    for (int i = st->top; i >= 0; i--)
        cout << st->S[i] << " ";
    cout << endl;
}

int main()
{
    int size;
    while (true)
    {
        cout << "Enter stack size (positive integer): ";
        cin >> size;
        if (size > 0)
            break;
        cout << "Invalid size!" << endl;
    }
    Stack *st = new Stack(size);

    while (true)
    {
        cout << "===================================" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Check underflow (empty?)" << endl;
        cout << "4. Check overflow (full?)" << endl;
        cout << "5. Print stack" << endl;
        cout << "99. Exit" << endl;
        cout << "Enter choice: ";
        int choice;
        cin >> choice;

        int x;
        switch (choice)
        {
        case 1:
            cout << "Enter element to push: ";
            cin >> x;
            push(st, x);
            print(st);
            break;
        case 2:
            pop(st);
            print(st);
            break;
        case 3:
            cout << "underflow() = " << (underflow(st) ? "true" : "false")
                 << " -> stack is " << (underflow(st) ? "empty" : "not empty") << endl;
            break;
        case 4:
            cout << "overflow() = " << (overflow(st) ? "true" : "false")
                 << " -> stack is " << (overflow(st) ? "full" : "not full") << endl;
            break;
        case 5:
            print(st);
            break;
        case 99:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
