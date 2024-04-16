#include <iostream>

using namespace std;

struct Node {
    Node *next;
    int data;
};

void at_end(Node **head_ref, int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->next = NULL;
    Node *last = *head_ref;
    newNode->data = val;
    if (head_ref == NULL) {
        *head_ref = newNode;
        return;
    } else {
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

void reverse_in_interval(Node **head_ref, int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *current = *head_ref;
    newNode->next = current->next;
    current->next = newNode;
    newNode->next = current->next->next;
}

void print_list(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data;
        temp = temp->next;
    }
}

int main() {
    int n, val;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++) {
        cin >> val;
        at_end(&head, val);
    }
    cout << "Original Linked List: ";
    print_list(head);
    cin >> val;
    reverse_in_interval(&head, val);
    cout << endl << "Modified Linked List: ";
    print_list(head);
    return 0
}