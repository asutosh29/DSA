#include <iostream>
using namespace std;

struct Node
{
    double data;
    Node *next;
    Node(double data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node()
    {
        this->data = 0.0;
        this->next = nullptr;
    }
};

Node *create_sorted();
void print(Node *head);
Node *insert_sorted(Node *head, double data);

int main()
{
    Node *head = create_sorted();
    cout << "Sorted list: ";
    print(head);
    return 0;
}

// Reads n numbers from standard input and inserts each one at sorted position
Node *create_sorted()
{
    cout << "input number of elements: " << endl;
    int n;
    cin >> n;

    Node *head = nullptr;
    for (int i = 0; i < n; i++)
    {
        cout << "input element " << i + 1 << ": ";
        double temp;
        cin >> temp;
        head = insert_sorted(head, temp);
    }
    return head;
}

// Inserts data into the sorted list maintaining ascending order
// Works for both integers and floats since double holds both
Node *insert_sorted(Node *head, double data)
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
