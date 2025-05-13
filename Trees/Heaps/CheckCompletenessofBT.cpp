// Leetcode Problem No - 958 : Check Completeness of Binary Tree(Medium)

/*
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.



Example 1:


Input: root = [1,2,3,4,5,6]
Output: true
Explanation: Every level before the last is full (ie. levels with node-values {1} and {2, 3}), and all nodes in the last level ({4, 5, 6}) are as far left as possible.
Example 2:


Input: root = [1,2,3,4,5,null,7]
Output: false
Explanation: The node with value 7 isn't as far left as possible.


Constraints:

The number of nodes in the tree is in the range [1, 100].
1 <= Node.val <= 1000
*/

#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    int findCount(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        return 1 + findCount(root->left) + findCount(root->right);
    }
    bool isCBT(TreeNode *root, int index, int cnt)
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
    bool isCompleteTree(TreeNode *root)
    {
        int totalCount = findCount(root);
        return isCBT(root, 0, totalCount);
    }
};