#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    Node()
    {
        this->data = 0;
        this->next = nullptr;
    }
};

struct SearchAnswer
{
    Node *prev;
    Node *curr;
};

Node *create();
void print(Node *head);
SearchAnswer *search_with_prev(Node *head, int key);

int main()
{
    Node *list = create();
    cout << "List: ";
    print(list);

    while (true)
    {
        int input;
        cout << "Enter element to search (-99 to cancel): ";
        cin >> input;
        if (input == -99)
        {
            break;
        }

        SearchAnswer *result = search_with_prev(list, input);
        if (result->curr == nullptr)
        {
            cout << "Element not found!" << endl;
            continue;
        }
        cout << result->curr->data << " found!" << endl;

        if (result->prev != nullptr)
        {
            cout << "Element previous to key is: " << result->prev->data << endl;
        }
        else
        {
            cout << "Element previous to key doesn't exist!" << endl;
        }
    }
    return 0;
}

// Creates a linear linked list from standard input
// Input stops when -99 is entered
Node *create()
{
    int temp;
    cout << "Input node (-99 to quit): ";
    cin >> temp;
    if (temp == -99)
    {
        return nullptr;
    }
    Node *current = new Node(temp);
    current->next = create();
    return current;
}

void print(Node *head)
{
    if (head == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    Node *ptr = head;
    while (ptr != nullptr)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << endl;
}

// Searches for key and returns BOTH pointers:
// curr: the node containing the key (nullptr if not found)
// prev: the node immediately before it (nullptr if the key
// is at the head, or if the key is not found)
SearchAnswer *search_with_prev(Node *head, int key)
{
    Node *ptr = head;
    Node *prev = nullptr;
    while (ptr != nullptr)
    {
        if (ptr->data == key)
        {
            SearchAnswer *result = new SearchAnswer;
            result->curr = ptr;
            result->prev = prev;
            return result;
        }
        prev = ptr;
        ptr = ptr->next;
    }
    SearchAnswer *result = new SearchAnswer;
    result->curr = ptr;
    result->prev = prev;
    return result;
}
