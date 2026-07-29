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
    };
    Node()
    {
        this->data = 0;
        this->next = nullptr;
    };
};

Node *create_sorted()
{
    cout << "input number of elements: " << endl;
    int n;
    cin >> n;
    Node* head = new Node();
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        
    }
    
}

int main()
{

    return 0;
}