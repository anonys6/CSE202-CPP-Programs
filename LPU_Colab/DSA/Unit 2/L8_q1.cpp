#include <iostream>

using namespace std;

struct Node {
    string data;
    Node* next;
};

void at_begin(Node** head_ref, string val) {
    // Node* newNode = (Node*) malloc(sizeof(Node));
    Node* newNode = new Node();
    newNode->data = val;
    newNode->next = *head_ref;
    *head_ref = newNode;   
}

void at_end(Node** head_ref, string val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    Node* last = *head_ref;
    newNode->data = val;
    newNode->next = NULL;

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

void print_list (Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main() {
    int n;
    string val;
    cin >> n;

    if (n == 0) {
        cout << "Document: \nUpdated Document:";
        return 0;
    }

    Node* head = NULL;

    for (int i = 0; i < n; i++) {
        cin >> val;
        at_begin(&head, val);
    }

    cout << "Document: ";
    print_list(head);

    cin >> val;
    at_end(&head, val);

    cout << endl << "Updated Document: ";
    print_list(head);
    
    return 0;
}