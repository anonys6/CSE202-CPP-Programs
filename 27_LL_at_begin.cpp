#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert_at_begin(Node **head_ref, int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

void print_list(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp -> next;
    }
}




int main() {
    int n;
    cin >> n;

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insert_at_begin(&head, val);
    }

    print_list(head);

    return 0;
}