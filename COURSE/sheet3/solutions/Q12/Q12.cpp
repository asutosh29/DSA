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
Node *delete_at_ptr(Node *ptr);
void test_delete_at_ptr();

int main()
{
    test_delete_at_ptr();
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

Node *search(Node *head, int key)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        if (curr->data == key)
        {
            return curr;
        }
        curr = curr->next;
    }
    return curr;
}

// Copy temporary data from the next node to the current node, then delete the next node
Node *delete_at_ptr(Node *ptr)
{
    // if ptr is the last element, this approach can't be applied
    if (ptr->next == nullptr)
    {
        cout << "Can't delete last node!" << endl;
        return nullptr;
    }

    Node *temp = ptr->next;
    ptr->data = temp->data;
    ptr->next = temp->next;
    delete temp;
    return ptr;
}

void test_delete_at_ptr()
{
    Node *list = create();
    print(list);

    while (true)
    {
        cout << "Enter the element to delete (-99 to exit): ";
        int key;
        cin >> key;
        if (key == -99)
        {
            cout << "Exiting..." << endl;
            break;
        }

        Node *ptr = search(list, key);
        if (ptr == nullptr)
        {
            cout << "Key not found!" << endl;
            continue;
        }

        delete_at_ptr(ptr);
        print(list);
    }
}
