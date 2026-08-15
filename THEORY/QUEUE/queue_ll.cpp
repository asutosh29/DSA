#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = nullptr;
    };
    Node(int val)
    {
        this->data = val;
        this->next = nullptr;
    };
};

struct Queue
{
    Node *front, *rear;
    Queue()
    {
        front = rear = nullptr;
    }
};

bool isEmpty(Queue *queue)
{
    return queue->front == nullptr;
}

bool isFull(Queue *queue)
{
    return false;
}

void enqueue(Queue *queue, int x)
{
    if (!isFull(queue))
    {
        cout << "Queue is Full" << endl;
        return;
    }

    Node *temp = new Node(x);
    if (queue->front == nullptr)
    {
        queue->front = temp;
        queue->rear = temp;
    }
    else
    {
        queue->front->next = temp;
        queue->front = temp;
    }
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    Node *temp = queue->rear;
    queue->rear = queue->rear->next;
    int x = temp->data;
    delete temp;
    return x;
}


void printQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue is empty" << endl;
        return;
    }
    Node* start = queue->rear;
    Node* end = queue->front;
    while (start != end->next){
        cout << start->data << endl;
        start = start->next;
    }
}

void test_queue(){
    Queue *queue = new Queue();
    printQueue(queue);
    enqueue(queue, 1);
    enqueue(queue, 2);
    enqueue(queue, 3);
    enqueue(queue, 4);
    enqueue(queue, 5);
    printQueue(queue);
    enqueue(queue, 6); // Queue is full
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
    enqueue(queue, 6);
    enqueue(queue, 7);
    printQueue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    dequeue(queue);
    printQueue(queue);
}

int main()
{
    test_queue();
    return 0;
}