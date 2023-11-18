#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Node* create_node(int val) {
//     // Node* newNode = (Node*) malloc(sizeof(Node));
//     Node* newNode = new Node();

//     if (!newNode) {
//         return 0;
//     } else {
//         newNode->data = val;
//         newNode->left = NULL;
//         newNode->right = NULL;
//         return newNode;
//     }
// }

Node* create_node(int val) {
    Node* newNode = new Node();

    if (!newNode) {
        return 0;
    } else {
        newNode->data = val;
        newNode->left = NULL;
        newNode->right = NULL;
    }
    return newNode;
}

// Node* insert_node(Node* root, int val) {
//     if(root == NULL) {
//         return create_node(val);
//     } else {
//         if (val < root->data) {
//             root->left = insert_node(root->left, val);
//         } else {
//             root->right = insert_node(root->right, val);
//         }
//     }
//     return root;
// }


Node* insert_node(Node* root, int val) {
    if (root == NULL) {
        return create_node(val);
    } else {
        if (val < root->data) {
            root->left = insert_node(root->left, val);
        } else {
            root->right = insert_node(root->right, val);
        }
        return root;
    }
}

// Node* find_largest(Node* root) {
//     if (root == NULL || root->right == NULL) {
//         return root;
//     }
//     find_largest(root->right);
// }

Node* find_largest(Node* root) {
    if (root == NULL || root->right == NULL) {
        return root;
    }
    find_largest(root->right);
}

// Node* find_smallest(Node* root) {
//     if (root == NULL || root->left == NULL) {
//         return root;
//     }
//     find_smallest(root->left);
// }

Node* find_smallest(Node* root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }
    find_smallest(root->left);
}

// Node* search(Node* root, int val) {
//     if (root == NULL || root->data == val) {
//         return root;
//     }
    
//     if (val < root->data) {
//         return search(root->left, val);
//     } else {
//         return search(root->right, val);
//     }
// }

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

// Node* find_minimum(Node* root) {
//     if (root->left == NULL) {
//         return root;
//     }
//     return find_minimum(root->left);
// }

// Node* delete_node(Node* root, int val) {
//     if (root == NULL) {
//         cout << "Element not found" << endl;
//         return NULL;
//     } else if (val < root->data) {
//         root->left = delete_node(root->left, val);
//     } else if (val > root->data) {
//         root->right = delete_node(root->right, val);
//     } else {
//         if (root->left == NULL && root->right == NULL) {
//             root = NULL;
//         } else if (root->left == NULL) {
//             root = root->right;
//         } else if (root->right == NULL) {
//             root = root->left;
//         } else {
//             Node* temp = find_minimum(root->right);
//             root->data = temp->data;
//             root->right = delete_node(root->right, temp->data);
//         }
//     }
//     return root;
// }

Node* find_minimum(Node* root) {
    if (root->left == NULL) {
        return root;
    }
    return find_minimum(root->left);
}

Node* delete_node(Node* root, int val) {
    if (root == NULL) {
        cout << "Element not found" << endl;
        return NULL;
    } else if (val < root->data) {
        root->left = delete_node(root->left, val);
    } else if (val > root->data) {
        root->right = delete_node(root->right, val);
    } else {
        if (root->left == NULL && root->right == NULL) {
            root = NULL;
        } else if (root->left == NULL) {
            root = root->right;
        } else if (root->right == NULL) {
            root = root->left;
        } else {
            Node* temp = find_minimum(root->right);
            root->data = temp->data;
            root->right = delete_node(root->right, temp->data);
        }
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
    Node* del;

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

    cin >> val;

    del = delete_node(root, val);
    in_order(root);
    cout << endl;


    return 0;
}