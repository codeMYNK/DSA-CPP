// Leetcode Problem No : 876 - Middle of a linked list (Easy)

/*
Given the head of a singly linked list, return the middle node of the linked list.

If there are two middle nodes, return the second middle node.



Example 1:


Input: head = [1,2,3,4,5]
Output: [3,4,5]
Explanation: The middle node of the list is node 3.
Example 2:


Input: head = [1,2,3,4,5,6]
Output: [4,5,6]
Explanation: Since the list has two middle nodes with values 3 and 4, we return the second one.


Constraints:

The number of nodes in the list is in the range [1, 100].
1 <= Node.val <= 100

Approach : Used Tortoise algo to solve this , where we have two pointers called fast and slow, fast increments twice
first then is followed by the 1 incrementation of slow pointer, once the fast increment becomes null
the slow pointer is standing on the mid element of ll.

Key takeaway : The question demands to return the second middle element in even cases, however if we want to return
the first one we can just intitialise fast as head -> next;
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
    ListNode *getMiddleNode(ListNode *&head)
    {
        if (head == NULL)
        {
            cout << "The given LL is empty" << endl;
            return head;
        }
        if (head->next == NULL)
        {
            return head;
        }
        ListNode *slow = head;
        ListNode *fast = head;
        while (slow != NULL && fast != NULL)
        {
            fast = fast->next;
            if (fast != NULL)
            {
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

public:
    ListNode *middleNode(ListNode *head)
    {
        head = getMiddleNode(head);
        return head;
    }
};