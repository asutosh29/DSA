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
int count(Node *list, int key);

int main()
{
    Node *list = create();
    cout << "List: " << endl;
    print(list);
    while (true)
    {
        int choice;
        cout << "Input element: (-99 to quit): ";
        cin >> choice;
        if (choice == -99)
            break;
        cout << "Count of element " << choice << " : " << count(list, choice) << endl;
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

// Counts how many times key appears in the list
int count(Node *list, int key)
{
    int count = 0;
    Node *ptr = list;
    while (ptr != nullptr)
    {
        if (ptr->data == key)
            count++;
        ptr = ptr->next;
    }
    return count;
}
