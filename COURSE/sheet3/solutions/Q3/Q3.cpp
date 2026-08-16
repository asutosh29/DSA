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

Node *create();
void print(Node *head);
Node *search(Node *head, int key);

int main()
{
    Node *list = create();
    cout << "List: ";
    print(list);

    while (true)
    {
        int input;
        cout << "Enter element to search (-99 to cancel): ";
        cin >> input;
        if (input == -99)
        {
            break;
        }

        Node *loc = search(list, input);
        if (loc == nullptr)
        {
            cout << "Element not found!" << endl;
            continue;
        }
        cout << loc->data << " found at address " << loc << "!" << endl;
    }
    return 0;
}

// Creates a linear linked list from standard input
// Input stops when -99 is entered
Node *create()
{
    int temp;
    cout << "Input node (-99 to quit): ";
    cin >> temp;
    if (temp == -99)
    {
        return nullptr;
    }
    Node *current = new Node(temp);
    current->next = create();
    return current;
}

void print(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Returns a pointer to the first node whose data equals key,
// or nullptr if the key is not present in the list
Node *search(Node *head, int key)
{
    Node *ptr = head;

    while (ptr != nullptr)
    {
        if (ptr->data == key)
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return nullptr;
}
