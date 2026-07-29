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
    };
    Node()
    {
        this->data = (char *)"";
        this->next = nullptr;
    };
};

char *input_line()
{
    char temp[100];
    cin.getline(temp, 100);
    char *return_string = new char[strlen(temp) + 1];
    strcpy(return_string, temp);
    return return_string;
}

void josephus(Node *head);
Node *create();
void print(Node *head);

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
    // Keep ingesting nodes untill END is written.
    while (true)
    {
        if (head == nullptr)
        {
            cout << "Enter head element name: ";
            char *name = input_line();
            cout << name << endl;
            if (!strcmp(name, "END"))
            {
                return head;
            }
            head = new Node(name);
            curr = head;
            continue;
        }
        cout << "Enter name: ";
        char *name = input_line();
        if (!strcmp(name, "END"))
        {
            // point the last node->next = head;
            curr->next = head;
            return head;
        }
        curr->next = new Node(name);
        curr = curr->next;
    }
    return head;
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

Node *delete_node(Node *head, Node *loc)
{

    if (head == nullptr || loc == nullptr)
    {
        cout << "Location not found or List is empty" << endl;
        return head;
    }

    if (loc == head)
    {
        delete loc;
        head = head->next;
        return head;
    }

    Node *prev = nullptr;
    Node *ptr = head;
    while (ptr != nullptr && ptr != loc)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (ptr == nullptr)
    {
        cout << "Location not present in list!" << endl;
        return head;
    }

    prev->next = ptr->next;
    delete ptr;
    return head;
}

char *read_name()
{
    char *name;
    cout << "Enter entrypoint soldier name: " << endl;
    name = input_line();
    return name;
}

void josephus(Node *head)
{
    char *name = read_name();
    int n;
    cout << "Input N:" << endl;
    cin >> n;
    cout << "Searching for " << name << "; n=" << n << endl;
    Node *start = find(head, name);
    if (start == nullptr)
    {
        cout << "Name not found in the list!" << endl;
        return;
    }
    Node *ptr = start;
    while (ptr->next != ptr)
    {
        for (int i = 0; i < n - 1; i++)
        {
            ptr = ptr->next;
        }
        head = delete_node(head, ptr);
        ptr = ptr->next;
    }

    cout << "Final person to exit: " << ptr->data << endl;
    return;
}