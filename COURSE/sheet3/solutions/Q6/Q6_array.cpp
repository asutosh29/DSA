#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
const int NIL = -1;

int data[MAX_SIZE];
int next_index[MAX_SIZE];

int START = NIL;
int AVAIL = NIL;

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
// Create a list (keeps the -99 sentinel prompt from the pointer version)
void create()
{
    int last = NIL;

    while (true)
    {
        cout << "Input node (-99 to quit): ";
        int val;
        cin >> val;
        if (val == -99)
        {
            break;
        }

        int idx = get_node();
        data[idx] = val;
        next_index[idx] = NIL; // new node points to NIL

        if (START == NIL)
            START = idx;
        else
            next_index[last] = idx;
        last = idx;
    }
}

// Print List
void print()
{
    if (START == NIL)
    {
        cout << "List is empty" << endl;
        return;
    }
    int ptr = START;
    while (ptr != NIL)
    {
        cout << data[ptr] << " ";
        ptr = next_index[ptr];
    }
    cout << endl;
}

// Inserts the integer data item immediately before the node
// whose data equals key. Returns the (possibly new) START
int insert_before(int val, int key)
{
    // empty list
    if (START == NIL)
    {
        cout << "Provided list is empty!" << endl;
        return NIL;
    }
    int ptr = START;
    int prev = NIL;
    while (ptr != NIL)
    {
        if (data[ptr] == key)
        {
            break;
        }
        prev = ptr;
        ptr = next_index[ptr];
    }

    if (ptr == NIL)
    {
        cout << "Key not found!" << endl;
        return START;
    }

    int idx = get_node();
    data[idx] = val;

    // Key node is the first node
    if (prev == NIL)
    {
        next_index[idx] = START;
        START = idx;
    }
    else
    {
        next_index[idx] = ptr;
        next_index[prev] = idx;
    }
    return START;
}

int main()
{
    // Allocate the Static List globally
    init_avail();

    create();
    if (START == NIL)
    {
        cout << "List is empty!" << endl;
        return 0;
    }
    else
    {
        cout << "List created: ";
        print();
    }

    while (true)
    {
        int val, key;
        cout << "Enter element to insert (-99 to exit): ";
        cin >> val;
        if (val == -99)
        {
            cout << "Exiting..." << endl;
            break;
        }
        cout << "Input key before which element is to be inserted: ";
        cin >> key;

        insert_before(val, key);
        print();
    }
    return 0;
}
