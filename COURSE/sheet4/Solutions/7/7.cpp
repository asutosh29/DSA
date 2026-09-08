#include <iostream>
#include <cstring>
using namespace std;

enum ItemType
{
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_STRING,
};

union StackData
{
    int intVal;
    float floatVal;
    char *stringVal;
};

struct StackElement
{
    ItemType type;
    StackData value;
};

struct HeteroStack
{
    int top;
    int size;
    StackElement *data;
    HeteroStack(int size)
    {
        this->top = -1;
        this->size = size;
        this->data = new StackElement[size];
    }
};

// checks if the heterogeneous stack is full
bool isFull(HeteroStack &stack)
{
    return stack.top == stack.size - 1;
}

// checks if the heterogeneous stack is empty
bool isEmpty(HeteroStack &stack)
{
    return stack.top == -1;
}

// saves an int item on top of the stack
void push(HeteroStack &stack, int data)
{
    if (isFull(stack))
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    stack.top++;
    StackElement elem;
    elem.type = TYPE_INT;
    elem.value.intVal = data;
    stack.data[stack.top] = elem;
}

// saves a float item on top of the stack
void push(HeteroStack &stack, float data)
{
    if (isFull(stack))
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    stack.top++;
    StackElement elem;
    elem.type = TYPE_FLOAT;
    elem.value.floatVal = data;
    stack.data[stack.top] = elem;
}

// saves a string item on top of the stack
void push(HeteroStack &stack, char *data)
{
    if (isFull(stack))
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    stack.top++;
    StackElement elem;
    elem.type = TYPE_STRING;
    char *strCopy = new char[strlen(data) + 1];
    strcpy(strCopy, data);
    elem.value.stringVal = strCopy;
    stack.data[stack.top] = elem;
}

// retrieves the top item from the stack
StackElement pop(HeteroStack &stack)
{
    if (isEmpty(stack))
    {
        cout << "Stack Underflow" << endl;
        StackElement emptyElem;
        emptyElem.type = TYPE_INT;
        emptyElem.value.intVal = 0;
        return emptyElem;
    }
    StackElement item = stack.data[stack.top];
    stack.top--;
    return item;
}

// prints the stack contents from top to bottom
void printStack(HeteroStack &stack)
{
    if (isEmpty(stack))
    {
        cout << "Stack is empty" << endl;
        return;
    }
    for (int i = stack.top; i >= 0; i--)
    {
        switch (stack.data[i].type)
        {
        case TYPE_INT:
            cout << stack.data[i].value.intVal << " ";
            break;
        case TYPE_FLOAT:
            cout << stack.data[i].value.floatVal << " ";
            break;
        case TYPE_STRING:
            cout << stack.data[i].value.stringVal << " ";
            break;
        default:
            break;
        }
    }
    cout << endl;
}

int main()
{
    int size;
    cout << "Enter stack capacity: ";
    cin >> size;
    if (size < 1)
    {
        cout << "Invalid capacity!" << endl;
        return 0;
    }
    HeteroStack stack(size);

    while (true)
    {
        cout << "===================================" << endl;
        cout << "1. Push int" << endl;
        cout << "2. Push float" << endl;
        cout << "3. Push string" << endl;
        cout << "4. Pop" << endl;
        cout << "5. Check if empty" << endl;
        cout << "6. Check if full" << endl;
        cout << "99. Exit" << endl;
        cout << "Enter choice: ";
        int choice;
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int x;
            cout << "Enter int to push: ";
            cin >> x;
            push(stack, x);
            printStack(stack);
            break;
        }
        case 2:
        {
            float x;
            cout << "Enter float to push: ";
            cin >> x;
            push(stack, x);
            printStack(stack);
            break;
        }
        case 3:
        {
            char x[100];
            cout << "Enter string to push: ";
            cin >> x;
            push(stack, x);
            printStack(stack);
            break;
        }
        case 4:
        {
            if (isEmpty(stack))
            {
                pop(stack);
                break;
            }
            StackElement poppedItem = pop(stack);
            cout << "Popped item: ";
            switch (poppedItem.type)
            {
            case TYPE_INT:
                cout << poppedItem.value.intVal << endl;
                break;
            case TYPE_FLOAT:
                cout << poppedItem.value.floatVal << endl;
                break;
            case TYPE_STRING:
                cout << poppedItem.value.stringVal << endl;
                delete[] poppedItem.value.stringVal;
                break;
            default:
                break;
            }
            printStack(stack);
            break;
        }
        case 5:
            cout << "isEmpty() = " << (isEmpty(stack) ? "true" : "false")
                 << " -> stack is " << (isEmpty(stack) ? "empty" : "not empty") << endl;
            break;
        case 6:
            cout << "isFull() = " << (isFull(stack) ? "true" : "false")
                 << " -> stack is " << (isFull(stack) ? "full" : "not full") << endl;
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
