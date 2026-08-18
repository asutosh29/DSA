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
    Node *rear, *front;
    Queue()
    {
        rear = front = nullptr;
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
    if (isFull(queue))
    {
        cout << "Queue is Full" << endl;
        return;
    }

    Node *temp = new Node(x);
    if (queue->front == nullptr)
    {
        queue->rear = temp;
        queue->front = temp;
    }
    else
    {
        queue->rear->next = temp;
        queue->rear = temp;
    }
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    Node *temp = queue->front;
    queue->front = queue->front->next;
    if(queue->front == nullptr)
    {
        queue->rear = nullptr;
    }
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
    Node* start = queue->front;
    Node* end = queue->rear;
    while (start != end->next){
        cout << start->data << " ";
        start = start->next;
    }
    cout << endl;
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
    enqueue(queue, 6);
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
    dequeue(queue);
    printQueue(queue);
}

int main()
{
    test_queue();
    return 0;
}