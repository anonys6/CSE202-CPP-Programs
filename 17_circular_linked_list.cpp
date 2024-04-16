#include <iostream>
using namespace std;

// Define a node struct to hold data and a pointer to the next node
struct Node {
    int data;
    Node* next;
};

// Define a class for the circular linked list
class CircularLinkedList {
private:
    Node* head; // Pointer to the head of the list
public:
    // Constructor to initialize the head to null
    CircularLinkedList() {
        head = NULL;
    }

    // Function to add a node to the end of the list
    void addNode(int data) {
        // Create a new node with the given data
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;

        // If the list is empty, set the head to the new node
        if (head == NULL) {
            head = newNode;
            head->next = head; // Make the node point to itself to create a circular list
        }
        else {
            // Traverse the list to find the last node
            Node* current = head;
            while (current->next != head) {
                current = current->next;
            }

            // Add the new node to the end of the list
            current->next = newNode;
            newNode->next = head; // Make the new node point to the head to create a circular list
        }
    }

    // Function to display the contents of the list
    void displayList() {
        // If the list is empty, print a message and return
        if (head == NULL) {
            cout << "List is empty" << endl;
            return;
        }

        // Traverse the list and print each node's data
        Node* current = head;
        do {
            cout << current->data << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

// Main function to test the circular linked list
int main() {
    CircularLinkedList list;

    // Add some nodes to the list
    list.addNode(1);
    list.addNode(2);
    list.addNode(3);
    list.addNode(4);

    // Display the contents of the list
    list.displayList();

    return 0;
}


