#include <iostream>
#include<cstring>
using namespace std;

const int MAX_SIZE = 100;

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
    StackElement data[MAX_SIZE];
    HeteroStack()
    {
        this->top = -1;
    }
};

bool isFull(HeteroStack& stack)
{
    return stack.top == MAX_SIZE - 1;
}

bool isEmpty(HeteroStack& stack)
{
    return stack.top == -1;
}

void push(HeteroStack& stack, int data)
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

void push(HeteroStack& stack, float data)
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

void push(HeteroStack& stack, char *data)
{
    if (isFull(stack))
    {
        cout << "Stack Overflow" << endl;
        return;
    }
    stack.top++;
    StackElement elem;
    elem.type = TYPE_STRING;
    char* strCopy = new char[strlen(data) + 1];
    strcpy(strCopy, data);
    elem.value.stringVal = strCopy;
    stack.data[stack.top] = elem;
}

StackElement pop(HeteroStack& stack){
    if (isEmpty(stack)){
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

void printStack(HeteroStack& stack)
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

void test_stack()
{
    HeteroStack stack;
    push(stack, 5);
    push(stack, 3.14f);
    push(stack, "Hi there!");
    printStack(stack);

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
        delete[] poppedItem.value.stringVal; // Free the allocated memory for the string
        break;
    default:
        break;
    }

    printStack(stack);
}

int main()
{
    test_stack();
    return 0;
}