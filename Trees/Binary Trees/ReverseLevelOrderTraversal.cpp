#include <iostream>
#include <stack>
#include <queue>

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

node *treeBuilder(node *root)
{
    int data;
    cout << "Enter the data : " << endl;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }
    root = new node(data);

    cout << "Enter the data to insert in left of " << root->data << " :" << endl;
    root->left = treeBuilder(root->left);

    cout << "Enter the data to insert in right of " << root->data << " :" << endl;
    root->right = treeBuilder(root->right);

    return root;
}

void print(stack<int> st)
{
    while (!st.empty())
    {
        int temp = st.top();
        st.pop();
        cout << temp << " ";
    }
}

void reverseLevelOrderTraversal(node *root)
{
    if (root == NULL)
        return;

    queue<node *> q;
    stack<int> st;

    q.push(root);

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        st.push(temp->data);

        if (temp->right)
        {
            q.push(temp->right);
        }
        if (temp->left)
        {
            q.push(temp->left);
        }
    }

    print(st);
}

int main()
{
    node *root = NULL;
    root = treeBuilder(root);
    reverseLevelOrderTraversal(root);

    return 0;
}