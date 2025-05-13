// GfG Problem : Check if Circular Linked List(Easy)

/*
Given the head, the head of a singly linked list, Returns true if the linked list is circular & false if it is not circular.

A linked list is called circular if it is not NULL terminated and all nodes are connected in the form of a cycle.

Note: The linked list does not contain any inner loop.

Examples:

Input:

Output: true
Explanation: As shown in figure the first and last node is connected, i.e. 5 --> 2
Input:

Output: false
Explanation: As shown in figure this is not a circular linked list.
Constraints:
1 <= number of nodes <= 100
1 <= node -> data <= 104
*/

#include <iostream>
#include <unordered_map>

using namespace std;

struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class Solution
{
public:
    bool isCircular(Node *head)
    {
        // Your code here
        if (!head)
            return true;
        unordered_map<Node *, bool> mp;
        Node *temp = head;

        while (temp != NULL)
        {
            if (mp[temp])
                return true;
            mp[temp] = true;
            temp = temp->next;
        }
        return false;
    }
};