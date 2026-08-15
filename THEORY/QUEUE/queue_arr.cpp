#include <iostream>
using namespace std;

struct Queue
{
    int front, rear, size;
    int *array;
    Queue(int size)
    {
        this->size = size + 1;
        front = 0;
        rear = 0;
        array = new int[size + 1];
    }
};

bool isEmpty(Queue *queue)
{
    return (queue->front == queue->rear);
}
bool isFull(Queue *queue)
{
    return ((queue->rear + 1) % queue->size == queue->front);
}

void enqueue(Queue *queue, int item)
{
    if (isFull(queue))
    {
        cout << "Queue is full" << endl;
        return;
    }
    queue->rear = (queue->rear + 1) % queue->size;
    queue->array[queue->rear] = item;
}

int dequeue(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    queue->front = (queue->front + 1) % queue->size;
    return queue->array[queue->front];
}

int front(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return queue->array[(queue->front + 1) % queue->size];
}

int rear(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    return queue->array[(queue->rear) % queue->size];
}

void printQueue(Queue *queue)
{
    if (isEmpty(queue))
    {
        cout << "Queue is empty" << endl;
        return;
    }
    int i = (queue->front + 1) % queue->size;
    while (i != (queue->rear + 1) % queue->size)
    {
        cout << queue->array[i] << " ";
        i = (i + 1) % queue->size;
    }
    cout << endl;
}

void test_queue()
{
    Queue *queue = new Queue(5);
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