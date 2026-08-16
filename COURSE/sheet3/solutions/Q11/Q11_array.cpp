#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
const int NIL = -1;

int data[MAX_SIZE];
int next_index[MAX_SIZE];

int START1 = NIL; 
int START2 = NIL; 
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

// Creates a linear linked list from standard input.
// The head index is stored in "start" (passed by reference).
// Input stops when -99 is entered.
void create(int &start)
{
    int last = NIL;
    start = NIL;

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

        if (start == NIL)
            start = idx;
        else
            next_index[last] = idx;
        last = idx;
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

// Both lists are sorted ascending.
// The two cursors c1 and c2 traverse the two lists.
// If the two nodes are equal, we add it to the new list.
int intersect_sorted_list(int L1, int L2)
{
    int c1 = L1;
    int c2 = L2;
    int head = NIL;
    int c3 = head;
    while (c1 != NIL && c2 != NIL)
    {
        if (data[c1] == data[c2])
        {
            int idx = get_node();
            data[idx] = data[c1];
            next_index[idx] = NIL;
            if (head == NIL)
            {
                head = idx;
                c3 = idx;
            }
            else
            {
                next_index[c3] = idx;
                c3 = idx;
            }
            c1 = next_index[c1];
            c2 = next_index[c2];
        }
        else if (data[c1] > data[c2])
        {
            c2 = next_index[c2];
        }
        else
        {
            c1 = next_index[c1];
        }
    }
    return head;
}

int main()
{
    // Allocate the Static List globally
    init_avail();

    cout << "Input first sorted List:" << endl;
    create(START1);
    print(START1);

    cout << "Input second sorted List:" << endl;
    create(START2);
    print(START2);

    cout << "Computing intersection..." << endl;
    int merged = intersect_sorted_list(START1, START2);
    print(merged);

    return 0;
}
