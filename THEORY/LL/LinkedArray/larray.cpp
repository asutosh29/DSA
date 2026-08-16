#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
const int NIL = -1;

int data[MAX_SIZE];
int next_index[MAX_SIZE];

int START = -1;
int AVAIL = -1;

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
    // to the front of the list.
    next_index[index] = AVAIL;
    AVAIL = index;
}

// --- Linked list operations ---
// Create a list
void create()
{
    int val;
    int last = NIL;

    cout << "Input numbers (type -99 to stop):";
    while (true)
    {
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
    int ptr = START;
    while (ptr != NIL)
    {
        cout << data[ptr] << " ";
        ptr = next_index[ptr];
    }
    cout << "\n";
}
// Insert a new node with the given data at the end of the list
int count()
{
    int ptr = START;
    int count = 0;
    while(ptr != NIL)
    {
        count++;
        ptr = next_index[ptr];
    }
    return count;
}

// Search for a key in the list, return its index and the index of its previous node
int search(int key, int &prevOut) {
    int ptr = START;
    int prev = NIL;
    while (ptr != NIL) {
        if (data[ptr] == key) {
            prevOut = prev;
            return ptr;
        }
        prev = ptr;
        ptr = next_index[ptr];
    }
    prevOut = NIL;
    return NIL;   // not found
}
 
// Swaps the data of the node at index p with its next node
void swapData(int p) {
    int t = data[next_index[p]];
    data[next_index[p]] = data[p];
    data[p] = t;
}
 


int main()
{
    // Allocate the Static List globally
    init_avail();

    create();
    cout << count() << " elements in the list: ";
    print();
    return 0;
}