#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

void print_tree(Node* root) {
    if (root == NULL) {
        return ;
    }

    cout << root->data << " ";    
    print_tree(root->left);
    print_tree(root->right);
}


int main()
{
    Node* root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left ->left = new Node(4);
    root->left->right = new Node(5);

    // cout << root->left->left << endl;

    print_tree(root);
    
    return 0;
}