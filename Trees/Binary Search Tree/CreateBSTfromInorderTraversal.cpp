#include <iostream>
#include <vector>

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

Node *bstusingInorder(vector<int> arr, int s, int e)
{

    if (s > e)
        return NULL;
    int mid = s + (e - s) / 2;
    int element = arr[mid];
    Node *root = new Node(element);

    root->left = bstusingInorder(arr, s, mid - 1);
    root->right = bstusingInorder(arr, mid + 1, e);
    return root;
}

int main()
{

    int userLength;

    cout << "Enter the length of the array of inorder nodes : " << endl;
    cin >> userLength;

    vector<int> inorderLengths(userLength);

    cout << "Enter the values(Warning: The values should be in sorted order)" << endl;

    for (int i = 0; i < userLength; i++)
    {
        cin >> inorderLengths[i];
    }

    Node *root = bstusingInorder(inorderLengths, 0, userLength);
    return 0;
}