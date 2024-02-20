#include <iostream>

using namespace std;

struct Node {
    string data;
    Node *next;
};

void at_end(Node **head_ref, int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *last = *head_ref;
    newNode->data = val;
    newNode->next = NULL;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return;
    } else {
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

void print_list(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void delete_second_last(Node **head_ref) {
    Node *current = *head_ref;
    Node *temp = NULL;

    while (current->next->next != NULL) {
        current = current->next;
    }
    temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void delete_last(Node **head_ref) {
    Node *current = *head_ref;
    Node *temp = NULL;

    while (current->next->next != NULL) {
        current = current->next;
    }
    temp = current->next;
    current->next = current->next->next;
    free(temp);
}

void delete_n_to_m(Node **head_ref, int n, int m) {
    Node *current = *head_ref;
    Node *temp = NULL;

    for (int i = 0; i < n - 1; i++) {
        current = current->next;
    }
    temp = current->next;
    for (int i = 0; i < m - n + 1; i++) {
        current->next = current->next->next;
        free(temp);
    }
}

int main() {
    int n;
    cin >> n;

    Node *head = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        at_end(&head, val);
    }

    print_list(head);

    return 0;
}

void at_middle(Node **head_ref, int val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *current = *head_ref;

    newNode->next = current->next;
    current->next = newNode;
    newNode->next = current->next->next;
}

void append_in_second(Node **head_ref, int data_val) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    Node *current = *head_ref;
    newNode->data = data_val;

    newNode->next = current->next;
    current->next = newNode;
    newNode->next = current->next->next;
}