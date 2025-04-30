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
    int height(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        int ans = max(leftHeight, rightHeight) + 1;
        return ans;
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
        {
            return true;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        int diff = abs(leftHeight - rightHeight);

        bool ans1 = (diff <= 1);

        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        if (ans1 && leftAns && rightAns)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};