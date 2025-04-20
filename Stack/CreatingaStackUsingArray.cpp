#include <iostream>

using namespace std;

class Stack
{
public:
    int *arr;
    int size;
    int top;

    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    void push(int data)
    {
        if (size - top > 1)
        {
            top++;
            arr[top] = data;
        }
        else
        {
            cout << "ERROR: Stack Overflow" << endl;
        }
    }
    void pop()
    {
        if (top == -1)
        {
            cout << "ERROR: Stack Underflow can't delete an empty stack" << endl;
        }
        else
        {
            top--;
        }
    }
    int getTop()
    {
        if (top == -1)
        {
            cout << "ERROR: The Stack is empty" << endl;
            return top;
        }

        return arr[top];
    }
    int getSize()
    {
        return top + 1;
    }
    bool isEmpty()
    {
        if (top == -1)
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
    Stack s(10);

    // Insertion
    s.push(20);
    s.push(40);
    s.push(60);
    s.push(90);

    // Deletion
    s.pop();

    cout << s.getTop() << " -Top element" << endl;

    cout << s.getSize() << " -Current Size of stack" << endl;

    if (s.isEmpty())
    {
        cout << "The stack is empty" << endl;
    }
    else
    {
        cout << "The stack is not empty" << endl;
    }
    return 0;
}