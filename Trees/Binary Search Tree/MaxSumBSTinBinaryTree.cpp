// Leetcode Problem No : 1373 - Max Sum BST in Binary Tree (Hard)

/*
Given a binary tree root, return the maximum sum of all keys of any sub-tree which is also a Binary Search Tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Example 1:



Input: root = [1,4,3,2,4,2,5,null,null,null,null,null,null,4,6]
Output: 20
Explanation: Maximum sum in a valid Binary search tree is obtained in root node with key equal to 3.
Example 2:



Input: root = [4,3,null,1,2]
Output: 2
Explanation: Maximum sum in a valid Binary search tree is obtained in a single root node with key equal to 2.
Example 3:

Input: root = [-4,-2,-5]
Output: 0
Explanation: All values are negatives. Return an empty BST.


Constraints:

The number of nodes in the tree is in the range [1, 4 * 104].
-4 * 104 <= Node.val <= 4 * 104
*/

#include <iostream>
#include <algorithm>
#include <limits.h>

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

class TreeNodeData
{
public:
    int minVal;
    int maxVal;
    int sum;
    bool validBST;

    TreeNodeData(int min, int max, int sum, bool isValidBST)
    {
        this->minVal = min;
        this->maxVal = max;
        this->sum = sum;
        this->validBST = isValidBST;
    }
};
class Solution
{
public:
    TreeNodeData maxSumBSTHelper(TreeNode *root, int &ans)
    {
        if (root == NULL)
        {
            return TreeNodeData(INT_MAX, INT_MIN, 0, true);
        }

        TreeNodeData leftAns = maxSumBSTHelper(root->left, ans);
        TreeNodeData rightAns = maxSumBSTHelper(root->right, ans);

        if (leftAns.validBST && rightAns.validBST && (root->val > leftAns.maxVal && root->val < rightAns.minVal))
        {
            int sum = leftAns.sum + rightAns.sum + root->val;
            ans = max(ans, sum);
            int minVal = min(root->val, leftAns.minVal);
            int maxVal = max(root->val, rightAns.maxVal);
            return TreeNodeData(minVal, maxVal, sum, true);
        }
        return TreeNodeData(INT_MAX, INT_MIN, 0, false);
    }
    int maxSumBST(TreeNode *root)
    {
        int ans = 0;
        maxSumBSTHelper(root, ans);
        return ans;
    }
};