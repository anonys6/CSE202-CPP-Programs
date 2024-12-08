#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Define the LinkedList class
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}

    // Method to insert a node at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Method to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int values[5] = {1, 4, 14, 23, 6}; // Example values

    for (int i = 0; i < 5; ++i) {
        list.insertAtEnd(values[i]);
    }

    list.display();

    return 0;
}