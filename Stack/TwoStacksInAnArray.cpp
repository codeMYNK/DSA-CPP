#include <iostream>

using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top1 = -1;
        top2 = size;
    }

    void push1(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << "ERROR : Stack Overflow in stack 1, no space to insert." << endl;
            return;
        }
        else
        {
            top1++;
            arr[top1] = data;
        }
    }
    void pop1()
    {
        if (top1 == -1)
        {
            cout << "ERROR : Stack Underflow in stack 1, no element present to pop." << endl;
            return;
        }
        else
        {
            top1--;
        }
    }
    void push2(int data)
    {
        if (top2 - top1 == 1)
        {
            cout << "ERROR : Stack Overflow in stack 2, no space to insert." << endl;
            return;
        }
        else
        {
            top2--;
            arr[top2] = data;
        }
    }
    void pop2()
    {
        if (top2 == size)
        {
            cout << "ERROR : Stack Underflow in stack 2, no element present to pop." << endl;
            return;
        }
        else
        {
            top2++;
        }
    }

    void print()
    {
        cout << endl;
        cout << top1 << endl;
        cout << top2 << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s(10);

    s.push1(10);
    s.print();
    s.push2(20);
    s.print();
    s.push1(30);
    s.print();
    s.push2(40);
    s.print();
    s.push1(50);
    s.print();
    s.push2(60);
    s.print();

    s.pop1();
    s.print();
    s.pop2();
    s.print();
    return 0;
}