#include <iostream>

using namespace std;

class Queue
{
public:
    int *arr;
    int size;
    int rear;
    int front;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void Push(int data)
    {
        if (rear == size)
        {
            cout << "The queue is full." << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void Pop()
    {
        if (front == rear)
        {
            cout << "The queue is empty." << endl;
        }
        else
        {
            arr[front] = -1;
            front++;
            if (front == rear)
            {
                front = 0;
                rear = 0;
            }
        }
    }

    int GetFront()
    {
        if (front == rear)
        {
            cout << "The queue is empty, nothing to return." << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        if (front == rear)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Queue q(10);

    q.Push(7);
    q.Push(8);
    q.Push(9);
    q.Push(10);
    q.Push(11);
    q.Push(12);

    q.Pop();
    q.Pop();
    q.Pop();
    q.Pop();
    q.Pop();
    q.Pop();
    q.Pop();

    q.Push(13);
    q.Push(14);
    q.Push(15);
    q.Push(16);
    q.Push(17);

    cout << q.GetFront() << endl;

    if (q.isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}