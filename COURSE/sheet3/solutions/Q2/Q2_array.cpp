#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
const int NIL = -1;

double data[MAX_SIZE];
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
    AVAIL = next_index[AVAIL]; // move AVAIL to the next available node
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
// Creates a sorted list: reads n numbers, inserting each at its
void create_sorted()
{
    cout << "input number of elements: " << endl;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "input element " << i + 1 << ": ";
        double temp;
        cin >> temp;

        // insert_sorted: find the right spot in the existing list
        int ptr = START;
        int prev = NIL;
        while (ptr != NIL && data[ptr] < temp)
        {
            prev = ptr;
            ptr = next_index[ptr];
        }

        int idx = get_node();
        data[idx] = temp;

        // insert before the node at ptr
        if (prev == NIL)
        {
            // new head
            next_index[idx] = START;
            START = idx;
        }
        else
        {
            next_index[idx] = ptr;
            next_index[prev] = idx;
        }
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

int main()
{
    // Allocate the Static List globally
    init_avail();

    create_sorted();
    cout << "Sorted list: ";
    print();

    return 0;
}
