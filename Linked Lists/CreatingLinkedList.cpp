#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        cout << "Node deleted sucessfully." << endl;
    }
};

int findLength(Node *&head)
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
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
    Node *newNode = new Node(data);
    if (tail == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(int data, int position, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
    }

    if (position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }

    int len = findLength(head);

    if (position >= len)
    {
        insertAtTail(head, tail, data);
    }

    int i = 1;
    Node *prev = head;
    while (i < position)
    {
        prev = prev->next;
        i++;
    }
    Node *current = prev->next;

    Node *newNode = new Node(data);

    newNode->next = current;
    prev->next = newNode;
}

void deleteNode(int position, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "Cannot delete from an empty Linked List" << endl;
        return;
    }

    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    int len = findLength(head);

    if (position == len)
    {
        Node *prev = head;
        int i = 1;
        while (i < position - 1)
        {
            prev = prev->next;
            i++;
        }
        prev->next = NULL;

        Node *temp = tail;
        tail = prev;
        delete (temp);
        return;
    }

    int i = 1;
    Node *prev = head;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }
    Node *current = prev->next;

    prev->next = current->next;
    current->next = NULL;
    delete current;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;
    Node *tail = nullptr;

    // Insert at head
    insertAtHead(head, tail, 90);
    insertAtHead(head, tail, 60);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 25);

    cout << "After head insertions: ";
    print(head);

    // Insert at tail
    insertAtTail(head, tail, 100);
    insertAtTail(head, tail, 120);

    // Insert at a specific position
    insertAtPosition(1000, 4, head, tail);

    cout << "After tail insertions: ";
    print(head);

    return 0;
}
