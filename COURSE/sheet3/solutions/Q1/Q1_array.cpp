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

// Returns the number of elements in the list
int count()
{
    int ptr = START;
    int count = 0;
    while (ptr != NIL)
    {
        count++;
        ptr = next_index[ptr];
    }
    return count;
}

// Manipulates the record by index and value
void modify()
{
    if (START == NIL)
    {
        cout << "Empty list can't be modified!" << endl;
        return;
    }
    int n = count();
    while (true)
    {
        cout << "Enter index to modify (1 to " << n << ", 0 to exit): ";
        int index;
        cin >> index;
        if (index == 0)
        {
            cout << "Exiting modification..." << endl;
            return;
        }
        if (index < 1 || index > n)
        {
            cout << "Invalid index!" << endl;
            continue;
        }

        int ptr = START;
        for (int i = 1; i < index; i++)
        {
            ptr = next_index[ptr];
        }
        cout << "Current value at index " << index << " is " << data[ptr] << endl;
        cout << "Enter new value: ";
        int temp;
        cin >> temp;
        data[ptr] = temp;
        cout << "Updated!" << endl;
    }
}

int main()
{
    // Allocate the Static List globally
    init_avail();

    create();
    print();
    cout << "Number of elements in list is: " << count() << endl;
    modify();

    cout << "list after modification: " << endl;
    print();

    return 0;
}
