#include <iostream>
using namespace std;

const int MAX_SIZE = 5;
const int NIL = -1;

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
    if (q->front == NIL && q->rear == NIL)
    {
        return true;
    }
    return false;
}

bool check_q_overflow(Queue *q)
{
    if ((q->front == 0 && q->rear == MAX_SIZE - 1) || (q->front == q->rear + 1))
    {
        return true;
    }
    return false;
}

void add_q(Queue *q, int item)
{
    // Check overflow
    if (check_q_overflow(q))
    {
        cout << "Overflow!" << endl;
        return;
    }
    // Update pointers
    if (q->front == q->rear && q->front == NIL)
    {
        q->front = 0;
        q->rear = 0;
    }
    else if (q->rear == MAX_SIZE - 1)
    {
        q->rear = 0;
    }
    else
    {
        q->rear++;
    }
    // Assign element
    q->data[q->rear] = item;
}

int remove_q(Queue *q)
{
    // check underflow
    if (check_q_underflow(q))
    {
        cout << "Underflow!" << endl;
        return -1;
    }
    // keep value
    int item = q->data[q->front];
    // update pointers
    if (q->front == q->rear)
    {
        // single element remains
        q->front = NIL;
        q->rear = NIL;
    }
    else if (q->front == MAX_SIZE - 1)
    {
        q->front = 0;
    }
    else
    {
        q->front++;
    }
    return item;
}

void print_queue(Queue *q)
{
    int i = q->front;
    cout << q->data[i] << " ";
    for (i++; i != (q->rear + 1) % MAX_SIZE; i = (i + 1) % MAX_SIZE)
    {
        cout << q->data[i] << " ";
    }
    cout << endl;
}

void test_queue()
{
    Queue *q = new Queue();
    add_q(q, 10);
    add_q(q, 11);
    add_q(q, 12);
    add_q(q, 13);
    add_q(q, 14);
    add_q(q, 15);
    print_queue(q);
    int val = remove_q(q);
    cout << val << endl;
    val = remove_q(q);
    cout << val << endl;
    val = remove_q(q);
    cout << val << endl;
    val = remove_q(q);
    cout << val << endl;
    val = remove_q(q);
    cout << val << endl;
    val = remove_q(q);
    cout << val << endl;
}

int main()
{
    test_queue();
    return 0;
}