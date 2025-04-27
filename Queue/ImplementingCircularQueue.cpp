#include <iostream>

using namespace std;

class CQueue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    CQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void Push(int data)
    {
        // queue full
        if ((front == 0 && rear == size - 1) || (rear == (front - 1 + size) % size))
        {
            cout << "Queue is full, cannot insert." << endl;
            return;
        }
        // first element
        else if (front == -1)
        {
            front = rear = 0;
            arr[rear] = data;
        }
        // circular nature
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
            arr[rear] = data;
        }
        // normal flow
        else
        {
            rear++;
            arr[rear] = data;
        }
    }

    void Pop()
    {
        // queue empty
        if (front == -1 && rear == -1)
        {
            cout << "Queue is empty, cannot pop" << endl;
        }

        // single element remaining
        else if (front == rear)
        {
            arr[rear] = -1;
            front = rear = -1;
        }
        // circular flow
        else if (front = size - 1)
        {
            front = 0;
        }
        // normal flow
        else
        {
            front++;
        }
    }

    void printQueue()
    {
        if (front == -1)
        {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue: ";
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

int main()
{
    CQueue q(5);

    q.Push(10);
    q.Push(20);
    q.Push(30);
    q.Push(40);
    q.Push(50);

    q.printQueue();

    q.Pop();
    q.Pop();

    q.printQueue();

    q.Push(60);
    q.Push(70);

    q.printQueue();

    return 0;
}