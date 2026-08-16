#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
const int NIL = -1;

int data[MAX_SIZE];
int next_index[MAX_SIZE];

int START = NIL;
int AVAIL = NIL;

// Result of a search: indices of the key node and the node before it
struct SearchAnswer
{
    int prev; // NIL if the key is the first node, or if not found
    int curr; // NIL if the key is not found
};

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

// Searches for key and returns BOTH pointers:
// curr: the node containing the key (nullptr if not found)
// prev: the node immediately before it (nullptr if the key
// is at the head, or if the key is not found)
SearchAnswer search_with_prev(int key)
{
    int ptr = START;
    int prev = NIL;
    while (ptr != NIL)
    {
        if (data[ptr] == key)
        {
            SearchAnswer result;
            result.curr = ptr;
            result.prev = prev;
            return result;
        }
        prev = ptr;
        ptr = next_index[ptr];
    }
    SearchAnswer result;
    result.curr = NIL;
    result.prev = prev;
    return result;
}

int main()
{
    // Allocate the Static List globally
    init_avail();

    create();
    cout << "List: ";
    print();

    while (true)
    {
        int input;
        cout << "Enter element to search (-99 to cancel): ";
        cin >> input;
        if (input == -99)
        {
            break;
        }

        SearchAnswer result = search_with_prev(input);
        if (result.curr == NIL)
        {
            cout << "Element not found!" << endl;
            continue;
        }
        cout << data[result.curr] << " found!" << endl;

        if (result.prev != NIL)
        {
            cout << "Element previous to key is: " << data[result.prev] << endl;
        }
        else
        {
            cout << "Element previous to key doesn't exist!" << endl;
        }
    }
    return 0;
}
