// GFG Problem : Delete N Nodes after M nodes in a linked list(Easy)

/*
Given a linked list, delete n nodes after skipping m nodes of a linked list until the last of the linked list.
Examples:

Input: Linked List: 9->1->3->5->9->4->10->1, n = 1, m = 2

Output: 9->1->5->9->10->1

Explanation: Deleting 1 node after skipping 2 nodes each time, we have list as 9-> 1-> 5-> 9-> 10-> 1.
Input: Linked List: 1->2->3->4->5->6, n = 1, m = 6

Output: 1->2->3->4->5->6

Explanation: After skipping 6 nodes for the first time , we will reach of end of the linked list, so, we will get the given linked list itself.
Expected Time Complexity: O(n)
Expected Space Complexity: O(1)

Constraints:
1 <= size of linked list <= 1000
0 < n, m <= size of linked list
*/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    Node *linkdelete(Node *head, int n, int m)
    {
        // code here
        if (!head)
            return 0;
        Node *it = head;
        for (int i = 0; i < m - 1; i++)
        {
            if (!it)
                return 0;
            it = it->next;
        }
        if (!it)
            return 0;
        Node *mthNode = it;
        it = mthNode->next;
        for (int i = 0; i < n; i++)
        {
            if (!it)
                break;

            Node *temp = it->next;
            delete it;
            it = temp;
        }
        mthNode->next = it;
        linkdelete(it, n, m);
        return head;
    }
};