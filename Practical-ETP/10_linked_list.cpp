#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// void at_begin(Node **head_ref, int val) {
//     Node* newNode = (Node *) malloc(sizeof(Node));

//     newNode->data = val;
//     newNode->next = *head_ref;
//     *head_ref = newNode;
// }


// void at_end(Node **head_ref, int val) {
//     Node* newNode = new Node;
//     Node* last = *head_ref;

//     newNode->data = val;
//     newNode->next = NULL;

//     if (*head_ref == NULL) {
//         *head_ref = newNode;
//         return ;
//     } else {
//         while (last->next != NULL) {
//             last = last->next;
//         }

//         last->next = newNode;
//     }
// }


void at_begin (Node** head_ref, int val) {
    Node* newNode = new Node;

    newNode->data = val;
    newNode->next = *head_ref;
    *head_ref = newNode;
}

void at_end(Node** head_ref, int val) {
    Node* newNode = new Node;
    Node* last = *head_ref;

    newNode->data = val;
    newNode->next = NULL;

    if(*head_ref == NULL) {
        *head_ref = newNode;
        return ;
    } else {
        while(last->next != NULL) {
            last = last->next;
        }
        
        last->next = newNode;
    }
}





void print(Node* head) {
    Node *temp = head;

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, val;
    
    cin >> n;

    Node *head = NULL;

    for (int i = 0; i < n; i++) {
        cin >> val;
        at_end(&head, val);
    }

    print(head);
    
    return 0;
}