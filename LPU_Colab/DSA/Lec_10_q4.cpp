#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

int flag = 0;

void at_end(Node** head_ref, int val) {
    Node* newNode = new Node();
    Node* last = *head_ref;
    newNode->data = val;

    if (*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        while (last->next != NULL) {
            last = last -> next;
        }
        last -> next = newNode;
    }
}

void print_list(Node* head) {
    Node* temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void remove_same(Node* head1, Node* head2) {
    Node* temp1 = head1;
    Node* temp2 = head2;

    while(temp1 != NULL) {
        temp2 = head2;
        int hit = 0;

        while(temp2 != NULL) {
            if (temp1->data == temp2->data) {
                hit = 1;
                break;
            }
            temp2 = temp2->next;
        }
        if (hit == 0) {
            cout << temp1->data << " ";
            flag = 1;
        }
        temp1 = temp1->next;
    }
}

int main() {
    int n, val;
    cin >> n;

    Node* head1 = NULL;
    Node* head2 = NULL;

    for (int i = 0; i < n; i++) {
        cin >> val;
        at_end(&head1, val);
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> val;
        at_end(&head2, val);
    }

    remove_same(head1, head2);

    if (flag == 0) {
        cout << "All elements are same" << endl;
    }
    
}