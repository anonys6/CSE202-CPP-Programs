#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* create_node(int val) {
    // Node* newNode = (Node*) malloc(sizeof(Node));
    Node* newNode = new Node();

    if (!newNode) {
        return 0;
    } else {
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
}

Node* insert_node(Node* root, int val) {
    if(root == NULL) {
        return create_node(val);
    } else {
        if (val < root->data) {
            root->left = insert_node(root->left, val);
        } else {
            root->right = insert_node(root->right, val);
        }
    }
    return root;
}

Node* find_largest(Node* root) {
    if (root == NULL || root->right == NULL) {
        return root;
    }
    find_largest(root->right);
}

Node* find_smallest(Node* root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }
    find_smallest(root->left);
}

Node* search(Node* root, int val) {
    if (root == NULL || root->data == val) {
        return root;
    }
    
    if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}






void pre_order(Node* root) {
    if (root == NULL) {
        return ;
    } else {
        cout << root->data << " ";
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(Node* root) {
    if (root == NULL) {
        return ;
    } else {
        in_order(root->left);
        cout << root->data << " ";
        in_order(root->right);
    }
}

void post_order(Node* root) {
    if (root == NULL) {
        return ;
    } else {
        post_order(root->left);
        post_order(root->right);
        cout << root->data << " ";
    }
}

int main() {
    
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, val;
    cin >> n;

    Node* root = NULL;

    // root = create_node(3);

    for(int i = 0; i < n; i++) {
        cin >> val;
        root = insert_node(root, val);
    }

    pre_order(root);
    cout << endl;

    in_order(root);
    cout << endl;

    post_order(root);
    cout << endl;

    cout << "Largest element: " << find_largest(root)->data << endl;
    cout << "Smallest element: " << find_smallest(root)->data << endl;

    if(search(root, 3) == NULL) {
        cout << "Not found" << endl;
    } else {
        cout << "Found" << endl;
    }


    return 0;
}