#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

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
        last->next = newNode;
    }
}

void node_sum (Node** head_ref, int val) {
    int sum = 0;
    int len = 0;
    Node* temp = *head_ref;

    while(temp != NULL) {
        len++;
        temp = temp->next;
    }

    temp = *head_ref;

    for (int i = 0; i < len - val; i++) {
        temp = temp -> next;
    }

    while(temp != NULL) {
        sum = sum + temp->data;
        temp = temp->next;
    }

    cout << sum;
}


int main()
{
    int n, val;
    cin >> n;

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        cin >> val;
        at_end(&head, val);
    }

    cin >> val;

    node_sum(&head, val);
    
    return 0;
}