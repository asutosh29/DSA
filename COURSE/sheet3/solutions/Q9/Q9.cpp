#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    char *data;
    Node *next;
    Node(char *data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node()
    {
        this->data = (char *)"";
        this->next = nullptr;
    }
};

char *input_line();
void josephus(Node *head);
Node *create();
void print(Node *head);
Node *find(Node *head, char *key);
Node *delete_node(Node *head, Node *loc);
char *read_name();

int main()
{
    Node *head = create();
    print(head);
    josephus(head);

    return 0;
}

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

    while (ptr != head)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

Node *create()
{
    // Input first node and mark it as head
    Node *head = nullptr;
    Node *curr = head;
    // Keep ingesting nodes untill END is written
    while (true)
    {
        if (head == nullptr)
        {
            cout << "Enter name (END to stop): ";
            char *name = input_line();
            if (!strcmp(name, "END"))
            {
                return head;
            }
            head = new Node(name);
            curr = head;
            continue;
        }
        cout << "Enter name (END to stop): ";
        char *name = input_line();
        if (!strcmp(name, "END"))
        {
            // point the last to maintain circular
            curr->next = head;
            return head;
        }
        curr->next = new Node(name);
        curr = curr->next;
    }
    return head;
}

char *input_line()
{
    char temp[100];
    cin.getline(temp, 100);
    char *return_string = new char[strlen(temp) + 1];
    strcpy(return_string, temp);
    return return_string;
}

Node *find(Node *head, char *key)
{
    Node *ptr = head;
    if (!strcmp(ptr->data, key))
    {
        return ptr;
    }
    ptr = ptr->next;
    while (ptr != head)
    {
        if (!strcmp(ptr->data, key))
        {
            return ptr;
        }
        ptr = ptr->next;
    }
    return nullptr;
}

// Deletes loc from the circular list and returns the (possibly new) head
Node *delete_node(Node *head, Node *loc)
{
    if (head == nullptr || loc == nullptr)
    {
        cout << "Location not found or List is empty" << endl;
        return head;
    }

    // Deleting the head of the circular list
    if (loc == head)
    {
        // Only one node left
        if (head->next == head)
        {
            cout << "Deleting " << head->data << endl;
            delete head;
            return nullptr;
        }
        // Find the tail (the node whose next points to head)
        Node *tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        Node *new_head = head->next;
        tail->next = new_head; // keep the list circular
        cout << "Deleting " << head->data << endl;
        delete head;
        return new_head;
    }

    // Otherwise, find the node just before loc
    Node *ptr = head;
    while (ptr->next != nullptr && ptr->next != loc)
    {
        ptr = ptr->next;
    }
    if (ptr->next == nullptr)
    {
        cout << "Location not present in list!" << endl;
        return head;
    }

    ptr->next = loc->next;
    cout << "Deleting " << loc->data << endl;
    delete loc;
    return head;
}

char *read_name()
{
    char *name;
    cout << "Enter entrypoint soldier name: ";
    name = input_line();
    return name;
}

void josephus(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty!" << endl;
        return;
    }
    char *name = read_name();
    int n;
    cout << "Input N: ";
    cin >> n;
    cout << "Searching for " << name << "; n=" << n << endl;
    Node *start = find(head, name);
    if (start == nullptr)
    {
        cout << "Name not found in the list!" << endl;
        return;
    }
    Node *ptr = start;
    while (ptr != ptr->next)
    {
        for (int i = 0; i < n - 1; i++)
        {
            ptr = ptr->next;
        }

        // Store the next node before deleting the current node
        Node *nxt = ptr->next;
        head = delete_node(head, ptr);
        ptr = nxt;
    }
    cout << "Final person to exit: " << ptr->data << endl;
    return;
}
