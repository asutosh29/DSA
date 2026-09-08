
#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
const int NIL = -1;

struct Node {
    int data;
    Node* next;
};

struct Queue
{
    int data[MAX_SIZE];
    int front, rear;
    Queue()
    {
        front = rear = NIL;
    }
};

bool check_q_underflow(Queue *q)
{
}

bool check_q_overflow(Queue *q)
{
}

void add_q(Queue *q, int item)
{
}

int remove_q(Queue *q)
{
}

void print_queue(Queue *q)
{
}

void test_queue()
{
    Queue *q = new Queue();
    add_q(q, 10);
    add_q(q, 11);
    add_q(q, 12);
    add_q(q, 13);
    add_q(q, 14);
    print_queue(q);
    int val = remove_q(q);
    cout << val << endl;
    val = remove_q(q);
    cout << val << endl;
    val = remove_q(q);
    cout << val << endl;
    add_q(q, 14);
    add_q(q, 15);
}

int main()
{
    test_queue();
    return 0;
}