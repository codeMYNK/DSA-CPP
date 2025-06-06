// Leetcode Problem No - 110 : Balanced Binary Tree(Easy)

/*
Given a binary tree, determine if it is height-balanced.



Example 1:


Input: root = [3,9,20,null,null,15,7]
Output: true
Example 2:


Input: root = [1,2,2,3,3,null,null,4,4]
Output: false
Example 3:

Input: root = []
Output: true


Constraints:

The number of nodes in the tree is in the range [0, 5000].
-104 <= Node.val <= 104
*/

#include <iostream>
#include <algorithm>

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
    bool isbalanced = true;
    int height(TreeNode *root)
    {
        if (!root)
            return 0;

        int lh = height(root->left);
        int rh = height(root->right);

        if (isbalanced && abs(lh - rh) > 1)
            isbalanced = false;
        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        height(root);
        return isbalanced;
    }
};