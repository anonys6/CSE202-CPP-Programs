#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

void at_the_end(Node** head_ref, int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    Node* last = *head_ref;
    newNode -> data = val;
    newNode -> next = NULL;

    if (*head_ref == NULL) {
        *head_ref = newNode;
        return ;
    } else {
        while(last->next != NULL) {
            last = last->next;
        }
        last->next = newNode;
    }
}

void print_list(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp -> next;
    }
}


int main()
{
    int n;
    cin >> n;

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        at_the_end(&head, val);
    }

    print_list(head);
    
    return 0;
}