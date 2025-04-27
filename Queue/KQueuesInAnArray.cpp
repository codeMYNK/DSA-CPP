#include <iostream>

using namespace std;

class KQueue
{
public:
    int n, k, freespot;
    int *arr, *front, *rear, *next;
    KQueue(int _n, int _k) : n(_n), k(_k), freespot(0)
    {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
            front[i] = rear[i] = -1;
        for (int i = 0; i < n; i++)
            next[i] = i + 1;
        next[n - 1] = -1;
    }
    bool push(int x, int qi)
    {
        // overflow
        if (freespot = -1)
        {
            return false;
        }
        // find first free index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // if front element is present in front
        if (front[qi] == -1)
        {
            front[qi] = index;
        }
        else
        {
            // Link new element to that Q's rearest element
            next[rear[qi]] = index;
        }
        // update index
        next[index] = -1;

        // update rear
        rear[qi] = index;
        arr[index] = x;
        return true;
    }

    int pop(int qi)
    {
        if (front[qi] == -1)
        {
            return -1;
        }

        // find index to pop
        int index = front[qi];

        // front update
        front[qi] = next[index];

        // next update
        next[index] = freespot;
        freespot = index;
        return arr[index];
    }

    ~KQueue()
    {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};
