#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

int main() {
    Node *first = new Node(1);
    Node *second = new Node(2);

    Node *head = first;

    cout << first << " " << first->data << " " << first->next << endl;

    first->next = second;
    cout << first << " " << first->next->data << " " << first->next->next
         << endl;

    // LInked list size

    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }

    cout << "Size: " << count << endl;

    return 0;
}