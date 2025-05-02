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
    cout << "Enter the value : ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new node(data);

    cout << "This element will be inserted as the left child of : " << root->data;
    root->left = treeBuilder(root->left);

    cout << "This element will be inserted as the right child of : " << root->data;
    root->right = treeBuilder(root->right);
    return root;
}

int findHeight(node *root)
{
    if (root == NULL)
    {
        return;
    }

    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int findDiameter(node *root)
{
    if (root == NULL)
    {
        return;
    }

    int leftSideDiameter = findDiameter(root->left);
    int rightSideDiameter = findDiameter(root->right);
    int maxHeight = findHeight(root->left) + findHeight(root->right) + 1;
    return max(leftSideDiameter, max(rightSideDiameter, maxHeight));
}

int main()
{
    node *root = NULL;

    root = treeBuilder(root);

    int diameter = findDiameter(root);

    return 0;
}