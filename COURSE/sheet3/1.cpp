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

Node *create();
void print(Node *head);
int count(Node *head);
void modify(Node *head);
Node *bubble_sort(Node *head);

int main()
{
    Node *head = create();
    print(head);
    cout << "Number of elements in list is: " << count(head) << endl;
    modify(head);

    cout << "list after modification: " << endl;
    print(head);

    bubble_sort(head);
    cout << "list after sort: " << endl;
    print(head);

    return 0;
}

Node *create()
{
    int temp;
    cout << "Input node (-99 to quit): ";
    cin >> temp;
    cout << endl;
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

void modify(Node *head)
{
    if (head == nullptr)
    {
        cout << "Empty list can't be modified!" << endl;
        return;
    }
    Node *ptr = head;
    int index = 1;
    while (ptr != nullptr)
    {
        cout << "Current value at index " << index << " is " << ptr->data << endl;
        cout << "Enter new value (-99 to skip, -999 to terminate): " << endl;
        int temp;
        cin >> temp;
        if (temp == -99)
        {
            cout << "Skipping..." << endl;
            ptr = ptr->next;
        }
        else if (temp == -999)
        {
            cout << "Exiting modification..." << endl;
            return;
        }
        else
        {
            ptr->data = temp;
            ptr = ptr->next;
        }
    }
}

void swap(Node *a, Node *b)
{
    int temp = b->data;
    b->data = a->data;
    a->data = temp;
}

Node *bubble_sort(Node *head)
{
    Node *ptr = head;
    if (ptr == nullptr)
        return head;
    int size = count(head);
    for (int i = 0; i < size - 1; i++)
    {
        ptr = head;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (ptr->data > ptr->next->data)
            {
                swap(ptr, ptr->next);
            }
            ptr = ptr->next;
        }
    }

    return head;
}