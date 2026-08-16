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
int create();
void print(int head);
int swap_k(int list, int k);

int main()
{
    // Allocate the Static List globally
    init_avail();

    START = create();
    cout << "List: " << endl;
    print(START);

    while (true)
    {
        int k;
        cout << "Enter k to swap (-99 to exit): ";
        cin >> k;
        if (k == -99)
        {
            cout << "Exiting..." << endl;
            break;
        }
        cout << "swapping with k=" << k << endl;
        START = swap_k(START, k);
        print(START);
    }

    return 0;
}

// Creates a linear linked list from standard input
// Input stops when -99 is entered
// The head index is returned (NIL for an empty list)
int create()
{
    int temp;
    cout << "Input node (-99 to quit): ";
    cin >> temp;
    if (temp == -99)
    {
        return NIL;
    }
    int idx = get_node();
    data[idx] = temp;
    next_index[idx] = create();
    return idx;
}

// Print List
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

// Swap the kth node from the beginning with the kth node from the end
// k1 = kth node from the beginning
// k2 = kth node from the end
int swap_k(int list, int k)
{
    if (k < 1)
    {
        cout << "k must be at least 1!" << endl;
        return list;
    }
    int start = list;
    int end = list;
    for (int i = 0; i < k - 1; i++)
    {
        if (end == NIL)
        {
            cout << "k is greater than length of the list!" << endl;
            return list;
        }
        end = next_index[end];
        if (end == NIL)
        {
            cout << "k is greater than length of the list!" << endl;
            return list;
        }
    }

    int ptr1 = end;
    while (end != NIL && next_index[end] != NIL)
    {
        start = next_index[start];
        end = next_index[end];
    }

    int ptr2 = start;
    int temp = data[ptr1];
    data[ptr1] = data[ptr2];
    data[ptr2] = temp;
    return list;
}