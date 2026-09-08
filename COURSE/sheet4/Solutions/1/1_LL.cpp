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
    }
    Node()
    {
        this->data = 0;
        this->next = nullptr;
    }
};

struct Stack
{
    Node *top;
    Stack()
    {
        this->top = nullptr;
    }
};

// checks if the stack is empty
bool underflow(Stack *st)
{
    return st->top == nullptr;
}

// checks if the stack is full (a dynamic stack is full only if no memory is left)
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

// saves an item on top of the stack
void push(Stack *st, int x)
{
    if (overflow(st))
    {
        cout << "Stack is full! " << x << " was not pushed." << endl;
        return;
    }
    Node *newNode = new Node(x);
    newNode->next = st->top;
    st->top = newNode;
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
    int x = st->top->data;
    Node *temp = st->top;
    st->top = st->top->next;
    delete temp;
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
    Node *current = st->top;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main()
{
    Stack *st = new Stack();

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
