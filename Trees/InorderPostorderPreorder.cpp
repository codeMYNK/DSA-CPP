/*
Direction of recursive calls in the traversals is always as follows:
InOrder: L -> N -> R
PostOrder: L -> R -> N
PreOrder: N -> L -> R
*/

#include <iostream>
#include <queue>

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
    cout << "Enter the data: ";
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root = new node(data);

    cout << "Enter the data to insert in the left of " << root->data << " :";
    root->left = treeBuilder(root->left);

    cout << "Enter the data to insert in the right of " << root->data << " :";
    root->right = treeBuilder(root->right);
    return root;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    node *root = NULL;
    root = treeBuilder(root);

    cout << "Inorder traversal is : " << endl;
    inorder(root);
    cout << "Preorder traversal is: " << endl;
    preorder(root);
    cout << "Postorder traversal is: " << endl;
    postorder(root);

    return 0;
}