// Leetcode Problem No : 23 - Merge K sorted lists (Hard)

/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.



Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []


Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.
*/

#include <iostream>
#include <queue>

using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class compare
{
public:
  bool operator()(ListNode *a, ListNode *b)
  {
    return a->val > b->val;
  }
};
class Solution
{
public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    priority_queue<ListNode *, vector<ListNode *>, compare> minHeap;

    if (lists.size() == 0)
      return NULL;

    for (int i = 0; i < lists.size(); i++)
    {
      if (lists[i] != NULL)
      {
        minHeap.push(lists[i]);
      }
    }
    ListNode *head = NULL;
    ListNode *tail = NULL;

    while (minHeap.size() > 0)
    {
      ListNode *top = minHeap.top();
      minHeap.pop();
      if (top->next != NULL)
      {
        minHeap.push(top->next);
      }
      if (head == NULL)
      {
        head = top;
        tail = top;
      }
      else
      {
        tail->next = top;
        tail = top;
      }
    }
    return head;
  }
};