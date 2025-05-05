// Gfg Problem - Predecessor and Successor(Medium)

/*
You are given root node of the BST and an integer key. You need to find the in-order successor and predecessor of the given key. If either predecessor or successor is not found, then set it to NULL.

Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor.

Examples :

Input: root[] = [8, 1, 9, N, 4, N, 10, 3, N, N, N]
      8
    /   \
   1     9
   \      \
    4      10
   /
  3
key = 8
Output: 4 9
Explanation: In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.
Input: root[] = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4, N, N]
      10
    /   \
   2     11
  / \
 1   5
    / \
   3   6
    \
     4
key = 11
Output: 10 -1
Explanation: In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.
Input: root[] = [2, 1, 3]
      2
    /   \
   1     3
key = 3
Output: 2 -1
Constraints:
1 <= Number of nodes <= 105
1 <= key <= 106
*/

#include <iostream>

using namespace std;

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
public:
    void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
    {
        pre = NULL;
        suc = NULL;

        while (root != NULL)
        {
            if (root->key == key)
            {

                if (root->left != NULL)
                {
                    Node *temp = root->left;
                    while (temp->right)
                        temp = temp->right;
                    pre = temp;
                }

                if (root->right != NULL)
                {
                    Node *temp = root->right;
                    while (temp->left)
                        temp = temp->left;
                    suc = temp;
                }
                break;
            }
            else if (key < root->key)
            {
                suc = root;
                root = root->left;
            }
            else
            {
                pre = root;
                root = root->right;
            }
        }
    }
};