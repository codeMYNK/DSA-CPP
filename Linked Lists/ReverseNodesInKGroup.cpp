// Leetcode Problem No : 25 - Reverse nodes in k-Group(Hard)

/*
Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.



Example 1:


Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]
Example 2:


Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]


Constraints:

The number of nodes in the list is n.
1 <= k <= n <= 5000
0 <= Node.val <= 1000


Follow-up: Can you solve the problem in O(1) extra memory space?
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
    int getLength(ListNode *&head)
    {
        int len = 0;
        ListNode *temp = head;
        while (temp != NULL)
        {
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode *finalOp(ListNode *&head, int k)
    {
        int len = getLength(head);
        if (head == NULL || k > len)
        {
            return head;
        }
        ListNode *prev = NULL;
        ListNode *current = head;
        ListNode *forward = current->next;
        int count = 0;
        while (count < k)
        {
            forward = current->next;
            current->next = prev;
            prev = current;
            current = forward;
            count++;
        }

        if (forward != NULL)
        {
            head->next = finalOp(forward, k);
        }
        return prev;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        head = finalOp(head, k);
        return head;
    }
};