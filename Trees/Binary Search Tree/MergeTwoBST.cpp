// Gfg Problem - Merge Two BST (Medium)

/*
Given two BSTs, return elements of merged BSTs in sorted form.

Examples :

Input: root1 = [5, 3, 6, 2, 4]
       5
     /   \
    3     6
   / \
  2   4
root2 = [2, 1, 3, N, N, N, 7, 6, N]
        2
      /   \
     1     3
            \
             7
            /
           6
Output: [1, 2, 2, 3, 3, 4, 5, 6, 6, 7]
Explanation: After merging and sorting the two BST we get [1, 2, 2, 3, 3, 4, 5, 6, 6, 7].
Input: root1 = [12, 9, N, 6, 11]
       12
     /
    9
   / \
  6   11
root2 = [8, 5, 10, 2]
      8
    /  \
   5    10
  /
 2
Output: [2, 5, 6, 8, 9, 10, 11, 12]
Explanation: After merging and sorting the two BST we get [2, 5, 6, 8, 9, 10, 11, 12].
Constraints:
1 ≤ number of nodes, root->data ≤ 105
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
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
    void inorderTraverse(Node *root, vector<int> &ans)
    {
        if (root == NULL)
        {
            return;
        }

        inorderTraverse(root->left, ans);
        ans.push_back(root->data);
        inorderTraverse(root->right, ans);
    }

    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
        // Your code here
        vector<int> ans;
        inorderTraverse(root1, ans);
        inorderTraverse(root2, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};