#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push_back(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = *head_ref;

    if (*head_ref != NULL)
    {
        Node *temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = new_node;
    }
    else
    {
        new_node->next = new_node;
        *head_ref = new_node;
    }
}

void insertAtIndex(Node **head_ref, int index, int value)
{
    if (index < 0 || (*head_ref == NULL && index > 0))
    {
        cout << "Invalid position." << endl;
        return;
    }

    if (index == 0)
    {
        push_back(head_ref, value);
        return;
    }

    Node *current = *head_ref;

    for (int i = 0; current != NULL && i < index - 1; i++)
        current = current->next;

    if (current == NULL)
    {
        cout << "Invalid position." << endl;
        return;
    }

    Node *new_node = new Node();
    new_node->data = value;
    new_node->next = current->next;
    current->next = new_node;
}

int countNodes(Node *head)
{
    if (head == NULL)
        return 0;

    int count = 0;

    Node *temp = head;

    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);

    return count;
}

void printList(Node *head)
{
    if (head == NULL)
        return;

    Node *temp = head;

    do
    {
        cout << "|" << temp->data << "| --> ";
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    int n1, n2, val, index;

    cin >> n1;

    string str_val;

    getline(cin, str_val);

    Node *head = NULL;

    for (int i = 0; i < n1; i++)
    {
        cin >> val;
        push_back(&head, val);
    }

    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return 0;
    }

    cin >> val;

    insertAtIndex(&head, countNodes(head) / 2, val);

    cout << "After inserting at middle:" << endl;

    printList(head);

    cout << endl
         << "No of nodes in the CLL is " << countNodes(head) << endl;

    cin >> index >> val;

    insertAtIndex(&head, index, val);

    cout << "After inserting at position:" << endl;

    printList(head);

    cout << endl
         << "No of nodes in the CLL is " << countNodes(head) << endl;

    return 0;
}


