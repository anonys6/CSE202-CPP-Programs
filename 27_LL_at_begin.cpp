#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

void insert_at_begin(Node **head_ref, int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

void print_list(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    int n;
    cin >> n;

    Node *head = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insert_at_begin(&head, val);
    }

    print_list(head);

    return 0;
}

void insert_val_at_pos(Node **head_ref, int val, int pos) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;

    if (pos == 0) {
        newNode->next = *head_ref;
        *head_ref = newNode;
        return;
    }

    Node *temp = *head_ref;
    for (int i = 0; i < pos - 1; i++) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void in_middle(Node **head_ref, int val, int pos) {
    Node *newNode = (Node *)malloc(sizeof(Node));

    Node *current = *head_ref;

    newNode->data = val;

    for (int i = 1; i < pos - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    newNode->next = current->next->next;
}

void print_list(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}