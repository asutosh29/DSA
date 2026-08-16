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
    // Avail is a LL of freenodes. So push the freed node to the front of the list
    next_index[index] = AVAIL;
    AVAIL = index;
}

void create();
void print();
int search(int key);
int delete_at_ptr(int ptr);
void test_delete_at_ptr();

int main()
{
    // Allocate the Static List globally
    init_avail();

    test_delete_at_ptr();
    return 0;
}

// --- Linked list operations ---
// Creates a linear linked list from standard input
// Input stops when -99 is entered
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

// Search for a key in the list, return the index of the node
// holding the key, or NIL if the key is not found
int search(int key)
{
    int curr = START;
    while (curr != NIL)
    {
        if (data[curr] == key)
        {
            return curr;
        }
        curr = next_index[curr];
    }
    return curr;
}

// Copy temporary data from the next node to the current node, then free the next node
int delete_at_ptr(int ptr)
{
    // if ptr is the last element, this approach can't be applied
    if (next_index[ptr] == NIL)
    {
        cout << "Can't delete last node!" << endl;
        return NIL;
    }

    int temp = next_index[ptr];
    data[ptr] = data[temp];
    next_index[ptr] = next_index[temp];
    free_node(temp);
    return ptr;
}

void test_delete_at_ptr()
{
    create();
    print();

    while (true)
    {
        cout << "Enter the element to delete (-99 to exit): ";
        int key;
        cin >> key;
        if (key == -99)
        {
            cout << "Exiting..." << endl;
            break;
        }

        int ptr = search(key);
        if (ptr == NIL)
        {
            cout << "Key not found!" << endl;
            continue;
        }

        delete_at_ptr(ptr);
        print();
    }
}
