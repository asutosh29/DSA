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
Node *intersect_sorted_list(Node *L1, Node *L2);

int main()
{
    cout << "Input first sorted List:" << endl;
    Node *L1 = create();
    print(L1);

    cout << "Input second sorted List:" << endl;
    Node *L2 = create();
    print(L2);

    cout << "Computing intersection..." << endl;
    Node *merged = intersect_sorted_list(L1, L2);
    print(merged);

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

// Both lists are sorted ascending. 
// The two pointers c1 and c2 traverse the two lists.
// If the two nodes are equal, we add it to the new list.
Node *intersect_sorted_list(Node *L1, Node *L2)
{
    Node *c1 = L1;
    Node *c2 = L2;
    Node *head = nullptr;
    Node *c3 = head;
    while (c1 != nullptr && c2 != nullptr)
    {
        if (c1->data == c2->data)
        {
            Node *temp = new Node(c1->data);
            if (head == nullptr)
            {
                head = temp;
                c3 = temp;
            }
            else
            {
                c3->next = temp;
                c3 = temp;
            }
            c1 = c1->next;
            c2 = c2->next;
        }
        else if (c1->data > c2->data)
        {
            c2 = c2->next;
        }
        else
        {
            c1 = c1->next;
        }
    }
    return head;
}
