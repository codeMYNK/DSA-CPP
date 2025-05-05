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

node *insertintoBST(node *root, int data)
{
    if (root == NULL)
    {
        // this is the first node
        root = new node(data);
        return root;
    }

    if (root->data > data)
    {
        root->left = insertintoBST(root->left, data);
    }
    else
    {
        root->right = insertintoBST(root->right, data);
    }
    return root;
}

void takeInput(node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        node *root = insertintoBST(root, data);
        cin >> data;
    }
}

int main()
{
    node *root = NULL;
    cout << "Enter the elements to add in the BST, enter -1 to stop : " << endl;
    takeInput(root);
    return 0;
}