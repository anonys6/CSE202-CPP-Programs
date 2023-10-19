#include <iostream>

using namespace std;

struct Node {
    string data;
    Node* next;
};

void at_end (Node** head_ref, string val) {
    Node* newNode = new Node();
    Node* last = *head_ref;
    newNode -> data = val;

    if (*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        while (last->next != NULL) {
            last = last -> next;
        }
        last -> next = newNode;
    }
}

void remove_alternate (Node* head) {
    Node* temp = head;
    // Node* prev = head;
    // Node* now = head -> next;

    int ll = 0;

    while (temp != NULL) {
        ll++;
        temp = temp -> next;
    }

    temp = head;

    for (int i = 0; i < ll; i++) {
        if (i % 2 == 0) {
            cout << temp -> data << " ";
        }
        // now = prev -> next;
        // prev = prev -> next;
        temp = temp -> next;
    }
}

void delete_at_begin(Node** head_ref) {
    Node* temp = *head_ref;

    *head_ref = temp->next;

    free(temp);

    // cout << temp->next->data;
}

void delete_at_end(Node** head_ref) {
    Node* temp = *head_ref;

    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}


void print_list (Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}

int main() {
    int n;
    string val;

    struct Node* head = NULL;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> val;
        at_end(&head, val);
    }

    // remove_alternate(head);
    // delete_at_begin(&head);
    delete_at_end(&head);

    print_list(head);
}