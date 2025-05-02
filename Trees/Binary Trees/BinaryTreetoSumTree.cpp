#include <iostream>

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

int convertIntoSumTree(node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftAns = convertIntoSumTree(root->left);
    int rightAns = convertIntoSumTree(root->right);
    root->data = leftAns + root->data + rightAns;
    return root->data;
}

int main()
{
    node *root = NULL;

    int sumTreeAns = convertIntoSumTree(root);

    cout << "The value of the root node of the sum tree is : " << sumTreeAns;

    return 0;
}