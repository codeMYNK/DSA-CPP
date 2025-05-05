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

bool findNodeInBST(Node *root, int target)
{
    if (root == NULL)
        return false;

    if (root->data == target)
        return true;
    if (target > root->data)
    {
        return findNodeInBST(root->right, target);
    }
    else
    {
        return findNodeInBST(root->left, target);
    }
}

Node *insertIntoBST(Node *root, int data)
{
    if (root == NULL)
    {
        root = new Node(data);
        return root;
    }

    if (root->data > data)
    {
        insertIntoBST(root->left, data);
    }
    else
    {
        insertIntoBST(root->right, data);
    }

    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        Node *root = insertIntoBST(root, data);
        cin >> data;
    }
}

int main()
{

    Node *root = NULL;
    cout << "Enter the nodes for the BST: " << endl;
    takeInput(root);

    cout << "Enter the value you want to search for: ";
    int userInput;
    cin >> userInput;
    bool isPresent = findNodeInBST(root, userInput);

    if (isPresent)
    {
        cout << "The value is present!" << endl;
    }
    else
    {
        cout << "The searched value is not present!" << endl;
    }

    return 0;
}