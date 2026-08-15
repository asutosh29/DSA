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

Node *swap_k(Node *list, int k)
{
    Node *start = list;
    Node *end = list;
    for (int i = 0; i < k - 1; i++)
    {
        if (end == nullptr)
        {
            cout << "k is greater than length of the list!" << endl;
            return list;
        }
        cout << end->data << endl;
        end = end->next;
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

int main()
{
    Node *list = create();
    cout << "List: " << endl;
    print(list);
    cout << "swapping with k=1" << endl;
    list = swap_k(list, 1);
    print(list);
    cout << "swapping with k=2" << endl;
    list = swap_k(list, 2);
    print(list);
    cout << "swapping with k=3" << endl;
    list = swap_k(list, 3);
    print(list);
    cout << "swapping with k=10" << endl;
    list = swap_k(list, 10);
    print(list);

    return 0;
}
