#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Deleted the node successfully." << endl;
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
    cout << endl;
}

int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);

    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
}

void insertAtPosition(int position, Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        return;
    }
    if (position == 1)
    {
        insertAtHead(head, tail, data);
        return;
    }
    int len = getLength(head);

    if (position >= len)
    {
        insertAtTail(head, tail, data);
        return;
    }

    int i = 1;
    Node *previous = head;

    while (i < position - 1)
    {
        previous = previous->next;
        i++;
    }
    Node *current = previous->next;

    Node *newNode = new Node(data);

    newNode->prev = previous;
    previous->next = newNode;
    newNode->next = current;
    current->prev = newNode;
    current = newNode;
}

void deleteAtPosition(int position, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Cannot delete in an empty linked list" << endl;
    }

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = getLength(head);

    if (position == len)
    {
        Node *temp = tail;
        tail = tail->prev;
        temp->prev = NULL;
        delete temp;
        return;
    }

    int i = 1;
    Node *previous = head;

    while (i < position - 1)
    {
        previous = previous->next;
        i++;
    }

    Node *current = previous->next;
    Node *ahead = current->next;

    ahead->prev = previous;
    previous->next = ahead;
    current->next = NULL;
    current->prev = NULL;
    delete current;
}

int main()
{
    Node *first = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    Node *head = first;
    Node *tail = third;

    first->next = second;
    second->prev = first;

    second->next = third;
    third->prev = second;

    insertAtHead(head, tail, 5);
    insertAtTail(head, tail, 35);
    insertAtPosition(3, head, tail, 15);

    print(head);
    deleteAtPosition(4, head, tail);
    cout << endl;
    print(head);
    return 0;
}