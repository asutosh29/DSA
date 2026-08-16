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
Node *swap_k(Node *list, int k);

int main()
{
    Node *list = create();
    cout << "List: " << endl;
    print(list);

    while (true)
    {
        int k;
        cout << "Enter k to swap (-99 to exit): ";
        cin >> k;
        if (k == -99)
        {
            cout << "Exiting..." << endl;
            break;
        }
        cout << "swapping with k=" << k << endl;
        list = swap_k(list, k);
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

// Swap the kth node from the beginning with the kth node from the end
// k1 = kth node from the beginning
// k2 = kth node from the end
Node *swap_k(Node *list, int k)
{
    if (k < 1)
    {
        cout << "k must be at least 1!" << endl;
        return list;
    }
    Node *start = list;
    Node *end = list;
    for (int i = 0; i < k - 1; i++)
    {
        if (end == nullptr)
        {
            cout << "k is greater than length of the list!" << endl;
            return list;
        }
        end = end->next;
        if (end == nullptr)
        {
            cout << "k is greater than length of the list!" << endl;
            return list;
        }
    }

    Node *ptr1 = end;
    while (end != nullptr && end->next != nullptr)
    {
        start = start->next;
        end = end->next;
    }

    Node *ptr2 = start;
    int temp = ptr1->data;
    ptr1->data = ptr2->data;
    ptr2->data = temp;
    return list;
}