// Leetcode Problem No : 98 - Validate Binary Search Tree(Medium)

/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:


Input: root = [2,1,3]
Output: true
Example 2:


Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.


Constraints:

The number of nodes in the tree is in the range [1, 104].
-231 <= Node.val <= 231 - 1
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
    bool solve(TreeNode *&root, long long int lb, long long int ub)
    {
        if (root == NULL)
            return true;
        if (root->val > lb && root->val < ub)
        {
            bool leftAns = solve(root->left, lb, root->val);
            bool rightAns = solve(root->right, root->val, ub);
            return leftAns && rightAns;
        }
        else
        {
            return false;
        }
    }
    bool isValidBST(TreeNode *root)
    {
        long long int lowerBound = -4294967296;
        long long int upperBound = 4294967296;

        bool ans = solve(root, lowerBound, upperBound);
        return ans;
    }
};