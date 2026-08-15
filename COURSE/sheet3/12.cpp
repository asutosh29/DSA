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
    };
    Node()
    {
        this->data = 0;
        this->next = nullptr;
    };
};

// LL Functions
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
Node *delete_at_ptr(Node *ptr);
void test_delete_at_ptr();
int main()
{
    test_delete_at_ptr();
    return 0;
}

Node *delete_at_ptr(Node *ptr)
{
    // Copy the next node into current node
    // Connect the current node to the next to next node (if exist, else to nullptr if last elem)
    // delete the next node.

    // if ptr is second last element then this approach can't be applied
    if (ptr->next == nullptr)
    {
        cout << "Can't delete last node!" << endl;
        return nullptr;
    }

    ptr->data = ptr->next->data;
    ptr->next = ptr->next->next;
    delete ptr->next;
    return ptr;
}

void test_delete_at_ptr()
{
    Node *list = create();
    print(list);

    cout << "Enter the element to delete (-99 to exit): ";
    int key;
    cin >> key;
    Node *ptr = search(list, key);
    while (ptr == nullptr && key != -99)
    {
        cout << "Key not found!" << endl;
        cout << "Enter the element to delete (-99 to exit): ";
        cin >> key;
        ptr = search(list, key);
    }

    if (key == -99)
    {
        return;
    }

    Node *curr = delete_at_ptr(ptr);
    print(list);
}
