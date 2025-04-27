#include <iostream>
using namespace std;

class Deque
{
public:
    int *arr;
    int size;
    int front, rear;

    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    void PushRear(int data)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size))
        {
            cout << "Queue is full, cannot insert at rear." << endl;
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }

        arr[rear] = data;
    }

    void PushFront(int data)
    {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size))
        {
            cout << "Queue is full, cannot insert at front." << endl;
            return;
        }

        if (front == -1)
        {
            front = rear = 0;
        }
        else
        {
            front = (front - 1 + size) % size;
        }

        arr[front] = data;
    }

    void PopFront()
    {
        if (front == -1)
        {
            cout << "Queue is empty, cannot pop front." << endl;
            return;
        }

        arr[front] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front = (front + 1) % size;
        }
    }

    void PopRear()
    {
        if (rear == -1)
        {
            cout << "Queue is empty, cannot pop rear." << endl;
            return;
        }

        arr[rear] = -1;

        if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            rear = (rear - 1 + size) % size;
        }
    }

    void print()
    {
        if (front == -1)
        {
            cout << "Queue is empty." << endl;
            return;
        }

        cout << "Deque: ";
        int i = front;
        while (true)
        {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }
};
