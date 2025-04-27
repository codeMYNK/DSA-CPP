

#include <iostream>
#include <queue>

using namespace std;

class Solution
{
public:
    queue<int> rearrangeQueue(queue<int> q)
    {

        int n = q.size();
        if (n == 0)
        {
            return q;
        }
        int k = n / 2;
        int count = 0;
        queue<int> q2;

        while (!q.empty())
        {
            int data = q.front();
            q.pop();
            q2.push(data);
            count++;

            if (count == k)
            {
                break;
            }
        }

        while (!q.empty() && !q2.empty())
        {
            int first = q2.front();
            q2.pop();
            q.push(first);

            int second = q.front();
            q.pop();
            q.push(second);
        }

        if (n & 1)
        {
            int element = q.front();
            q.pop();
            q.push(element);
        }
    }
};