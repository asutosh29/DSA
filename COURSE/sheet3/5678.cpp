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

// list functions
Node *create();
void print(Node *head);
Node *insert_after(Node *head, int data, int key);
Node *insert_before(Node *head, int data, int key);
Node *insert_sorted(Node *head, int data);
Node *insert_at_kth(Node *head, int data, int index);

// testing functions
Node *cli_insert_after(Node *list);
Node *cli_insert_before(Node *list);
Node *cli_insert_at_kth(Node *list);
Node *cli_insert_sorted(Node *list);

int main()
{

    Node *list = create();
    if (list == nullptr)
    {
        cout << "List is empty!" << endl;
        return 0;
    }
    else
    {
        cout << "List created: ";
        print(list);
    }
    while (true)
    {
        // Menu
        int choice;
        cout << "===================================" << endl;
        cout << "Choose from the following options: " << endl;
        cout << "1. Insert after" << endl;
        cout << "2. Insert before" << endl;
        cout << "3. Print list" << endl;
        cout << "4. Insert at kth position" << endl;
        cout << "5. Insert in sorted order (if the list is already sorted)" << endl;
        cout << "99. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            list = cli_insert_after(list);
            break;
        case 2:
            list = cli_insert_before(list);
            break;
        case 3:
            print(list);
            break;
        case 4:
            list = cli_insert_at_kth(list);
            break;
        case 5:
            list = cli_insert_sorted(list);
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

Node *insert_after(Node *head, int data, int key)
{
    // empty list
    if (head == nullptr)
    {
        cout << "Provided list is empty!" << endl;
        return nullptr;
    }
    Node *ptr = head;
    while (ptr != nullptr)
    {
        if (ptr->data == key)
        {
            Node *temp = new Node(data);

            temp->next = ptr->next;
            ptr->next = temp;
            return head;
        }
        ptr = ptr->next;
    }
    return head;
}
Node *insert_before(Node *head, int data, int key)
{
    // empty list
    if (head == nullptr)
    {
        cout << "Provided list is empty!" << endl;
        return nullptr;
    }
    Node *ptr = head;
    Node *prev = nullptr;
    while (ptr != nullptr)
    {
        if (ptr->data == key)
        {
            break;
        }
        prev = ptr;
        ptr = ptr->next;
    }

    Node *temp = new Node(data);
    // Key node is the first node
    if (prev == nullptr)
    {
        temp->next = head;
        head = temp;
    }
    else
    {
        temp->next = ptr;
        prev->next = temp;
    }
    return head;
}
Node *insert_at_kth(Node *head, int data, int index)
{
    if (index < 1)
    {
        cout << "Invalid position!" << endl;
        return head;
    }
    Node *temp = new Node(data);
    if (index == 1)
    {
        temp->next = head;
        head = temp;
        return head;
    }
    Node *ptr = head;
    for (int i = 1; i < index - 1 && ptr != nullptr; i++)
    {
        ptr = ptr->next;
    }
    if (ptr == nullptr)
    {
        cout << "Position exceeds list length!" << endl;
        delete temp;
        return head;
    }
    temp->next = ptr->next;
    ptr->next = temp;
    cout << "Inserted element " << data << " at index " << index << endl;
    return head;
}
Node *insert_sorted(Node *head, int data)
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

Node *cli_insert_after(Node *list)
{
    int data, key;
    cout << "Enter element to insert: ";
    cin >> data;
    cout << "Input key after which element is to be inserted: ";
    cin >> key;
    Node *result = insert_after(list, data, key);
    print(result);
    return result;
}
Node *cli_insert_before(Node *list)
{
    int data, key;
    cout << "Enter element to insert: ";
    cin >> data;
    cout << "Input key before which element is to be inserted: ";
    cin >> key;
    Node *result = insert_before(list, data, key);
    print(result);
    return result;
}
Node *cli_insert_at_kth(Node *list)
{
    int data, k;
    cout << "Enter element to insert: ";
    cin >> data;
    cout << "Input position k at which element is to be inserted: ";
    cin >> k;
    Node *result = insert_at_kth(list, data, k);
    print(result);
    return result;
}
Node *cli_insert_sorted(Node *list)
{
    int data;
    cout << "Enter element to insert in sorted order: ";
    cin >> data;
    Node *result = insert_sorted(list, data);
    print(result);
    return result;
}
