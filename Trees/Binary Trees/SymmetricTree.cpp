// Leetcode Problem No - 101 : Symmetric Trees(Easy)

/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).



Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false


Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100


Follow up: Could you solve it both recursively and iteratively?
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
    bool isMirror(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;

        if (p && q)
        {
            return (p->val == q->val) && isMirror(p->left, q->right) && isMirror(p->right, q->left);
        }
        return false;
    }
    bool isSymmetric(TreeNode *root)
    {
        return isMirror(root->left, root->right);
    }
};