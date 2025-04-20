#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &s, int &data)
{
    if (s.empty())
    {
        s.push(data);
        return;
    }

    int temp = s.top();
    s.pop();
    insertAtBottom(s, data);

    s.push(temp);
}

void reverseStack(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int topEl = s.top();
    s.pop();

    reverseStack(s);

    insertAtBottom(s, topEl);
}

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    s.push(70);

    reverseStack(s);

    cout << "After Reversing: " << endl;
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}