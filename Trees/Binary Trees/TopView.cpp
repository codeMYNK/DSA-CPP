// GfG Problem : Top View of Binary Tree (Medium)

/*
You are given a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.

Note:

Return the nodes from the leftmost node to the rightmost node.
If two nodes are at the same position (horizontal distance) and are outside the shadow of the tree, consider the leftmost node only.
Examples:

Input: root[] = [1, 2, 3]

Output: [2, 1, 3]
Input: root[] = [10, 20, 30, 40, 60, 90, 100]

Output: [40, 20, 10, 30, 100]
Explanation: The root 10 is visible.
On the left, 40 is the leftmost node and visible, followed by 20.
On the right, 30 and 100 are visible. Thus, the top view is 40 20 10 30 100.
Input: root[] = [1, 2, 3, N, 4, N, N, N, 5, N, 6]
       1
     /   \
    2     3
     \
      4
       \
        5
         \
          6
Output: [2, 1, 3, 6]
Explanation: Node 1 is the root and visible.
Node 2 is the left child and visible from the left side.
Node 3 is the right child and visible from the right side.
Nodes 4, 5, and 6 are vertically aligned, but only the lowest node 6 is visible from the top view. Thus, the top view is 2 1 3 6.
Constraints:
1 ≤ number of nodes ≤ 105
1 ≤ node->data ≤ 105

*/

#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        // code here
        vector<int> ans;
        if (root == NULL)
            return ans;
        map<int, int> topNode;
        queue<pair<Node *, int>> q;

        q.push(make_pair(root, 0));

        while (!q.empty())
        {
            pair<Node *, int> temp = q.front();
            q.pop();
            Node *topElement = temp.first;
            int hd = temp.second;

            // If one value is present then do nothing
            if (topNode.find(hd) == topNode.end())
            {
                topNode[hd] = topElement->data;
            }
            if (topElement->left)
            {
                q.push(make_pair(topElement->left, hd - 1));
            }
            if (topElement->right)
                q.push(make_pair(topElement->right, hd + 1));
        }
        for (auto i : topNode)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
