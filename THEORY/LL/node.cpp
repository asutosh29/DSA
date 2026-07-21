#include<iostream>
using namespace std;

class Node {
    public: 
        int data;
        Node* next;

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }

    void print(){
        cout << "( "<<this->next << " ) " << this->data << endl; 
    }
};

int main(){
    cout << "Hello" << endl;
    Node a(1, nullptr);
    Node b(2,&a);
    cout << &a << " " << &b << endl;
    a.print();
    b.print();
    return 0;
}