// GFG Problem : Is Binary Tree Heap (Medium)

/*
You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

A binary tree is considered a max-heap if it satisfies the following conditions:

Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
Max-Heap Property: The value of each node is greater than or equal to the values of its children.
Examples:

Input: root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]

Output: true
Explanation: The tree is complete and satisfies the max-heap property.
Input: root[] = [97, 46, 37, 12, 3, 7, 31, N, 2, 4]

Output: false
Explanation: The tree is not complete and does not follow the Max-Heap Property, hence it is not a max-heap.
Constraints:
1 ≤ number of nodes ≤ 103
1 ≤ node->data ≤ 103


*/

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    int countNodes(Node *root)
    {
        if (root == NULL)
            return 0;

        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }

    bool isCBT(Node *root, int index, int cnt)
    {
        if (root == NULL)
            return true;

        if (index >= cnt)
        {
            return false;
        }
        else
        {
            bool left = isCBT(root->left, 2 * index + 1, cnt);
            bool right = isCBT(root->right, 2 * index + 2, cnt);
            return left && right;
        }
    }
    bool isMaxOrder(Node *root)
    {
        if (root->left == NULL && root->right == NULL)
            return true;
        if (root->right == NULL)
        {
            return (root->data > root->left->data);
        }
        else
        {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
            if (left && right && (root->data > root->left->data && root->data > root->right->data))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    bool isHeap(Node *tree)
    {
        // code here
        int index = 0;
        int totalCount = countNodes(tree);

        if (isCBT(tree, index, totalCount) && isMaxOrder(tree))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};