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
Node *insert_sorted(Node *head, int data);

int main()
{
    Node *list = create();
    if (list == nullptr)
    {
        cout << "List is empty!" << endl;
        cout << "Add elements to the list:" << endl;
    }
    else
    {
        cout << "List created: ";
        print(list);
    }

    while (true)
    {
        int data;
        cout << "Enter element to insert (-99 to exit): ";
        cin >> data;
        if (data == -99)
        {
            cout << "Exiting..." << endl;
            break;
        }

        list = insert_sorted(list, data);
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

// Inserts data into the sorted list maintaining ascending order
// Returns the (possibly new) head
Node *insert_sorted(Node *head, int data)
{
    Node *temp = new Node(data);
    if (head == nullptr || head->data >= data)
    {
        temp->next = head;
        head = temp;
        return head;
    }
    Node *curr = head;
    while (curr->next != nullptr && curr->next->data < data)
    {
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;
    return head;
}
