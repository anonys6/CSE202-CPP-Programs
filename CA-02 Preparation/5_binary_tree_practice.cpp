/*
no of child possible at level n = 2 ^ n

maximun number of nodes at level n = 2^(n + 1) - 1


*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    }
    else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

Node* createBinaryTree() {
    Node* root = NULL;
    int n;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the values of the nodes: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        root = insertNode(root, data);
    }
    return root;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node* root = createBinaryTree();

    return 0;
}



