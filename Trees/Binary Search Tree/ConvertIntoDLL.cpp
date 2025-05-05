#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

class Solution
{
    void convertIntoSortedDLL(Node *root, Node *&head)
    {
        if (root == NULL)
            return;

        convertIntoSortedDLL(root->right, head);
        root->right = head;

        if (head != NULL)
            head->left = root;

        head = root;

        convertIntoSortedDLL(root->left, head);
    }
};