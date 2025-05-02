#include <iostream>
#include <algorithm>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *treeBuilder(node *root)
{
    int data;
    cout << "Enter the element : ";
    cin >> data;

    if (data == -1)
    {
        return;
    }

    root = new node(data);

    cout << "Currently inserting on the left side of " << root->data << endl;
    root->left = treeBuilder(root->left);

    cout << "Currently inserting on the right side of " << root->data << endl;
    root->right = treeBuilder(root->right);

    return root;
}

int findDepth(node *root)
{
    if (root == NULL)
    {
        return;
    }

    int leftDepth = findDepth(root->left);
    int rightDepth = findDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

int main()
{
    node *root(NULL);
    root = treeBuilder(root);
    int depth = findDepth(root);

    cout << "The depth of this binary tree is : " << depth << endl;
    return 0;
}