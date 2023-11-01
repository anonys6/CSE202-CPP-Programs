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

Node* create_node(int val) {
    Node* newNode = new Node();

    if (!newNode) {
        return 0;
    } else {
        newNode -> data = val;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
}

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

Node* serach_node(Node* root, int val) {
    if (root == NULL || root->data == val) {
        return root;
    } else {
        if (val < root->data) {
            return serach_node(root->left, val);
        } else {
            return serach_node(root->right, val);
        }
    }
}

void pre_order (Node* root) {
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

Node* find_largest(Node* root) {
    if (root == NULL || root->right == NULL) {
        return root;
    }
    return find_largest(root->right);
}

Node* find_smallest(Node* root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }
    return find_smallest(root->left);
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Node* root = NULL;

    root = create_node(3);
    insert_node(root, 5);
    insert_node(root, 2);
    insert_node(root, 7);
    insert_node(root, 9);
    insert_node(root, 3);
    insert_node(root, 4);

    // in_order(root);
    
    cout << find_largest(root)->data << endl;
    cout << find_smallest(root)->data << endl;

    return 0;
}
















// #include <iostream>
// #include <iomanip>
// #include <cmath>
// #include <vector>
// #include <algorithm>

// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;
// };

// Node* create_node(int val) {
//     Node* newNode = new Node();

//     if (newNode == NULL) {
//         return 0; 
//     } else {
//         newNode->data = val;
//         newNode->left = newNode->right = NULL;
//         return newNode;
//     }
// }

// Node* insert_node(Node* root, int val) {
//     if (root == NULL) {
//         return create_node(val);
//     } else {
//         if (val < root->data) {
//             root->left = insert_node(root->left, val);
//         } else {
//             root->right = insert_node(root->right, val);
//         }
//         return root;
//     }
// }

// Node* search_tree (Node* root, int val) {
//     if (root == NULL || root->data == val) {
//         return root;
//     } else {
//         if (val < root->data) {
//             return search_tree(root->left, val);
//         } else {
//             return search_tree(root->right, val);
//         }
//     }
// }

// void pre_order (Node* root) {
//     if (root == NULL) {
//         return ;
//     } else {
//         cout << root->data << " ";
//         pre_order(root->left);
//         pre_order(root->right);
//     }
// }

// Node* find_largest(Node* root) {
//     if (root == NULL || root->right == NULL) {
//         return root;
//     }
//     return find_largest(root->right);
// }

// Node* find_smallest(Node* root) {
//     if (root == NULL || root->left == NULL) {
//         return root;
//     }
//     return find_smallest(root->left);
// }

// int main() {

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     Node* root = NULL;

//     root = create_node(2);
//     insert_node(root, 4);
//     insert_node(root, 6);
//     insert_node(root, 9);
//     insert_node(root, 3);
//     insert_node(root, 0);
//     insert_node(root, 20);
//     insert_node(root, 8);

//     cout << find_largest(root)->data << endl;
//     cout << find_smallest(root)->data << endl;
    
    

//     return 0;
// }

























// #include <iostream>
// #include <iomanip>
// #include <cmath>
// #include <vector>
// #include <algorithm>

// using namespace std;

// struct Node {
//     int data;
//     Node* left;
//     Node* right;
// };

// Node* create_node(int val) {
//     Node* newNode = new Node();

//     if (newNode == NULL) {
//         return 0;
//     } else {
//         newNode->data = val;
//         newNode->left = newNode->right = NULL;
//         return newNode;
//     }
// }

// Node* insert_node(Node* root, int val) {
//     if (root == NULL) {
//         return create_node(val);
//     } else {
//         if (val < root->data) {
//             root->left = insert_node(root->left, val);
//         } else {
//             root->right = insert_node(root->right, val);
//         }
//         return root;
//     }
// }

// Node* search_tree(Node* root, int val) {
//     if (root == NULL || root->data == val) {
//         return root;
//     } else {
//         if (val < root->data) {
//             return search_tree(root->left, val);
//         } else {
//             return search_tree(root->right, val);
//         }
//     }
// }

// Node* find_largest(Node* root) {
//     if (root == NULL || root->right == NULL) {
//         return root;
//     }
//     return find_largest(root->right);
// }

// Node* find_smallest(Node* root) {
//     if (root == NULL || root->left == NULL) {
//         return root;
//     }
//     return find_smallest(root->left);
// }

// int main() {

// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

//     Node* root = NULL;

//     root = create_node(4);
//     insert_node(root, 5);

//     cout << find_largest(root)->data << endl;    

//     return 0;
// }