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
Node *insert_at_kth(Node *head, int data, int index);

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
        int data, k;
        cout << "Enter element to insert (-99 to exit): ";
        cin >> data;
        if (data == -99)
        {
            cout << "Exiting..." << endl;
            break;
        }
        cout << "Input position k at which element is to be inserted: ";
        cin >> k;

        list = insert_at_kth(list, data, k);
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

// Inserts data so that it becomes the index-th node (1-based)
// Returns the (possibly new) head
Node *insert_at_kth(Node *head, int data, int index)
{
    if (index < 1)
    {
        cout << "Invalid position!" << endl;
        return head;
    }
    Node *temp = new Node(data);
    if (index == 1)
    {
        temp->next = head;
        head = temp;
        return head;
    }
    Node *ptr = head;
    for (int i = 1; i < index - 1 && ptr != nullptr; i++)
    {
        ptr = ptr->next;
    }
    if (ptr == nullptr)
    {
        cout << "Position exceeds list length!" << endl;
        delete temp;
        return head;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    cout << "Inserted element " << data << " at index " << index << endl;
    return head;
}
