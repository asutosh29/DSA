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
int count(Node *head);
void modify(Node *head);

int main()
{
    Node *head = create();
    print(head);
    cout << "Number of elements in list is: " << count(head) << endl;
    modify(head);

    cout << "list after modification: " << endl;
    print(head);

    return 0;
}

// builds the elements of the list recursively
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

// prints the elements of the list
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

// Returs the number of elements in the list
int count(Node *head)
{
    Node *ptr = head;
    int counter = 0;
    while (ptr != nullptr)
    {
        counter++;
        ptr = ptr->next;
    }
    return counter;
}

// Manipulates the record by index and value
void modify(Node *head)
{
    if (head == nullptr)
    {
        cout << "Empty list can't be modified!" << endl;
        return;
    }
    int n = count(head);
    while (true)
    {
        cout << "Enter index to modify (1 to " << n << ", 0 to exit): ";
        int index;
        cin >> index;
        if (index == 0)
        {
            cout << "Exiting modification..." << endl;
            return;
        }
        if (index < 1 || index > n)
        {
            cout << "Invalid index!" << endl;
            continue;
        }

        Node *ptr = head;
        for (int i = 1; i < index; i++)
        {
            ptr = ptr->next;
        }
        cout << "Current value at index " << index << " is " << ptr->data << endl;
        cout << "Enter new value: ";
        int temp;
        cin >> temp;
        ptr->data = temp;
        cout << "Updated!" << endl;
    }
}
