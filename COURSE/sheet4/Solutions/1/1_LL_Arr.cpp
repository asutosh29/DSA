#include <iostream>
using namespace std;

const int NIL = -1;

struct Stack
{
    int size;
    int top;   // index of the top node (NIL = empty)
    int avail; // index of the first free node in the pool
    int *data;
    int *next_index;

    Stack(int sz)
    {
        size = sz;
        top = NIL;
        avail = 0;
        data = new int[size];
        next_index = new int[size];
        for (int i = 0; i < size - 1; i++)
            next_index[i] = i + 1;
        next_index[size - 1] = NIL;
    }
};

// checks if the stack is empty
bool underflow(Stack *st)
{
    return st->top == NIL;
}

// checks if the stack is full (no free node left in the pool)
bool overflow(Stack *st)
{
    return st->avail == NIL;
}

// equivalent of malloc: takes a node out of the free pool
int get_node(Stack *st)
{
    int node_index = st->avail;
    st->avail = st->next_index[st->avail];
    return node_index;
}

// equivalent of free: puts the node back into the free pool
void free_node(Stack *st, int index)
{
    st->next_index[index] = st->avail;
    st->avail = index;
}

// saves an item on top of the stack
void push(Stack *st, int x)
{
    if (overflow(st))
    {
        cout << "Stack is full! " << x << " was not pushed." << endl;
        return;
    }
    int idx = get_node(st);
    st->data[idx] = x;
    st->next_index[idx] = st->top;
    st->top = idx;
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
    int x = st->data[st->top];
    int temp = st->top;
    st->top = st->next_index[st->top];
    free_node(st, temp);
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
    for (int i = st->top; i != NIL; i = st->next_index[i])
        cout << st->data[i] << " ";
    cout << endl;
}

int main()
{
    int size;
    while (true)
    {
        cout << "Enter stack size (positive): ";
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
