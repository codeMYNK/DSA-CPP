// Leetcode Problem No : 234 - Palindrome Linked List(Easy)

/*
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.



Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false


Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9


Follow up: Could you do it in O(n) time and O(1) space?
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
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next = curr->next;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    bool checkPalindrome(ListNode *&head)
    {
        if (head == NULL || head->next == NULL)
        {
            return true;
        }
        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        ListNode *reverseLLHead = reverse(slow->next);
        slow->next = reverseLLHead;

        ListNode *temp1 = head;
        ListNode *temp2 = reverseLLHead;

        while (temp2 != NULL)
        {
            if (temp1->val != temp2->val)
            {
                return false;
            }
            else
            {
                temp1 = temp1->next;
                temp2 = temp2->next;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode *head)
    {
        bool result = checkPalindrome(head);
        return result;
    }
};