#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    };
    Node()
    {
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
    };
};

struct DLL
{
    Node *head;
    Node *tail;
    DLL()
    {
        this->head = nullptr;
        this->tail = nullptr;
    };
    DLL(Node *head, Node *tail)
    {
        this->head = nullptr;
        this->tail = nullptr;
    };
};

DLL *create_dll();
void print(Node *head);


void print(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *ptr = head;
    cout << ptr->data << " ";
    ptr = ptr->next;

    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

DLL *create_dll()
{
    Node *head = nullptr;
    Node *curr = head;
    while (true)
    {
        int el;
        cout << "Enter element (-99 to quit): ";
        cin >> el;
        if (el == -99)
        {
            break;
        }

        // LL is empty, insert at head
        if (head == nullptr)
        {
            Node *temp = new Node(el);
            head = temp;
            temp->prev = curr;
            curr = temp;
        }
        else
        {
            Node *temp = new Node(el);
            curr->next = temp;
            temp->prev = curr;
            curr = temp;
        }
    }
    DLL *result = new DLL(head, curr);
    return result;
}


DLL*  insert_before(DLL* list, int key);
DLL*  insert_after(DLL* list, int key);

int main()
{
    DLL *DLL = create_dll();
    print(DLL->head);

    return 0;
}
