#include <iostream>
using namespace std;

class DEQueue
{
    int* arr;
    int front, rear, size;
public:
    DEQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        for (int i = 0; i < this->size; i++)
        {
            arr[i] = 0;
        }
        
        front = 0;
        rear = 0;
    }
    bool isFull()
    {
        return ((this->rear + 1) % this->size == this->front);
    }
    bool isEmpty()
    {
        return (this->front == this->rear);
    }
    void push_front(int x)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        arr[this->front] = x;
        this->front = (this->front - 1 + this->size) % this->size;
    }
    void push_back(int x)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        this->rear = (this->rear + 1) % this->size;
        arr[this->rear] = x;
    }
    int pop_front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        this->front = (this->front + 1) % this->size;
        return arr[this->front];
    }
    int pop_back()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        int value = arr[this->rear];
        this->rear = (this->rear - 1 + this->size) % this->size;
        return value;
    }
    void print()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = 0; i < this->size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    DEQueue dq(5);
    dq.push_front(10);
    dq.push_back(20);
    dq.push_front(30);
    dq.push_back(40);
    dq.print();
    cout << dq.pop_front() << endl;
    cout << dq.pop_back() << endl;
    return 0;
}