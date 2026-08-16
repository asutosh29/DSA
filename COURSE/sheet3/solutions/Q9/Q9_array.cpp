#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 100;
const int NIL = -1;

char *data[MAX_SIZE]; // names
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

// Reads one line of input into a dynamically allocated char array
char *input_line()
{
    char temp[100];
    cin.getline(temp, 100);
    char *return_string = new char[strlen(temp) + 1];
    strcpy(return_string, temp);
    return return_string;
}

// --- Linked list operations ---
// Create a circular list
void create()
{
    int last = NIL;

    while (true)
    {
        cout << "Enter name (END to stop): ";
        char *name = input_line();

        if (START == NIL)
        {
            if (!strcmp(name, "END"))
            {
                return;
            }
            START = get_node();
            data[START] = name;
            next_index[START] = NIL;
            last = START;
        }
        else
        {
            if (!strcmp(name, "END"))
            {
                // close the circle
                // last node points to first node
                next_index[last] = START;
                return;
            }
            int idx = get_node();
            data[idx] = name;
            next_index[idx] = NIL;
            next_index[last] = idx;
            last = idx;
        }
    }
}

// Print the circular list
void print()
{
    if (START == NIL)
    {
        cout << "List is empty" << endl;
        return;
    }
    int ptr = START;
    cout << data[ptr] << " ";
    ptr = next_index[ptr];

    while (ptr != START)
    {
        cout << data[ptr] << " ";
        ptr = next_index[ptr];
    }
    cout << endl;
}

// Searches the circular list for the node whose name equals key
// Returns its index, or NIL if not found
int find(int head, char *key)
{
    int ptr = head;
    if (!strcmp(data[ptr], key))
    {
        return ptr;
    }
    ptr = next_index[ptr];
    while (ptr != head)
    {
        if (!strcmp(data[ptr], key))
        {
            return ptr;
        }
        ptr = next_index[ptr];
    }
    return NIL;
}

// Deletes the node at index loc from the circular list and returns
// the (possibly new) START index
int delete_node(int head, int loc)
{
    if (head == NIL || loc == NIL)
    {
        cout << "Location not found or List is empty" << endl;
        return head;
    }

    // Deleting the head of the circular list
    if (loc == head)
    {
        // Only one node left
        if (next_index[head] == head)
        {
            cout << "Deleting " << data[head] << endl;
            free_node(head);
            return NIL;
        }
        // Find the tail (the node whose next points to head)
        int tail = head;
        while (next_index[tail] != head)
        {
            tail = next_index[tail];
        }
        int new_head = next_index[head];
        next_index[tail] = new_head; // keep the list circular
        cout << "Deleting " << data[head] << endl;
        free_node(head);
        return new_head;
    }

    // Otherwise, find the node just before loc
    int ptr = head;
    while (next_index[ptr] != NIL && next_index[ptr] != loc)
    {
        ptr = next_index[ptr];
    }
    if (next_index[ptr] == NIL)
    {
        cout << "Location not present in list!" << endl;
        return head;
    }

    next_index[ptr] = next_index[loc];
    cout << "Deleting " << data[loc] << endl;
    free_node(loc);
    return head;
}

char *read_name()
{
    char *name;
    cout << "Enter entrypoint soldier name: ";
    name = input_line();
    return name;
}

void josephus()
{
    if (START == NIL)
    {
        cout << "List is empty!" << endl;
        return;
    }
    char *name = read_name();
    int n;
    cout << "Input N: ";
    cin >> n;
    cout << "Searching for " << name << "; n=" << n << endl;
    int start = find(START, name);
    if (start == NIL)
    {
        cout << "Name not found in the list!" << endl;
        return;
    }
    int ptr = start;
    while (ptr != next_index[ptr])
    {
        for (int i = 0; i < n - 1; i++)
        {
            ptr = next_index[ptr];
        }

        // Store the next node before deleting the current node
        int nxt = next_index[ptr];
        START = delete_node(START, ptr);
        ptr = nxt;
    }
    cout << "Final person to exit: " << data[ptr] << endl;
    return;
}

int main()
{
    // Allocate the Static List globally
    init_avail();

    create();
    print();
    josephus();

    return 0;
}
