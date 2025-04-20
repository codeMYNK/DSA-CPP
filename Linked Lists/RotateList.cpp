// Leetcode Problem No - 61 : Rotate List(Medium)

/*
Given the head of a linked list, rotate the list to the right by k places.



Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]
Example 2:


Input: head = [0,1,2], k = 4
Output: [2,0,1]


Constraints:

The number of nodes in the list is in the range [0, 500].
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/

#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    int getLen(ListNode *&head)
    {
        ListNode *temp = head;
        int len = 0;
        while (temp)
        {
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head)
            return 0;

        int len = getLen(head);
        int actualRotateK = (k % len);
        if (actualRotateK == 0)
        {
            return head;
        }
        int newLastNodePos = len - actualRotateK - 1;
        ListNode *newLastNode = head;
        for (int i = 0; i < newLastNodePos; i++)
        {
            newLastNode = newLastNode->next;
        }
        ListNode *newHead = newLastNode->next;
        newLastNode->next = 0;
        ListNode *it = newHead;
        while (it->next != NULL)
        {
            it = it->next;
        }
        it->next = head;
        return newHead;
    }
};