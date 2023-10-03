#include <iostream>

using namespace std;

struct Node{
    string data;
    Node* next;
};

void at_end(Node** head_ref, string val) {
    Node* newNode = new Node();
    Node* last = *head_ref;

    newNode->data = val;
    newNode->next = NULL;

    if(*head_ref == NULL) {
        *head_ref = newNode;
    } else {
        while(last->next != NULL) {
            last = last -> next;
        }
        last->next = newNode;
    }
}

void in_middle(Node** head_ref, string val, int pos) {
    Node* newNode = new Node();
    Node* current = *head_ref;
    newNode->data = val;

    for(int i = 0; i < pos - 2; i++) {
        current = current->next;
    }
    
    newNode->next = current->next;
    current->next = newNode;
    newNode->next = current->next->next;
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
    int n, pos;
    string val;
    cin >> n;

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        cin >> val;
        at_end(&head, val);
    }

    cout << "Current Linked List:" << endl;
    print_list(head);

    cin >> val >> pos;

    in_middle(&head, val, pos);

    cout << endl << "Updated Linked List:" << endl;
    print_list(head);
    
    return 0;
}