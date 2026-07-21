#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }

    void print()
    {
        cout << this->value << " -> " << this->next << endl;
    }
};

class LinkedList
{
public:
    Node *head;
    Node *tail;

    LinkedList()
    {
        head = nullptr;
        tail = nullptr;
    }

    void appendList(const vector<int> &v){
        for(auto e: v){
            this->append(e);
        }
    }
    ~LinkedList() 
    {
        Node* iter = head;
        while (iter != nullptr) {
            Node* nextNode = iter->next;
            delete iter;
            iter = nextNode;
        }
    }


    void append(int value){
        if(head == nullptr){
            Node* temp = new Node(value);
            tail = temp;
            head = tail;
            return;
        }

        Node* temp = new Node(value);
        tail->next = temp;
        tail = temp;
    }

    void reverse(){
        
    }




};

ostream &
operator<<(ostream &os, const LinkedList &list)
{
    Node* iter = list.head;
    while(iter != nullptr){
        os << iter->value << " ";
        iter = iter->next;
    }
    cout << '\n';
    return os;
}

ostream &
operator<<(ostream &os, const Node &node)
{
    os << node.value << " -> " << node.next << endl;
    return os;
}

int main()
{
    LinkedList LL;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        LL.append(temp);
    }
    cout << LL << endl;
    
    return 0;
}