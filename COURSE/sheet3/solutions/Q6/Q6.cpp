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
Node *insert_before(Node *head, int data, int key);

int main()
{
    Node *list = create();
    if (list == nullptr)
    {
        cout << "List is empty!" << endl;
        return 0;
    }
    else
    {
        cout << "List created: ";
        print(list);
    }

    while (true)
    {
        int data, key;
        cout << "Enter element to insert (-99 to exit): ";
        cin >> data;
        if (data == -99)
        {
            cout << "Exiting..." << endl;
            break;
        }
        cout << "Input key before which element is to be inserted: ";
        cin >> key;

        list = insert_before(list, data, key);
        print(list);
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

// Inserts the integer data item immediately before the node
// whose data equals key. Returns the (possibly new) head
Node *insert_before(Node *head, int data, int key)
{
    // empty list
    if (head == nullptr)
    {
        cout << "Provided list is empty!" << endl;
        return nullptr;
    }
    Node *ptr = head;
    Node *prev = nullptr;
    while (ptr != nullptr)
    {
        if (ptr->data == key)
        {
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    if (ptr == nullptr)
    {
        cout << "Key not found!" << endl;
        return head;
    }

    Node *temp = new Node(data);
    // Key node is the first node
    if (prev == nullptr)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        temp->next = ptr;
        prev->next = temp;
    }
    return head;
}
