// Gfg Problem : Sort A Stack (Medium)

/*
Given a stack, the task is to sort it such that the top of the stack has the greatest element.

Example 1:

Input:
Stack: 3 2 1
Output: 3 2 1
Example 2:

Input:
Stack: 11 2 32 3 41
Output: 41 32 11 3 2
Your Task:
You don't have to read input or print anything. Your task is to complete the function sort() which sorts the elements present in the given stack. (The sorted stack is printed by the driver's code by popping the elements of the stack.)

Expected Time Complexity: O(N*N)
Expected Auxilliary Space: O(N) recursive.

Constraints:
1<=N<=100
*/

#include <iostream>
#include <stack>

using namespace std;

class SortedStack
{
public:
    stack<int> s;
    void sort();
};

void insertSorted(stack<int> &s, int &target)
{
    if (s.empty())
    {
        s.push(target);
        return;
    }
    if (s.top() <= target)
    {
        s.push(target);
        return;
    }

    int topElement = s.top();
    s.pop();
    insertSorted(s, target);
    s.push(topElement);
}
void sortedStackHelper(stack<int> &s)
{
    if (s.empty())
    {
        return;
    }

    int topElement = s.top();
    s.pop();

    sortedStackHelper(s);
    insertSorted(s, topElement);
}
void SortedStack ::sort()
{
    // Your code here
    sortedStackHelper(s);
}