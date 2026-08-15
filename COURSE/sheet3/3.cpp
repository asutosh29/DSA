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

Node *search(Node *head, int key);

int main()
{

    Node *list = create();

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
        cout << loc->data << " found!" << endl;
    }
    return 0;
}

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