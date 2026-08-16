#include <iostream>
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
    }
    Node()
    {
        this->data = 0;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

struct DLL
{
    Node *head;
    Node *tail;
    DLL()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
    DLL(Node *head, Node *tail)
    {
        this->head = head;
        this->tail = tail;
    }
};

DLL *create_dll();
void print(Node *head);
void print_reverse(Node *tail);
Node *search(DLL *list, int key);
void insert_at_head(DLL *list, int data);
void insert_at_tail(DLL *list, int data);
void insert_before(DLL *list, int key, int data);
void insert_after(DLL *list, int key, int data);
void insert_at_position(DLL *list, int pos, int data);
int count(DLL *list);

int main()
{
    DLL *list = create_dll();
    cout << "List: ";
    print(list->head);

    while (true)
    {
        cout << "===================================" << endl;
        cout << "1. Insert at head" << endl;
        cout << "2. Insert at tail" << endl;
        cout << "3. Insert before a key node" << endl;
        cout << "4. Insert after a key node" << endl;
        cout << "5. Insert at a given position" << endl;
        cout << "6. Print list (forward)" << endl;
        cout << "7. Print list (reverse)" << endl;
        cout << "99. Exit" << endl;
        cout << "Enter choice: ";
        int choice;
        cin >> choice;

        int data, key, pos;
        switch (choice)
        {
        case 1:
            cout << "Enter element to insert at head: ";
            cin >> data;
            insert_at_head(list, data);
            print(list->head);
            break;
        case 2:
            cout << "Enter element to insert at tail: ";
            cin >> data;
            insert_at_tail(list, data);
            print(list->head);
            break;
        case 3:
            cout << "Enter element to insert: ";
            cin >> data;
            cout << "Enter key before which to insert: ";
            cin >> key;
            insert_before(list, key, data);
            print(list->head);
            break;
        case 4:
            cout << "Enter element to insert: ";
            cin >> data;
            cout << "Enter key after which to insert: ";
            cin >> key;
            insert_after(list, key, data);
            print(list->head);
            break;
        case 5:
            cout << "Enter element to insert: ";
            cin >> data;
            cout << "Enter position (1-based): ";
            cin >> pos;
            insert_at_position(list, pos, data);
            print(list->head);
            break;
        case 6:
            print(list->head);
            break;
        case 7:
            print_reverse(list->tail);
            break;
        case 99:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}

// Creates a doubly linked list from standard input
// Input stops when -99 is entered
DLL *create_dll()
{
    DLL *list = new DLL();
    while (true)
    {
        int el;
        cout << "Enter element (-99 to quit): ";
        cin >> el;
        if (el == -99)
        {
            break;
        }
        insert_at_tail(list, el);
    }
    return list;
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

void print_reverse(Node *tail)
{
    if (tail == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *ptr = tail;
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->prev;
    }
    cout << endl;
}

// Searches for the first node whose data equals key
// Returns the node pointer, or nullptr if not found
Node *search(DLL *list, int key)
{
    Node *ptr = list->head;
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

int count(DLL *list)
{
    int cnt = 0;
    Node *ptr = list->head;
    while (ptr != nullptr)
    {
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}

// Insert at the head
void insert_at_head(DLL *list, int data)
{
    Node *temp = new Node(data);
    if (list->head == nullptr)
    {
        list->head = temp;
        list->tail = temp;
    }
    else
    {
        temp->next = list->head;
        list->head->prev = temp;
        list->head = temp;
    }
}

// Insert at the tail
void insert_at_tail(DLL *list, int data)
{
    Node *temp = new Node(data);
    if (list->head == nullptr)
    {
        list->head = temp;
        list->tail = temp;
    }
    else
    {
        temp->prev = list->tail;
        list->tail->next = temp;
        list->tail = temp;
    }
}

// Insert before a key node
void insert_before(DLL *list, int key, int data)
{
    Node *loc = search(list, key);
    if (loc == nullptr)
    {
        cout << "Key not found!" << endl;
        return;
    }
    if (loc == list->head)
    {
        insert_at_head(list, data);
        return;
    }
    Node *temp = new Node(data);
    temp->prev = loc->prev;
    temp->next = loc;
    loc->prev->next = temp;
    loc->prev = temp;
}

// Insert after a key node
void insert_after(DLL *list, int key, int data)
{
    Node *loc = search(list, key);
    if (loc == nullptr)
    {
        cout << "Key not found!" << endl;
        return;
    }
    if (loc == list->tail)
    {
        insert_at_tail(list, data);
        return;
    }
    Node *temp = new Node(data);
    temp->prev = loc;
    temp->next = loc->next;
    loc->next->prev = temp;
    loc->next = temp;
}

// Insert at a given position (1-based)
void insert_at_position(DLL *list, int pos, int data)
{
    int n = count(list);
    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 1)
    {
        insert_at_head(list, data);
        return;
    }
    if (pos == n + 1)
    {
        insert_at_tail(list, data);
        return;
    }
    // Walk to the node currently at position pos
    Node *ptr = list->head;
    for (int i = 1; i < pos; i++)
    {
        ptr = ptr->next;
    }
    Node *temp = new Node(data);
    temp->prev = ptr->prev;
    temp->next = ptr;
    ptr->prev->next = temp;
    ptr->prev = temp;
}
