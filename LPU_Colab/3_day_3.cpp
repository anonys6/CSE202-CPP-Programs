#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

Node *merge(Node *left, Node *right)
{
    Node *result = nullptr;

    if (left == nullptr)
    {
        return right;
    }
    if (right == nullptr)
    {
        return left;
    }
    if (left->data <= right->data)
    {
        result = left;
        result->next = merge(left->next, right);
    }
    else
    {
        result = right;
        result->next = merge(left, right->next);
    }
    return result;
}

void split(Node *source, Node **front, Node **back)
{
    Node *slow = source;
    Node *fast = source->next;
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

void mergeSort(Node **headRef)
{
    Node *head = *headRef;
    Node *left;
    Node *right;
    if (head == nullptr || head->next == nullptr)
    {
        return;
    }
    split(head, &left, &right);
    mergeSort(&left);
    mergeSort(&right);
    *headRef = merge(left, right);
}

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "N = ";
    cin >> n;

    Node *head = nullptr;
    Node *temp = nullptr;

    cout << "value[] = ";
    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        Node *newNode = new Node(data);
        if (head == nullptr)
        {
            head = newNode;
            temp = head;
        }
        else
        {
            temp->next = newNode;
            temp = temp->next;
        }
    }

    mergeSort(&head);
    printList(head);

    return 0;
}
