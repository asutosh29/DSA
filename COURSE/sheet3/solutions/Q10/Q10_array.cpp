#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
const int NIL = -1;

int data[MAX_SIZE];
int next_index[MAX_SIZE];
int prev_index[MAX_SIZE];

int START = NIL;
int TAIL = NIL;
int AVAIL = NIL;

struct DLL
{
    int head;
    int tail;
};

void create_dll(DLL &list);
void print(int head);
void print_reverse(int tail);
int search(DLL &list, int key);
int count(DLL &list);
void insert_at_head(DLL &list, int val);
void insert_at_tail(DLL &list, int val);
void insert_before(DLL &list, int key, int val);
void insert_after(DLL &list, int key, int val);
void insert_at_position(DLL &list, int pos, int val);

// --- Construct a linked list using an array representation ---
// Make the links for all the available nodes
void init_avail()
{
    for (int i = 0; i < MAX_SIZE - 1; i++)
    {
        next_index[i] = i + 1;
    }
    next_index[MAX_SIZE - 1] = NIL;
    AVAIL = 0; // first available node at 0th index
}

// --- Memory management functions for the linked list ---
// equivalent of malloc() in C, returns the index of the next available node
int get_node()
{
    if (AVAIL == NIL)
    {
        cout << "No available nodes!" << endl;
        exit(1);
    }
    int node_index = AVAIL;
    AVAIL = next_index[AVAIL];
    return node_index;
}

// equivalent of free() in C, frees the node at the given index
void free_node(int index)
{
    // Avail is a LL of freenodes. So push the freed node
    // to the front of the list
    next_index[index] = AVAIL;
    AVAIL = index;
}

// --- Linked list operations ---
// Creates a doubly linked list from standard input
// Input stops when -99 is entered
void create_dll(DLL &list)
{
    list.head = NIL;
    list.tail = NIL;
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
}

void print(int head)
{
    if (head == NIL)
    {
        cout << "List is empty" << endl;
        return;
    }
    int ptr = head;
    while (ptr != NIL)
    {
        cout << data[ptr] << " ";
        ptr = next_index[ptr];
    }
    cout << endl;
}

void print_reverse(int tail)
{
    if (tail == NIL)
    {
        cout << "List is empty" << endl;
        return;
    }
    int ptr = tail;
    while (ptr != NIL)
    {
        cout << data[ptr] << " ";
        ptr = prev_index[ptr];
    }
    cout << endl;
}

// Searches for the first node whose data equals key
// Returns its index, or NIL if not found
int search(DLL &list, int key)
{
    int ptr = list.head;
    while (ptr != NIL)
    {
        if (data[ptr] == key)
        {
            return ptr;
        }
        ptr = next_index[ptr];
    }
    return NIL;
}

int count(DLL &list)
{
    int cnt = 0;
    int ptr = list.head;
    while (ptr != NIL)
    {
        cnt++;
        ptr = next_index[ptr];
    }
    return cnt;
}

// Insert at the head
void insert_at_head(DLL &list, int val)
{
    int idx = get_node();
    data[idx] = val;
    next_index[idx] = NIL;
    prev_index[idx] = NIL;
    if (list.head == NIL)
    {
        list.head = idx;
        list.tail = idx;
    }
    else
    {
        next_index[idx] = list.head;
        prev_index[list.head] = idx;
        list.head = idx;
    }
}

// Insert at the tail
void insert_at_tail(DLL &list, int val)
{
    int idx = get_node();
    data[idx] = val;
    next_index[idx] = NIL;
    prev_index[idx] = NIL;
    if (list.head == NIL)
    {
        list.head = idx;
        list.tail = idx;
    }
    else
    {
        prev_index[idx] = list.tail;
        next_index[list.tail] = idx;
        list.tail = idx;
    }
}

// Insert before a key node
void insert_before(DLL &list, int key, int val)
{
    int loc = search(list, key);
    if (loc == NIL)
    {
        cout << "Key not found!" << endl;
        return;
    }
    if (loc == list.head)
    {
        insert_at_head(list, val);
        return;
    }
    int idx = get_node();
    data[idx] = val;
    prev_index[idx] = prev_index[loc];
    next_index[idx] = loc;
    next_index[prev_index[loc]] = idx;
    prev_index[loc] = idx;
}

// Insert after a key node
void insert_after(DLL &list, int key, int val)
{
    int loc = search(list, key);
    if (loc == NIL)
    {
        cout << "Key not found!" << endl;
        return;
    }
    if (loc == list.tail)
    {
        insert_at_tail(list, val);
        return;
    }
    int idx = get_node();
    data[idx] = val;
    prev_index[idx] = loc;
    next_index[idx] = next_index[loc];
    prev_index[next_index[loc]] = idx;
    next_index[loc] = idx;
}

// Insert at a given position (1-based)
void insert_at_position(DLL &list, int pos, int val)
{
    int n = count(list);
    if (pos < 1 || pos > n + 1)
    {
        cout << "Invalid position!" << endl;
        return;
    }
    if (pos == 1)
    {
        insert_at_head(list, val);
        return;
    }
    if (pos == n + 1)
    {
        insert_at_tail(list, val);
        return;
    }
    // Walk to the node currently at position pos
    int ptr = list.head;
    for (int i = 1; i < pos; i++)
    {
        ptr = next_index[ptr];
    }
    int idx = get_node();
    data[idx] = val;
    prev_index[idx] = prev_index[ptr];
    next_index[idx] = ptr;
    next_index[prev_index[ptr]] = idx;
    prev_index[ptr] = idx;
}

int main()
{
    // Allocate the Static List globally
    init_avail();

    DLL list;
    create_dll(list);
    cout << "List: ";
    print(list.head);

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

        int val, key, pos;
        switch (choice)
        {
        case 1:
            cout << "Enter element to insert at head: ";
            cin >> val;
            insert_at_head(list, val);
            print(list.head);
            break;
        case 2:
            cout << "Enter element to insert at tail: ";
            cin >> val;
            insert_at_tail(list, val);
            print(list.head);
            break;
        case 3:
            cout << "Enter element to insert: ";
            cin >> val;
            cout << "Enter key before which to insert: ";
            cin >> key;
            insert_before(list, key, val);
            print(list.head);
            break;
        case 4:
            cout << "Enter element to insert: ";
            cin >> val;
            cout << "Enter key after which to insert: ";
            cin >> key;
            insert_after(list, key, val);
            print(list.head);
            break;
        case 5:
            cout << "Enter element to insert: ";
            cin >> val;
            cout << "Enter position (1-based): ";
            cin >> pos;
            insert_at_position(list, pos, val);
            print(list.head);
            break;
        case 6:
            print(list.head);
            break;
        case 7:
            print_reverse(list.tail);
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
