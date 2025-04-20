#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &s, int &data)
{
    if (s.size() == 0)
    {
        s.push(data);
        return;
    }

    int temp = s.top();
    s.pop();

    insertAtBottom(s, data);

    s.push(temp);
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

    int nodeToInsert = s.top();
    s.pop();

    cout << "Size before insertion : " << s.size() << endl;

    insertAtBottom(s, nodeToInsert);

    cout << "Top element of the stack is : " << s.top() << endl;
    cout << "Size after insertion : " << s.size() << endl;

    // If the top element is 60 then we have successfully inserted the previous top value at the bottom of the stack

    return 0;
}