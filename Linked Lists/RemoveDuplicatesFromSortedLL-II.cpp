// Leetcode Problem No : 82 - Remove Duplicate Elements From Sorted LL (Medium)

/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.



Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]


Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;
        ListNode *curr = head;

        while (curr)
        {

            if (curr->next && curr->val == curr->next->val)
            {

                while (curr->next && curr->val == curr->next->val)
                {
                    ListNode *temp = curr;
                    curr = curr->next;
                    delete temp;
                }

                ListNode *temp = curr;
                curr = curr->next;
                delete temp;
                prev->next = curr;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
};
