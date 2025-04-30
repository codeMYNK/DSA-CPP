// GFG Problem - Kth Ancestor in a tree (Medium)

/*
Given a binary tree of size  n, a node, and a positive integer k., Your task is to complete the function kthAncestor(), the function should return the kth ancestor of the given node in the binary tree. If there does not exist any such ancestor then return -1.
Note:
1. It is guaranteed that the node exists in the tree.
2. All the nodes of the tree have distinct values.

Examples :

Input: k = 2, node = 4

Output: 1
Explanation:
Since, k is 2 and node is 4, so we first need to locate the node and look k times its ancestors. Here in this Case node 4 has 1 as his 2nd Ancestor aka the root of the tree.
Input: k=1, node=3

Output: 1
Explanation: k=1 and node=3 ,kth ancestor of node 3 is 1.
Constraints:
1<=n<=105
1<= k <= 100
1 <= Node.data <= n


*/

#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
};

int solve(Node *root, int &k, int node, int &ancestor)
{
    if (root == NULL)
        return -1;

    if (root->data == node)
        return 1;

    int left = solve(root->left, k, node, ancestor);
    int right = solve(root->right, k, node, ancestor);

    if (left == 1 || right == 1)
    {
        k--;
        if (k == 0)
        {
            ancestor = root->data;
            return 0;
        }
        return 1;
    }

    return -1;
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ancestor = -1;
    solve(root, k, node, ancestor);
    return ancestor;
}
