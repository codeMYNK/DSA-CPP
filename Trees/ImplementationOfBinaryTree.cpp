#include <iostream>

using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    int data;
    cout << "Enter the data : " << endl;
    cin >> data;

       if (data == -1)
    {
        return NULL;
    }
    root = new node(data);

    cout << "Enter the data for inserting in left : " << endl;
    root->left = buildTree(root->left);

    cout << "Enter the data for inserting in right : " << endl;
    root->right = buildTree(root->right);

    return root;
}

int main()
{
    node *root = NULL;

    root = buildTree(root);

    return 0;
}