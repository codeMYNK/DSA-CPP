
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
    }
    ~Node()
    {
        cout << "Node deleted successfully" << endl;
    }
};

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *sort(Node *&head)
{
    // create dummy nodes
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *curr = head;
    while (curr != NULL)
    {
        if (curr->data == 0)
        {
            // appending the numbers to their respective ll's
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (curr->data == 1)
        {
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            oneTail->next = temp;
            oneTail = temp;
        }
        else if (curr->data == 2)
        {
            Node *temp = curr;
            curr = curr->next;
            temp->next = NULL;

            twoTail->next = temp;
            twoTail = temp;
        }
    }

    // remove dummy nodes
    Node *temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    // join all lls
    if (oneHead != NULL)
    {
        zeroTail->next = oneHead;
        if (twoHead != NULL)
        {
            oneTail->next = twoHead;
        }
    }
    else
    {
        zeroTail->next = twoHead;
    }

    // removing zeroHead's dummy node
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;
    // return head
    return zeroHead;
}

int main()
{
    Node *head = new Node(0);
    Node *first = new Node(2);
    Node *second = new Node(1);
    Node *third = new Node(2);
    Node *fourth = new Node(0);
    Node *fifth = new Node(1);
    head->next = first;
    first->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    cout << "Input Linked List :" << endl;
    print(head);

    head = sort(head);
    cout << "Sorted Linked List :" << endl;
    print(head);
    return 0;
}