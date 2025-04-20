#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> st;

    // Insertion
    st.push(40);
    st.push(20);
    st.push(10);
    st.push(5);

    // Deletion of elements - Happens in the LIFO order

    st.pop();

    // Checking the current element on top of the stack
    cout << "Element on top is : " << st.top() << endl;

    // Checking size
    cout << "Size of the stack is : " << st.size() << endl;

    // Checking if the stack is empty or not

    if (st.empty())
    {
        cout << "The stack is empty." << endl;
    }
    else
    {
        cout << "The stack is not empty" << endl;
    }

    // Printing a stack

    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    cout << "Elements in the s stack are : ";

    while (!s.empty())
    {
        cout << s.top() << " " << endl;
        s.pop();
    }

    return 0;
}