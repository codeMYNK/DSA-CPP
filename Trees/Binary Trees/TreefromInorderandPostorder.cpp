// Leetcode Problem no - 106 : Construct Binary Tree from Inorder and Postorder traversal(Medium)

/*
Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.



Example 1:


Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: inorder = [-1], postorder = [-1]
Output: [-1]


Constraints:

1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder and postorder consist of unique values.
Each value of postorder also appears in inorder.
inorder is guaranteed to be the inorder traversal of the tree.
postorder is guaranteed to be the postorder traversal of the tree.

*/
#include <iostream>
#include <vector>
#include <map>

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
    void createMapping(vector<int> &inorder, map<int, int> &nodeToIndex, int n)
    {
        for (int i = 0; i < n; i++)
        {
            nodeToIndex[inorder[i]] = i;
        }
    }
    TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int &index, int inorderStart, int inorderEnd, int n, map<int, int> &nodeToIndex)
    {
        if (index < 0 || inorderStart > inorderEnd)
        {
            return NULL;
        }

        int element = postorder[index--];

        TreeNode *root = new TreeNode(element);
        int pos = nodeToIndex[element];

        root->right = solve(inorder, postorder, index, pos + 1, inorderEnd, n, nodeToIndex);
        root->left = solve(inorder, postorder, index, inorderStart, pos - 1, n, nodeToIndex);

        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        int n = postorder.size();
        int postOrderIndex = n - 1;
        map<int, int> nodeToIndex;

        createMapping(inorder, nodeToIndex, n);

        TreeNode *ans = solve(inorder, postorder, postOrderIndex, 0, n - 1, n, nodeToIndex);

        return ans;
    }
};