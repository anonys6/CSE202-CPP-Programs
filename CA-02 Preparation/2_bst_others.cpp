//BINARY TREE
//Height of tree= number of levels
//Number of children possible at a level n= 2^n
//Maximum number of nodes posible for height h = 2^(h+1)-1
//Minimum number of nodes for height h = h+1
//Minimum height of a tree that cotains n nodes= log�(n+1)-1 [base 2 of log]   [found via maximum nodes formula]
//Maximum height of a tress that contains n nodes= n-1		[found via minimum nodes formula]
//
//Types of Binary tree:
//	Full/Proper/Strict :
//		Every node as either 2 or 0 children
//	Complete Binary tree:
//		All level are completely filled, except the last level which is filled from the left.
//	Perfect binary tree:
//		All internal nodes have 2 children and all leaves are at same level [Every perfect binary tree is full and complete]
//	Degenerate tree:
//		Each internal node has only one child.
//		If every node has only left children: left degenerate tree
//		If every node has only right children: right degenerate tree
//
//Properties:
//			Maximum Height		Minimum Height		Maximum Nodes		Minimum Nodes
//	Binary 		n-1				 log�(n+1)-1	      2^(h+1)-1			 2^(h+1)-1
//	Full	   (n-1)/2			 log�(n+1)-1		  2^(h+1)-1			   2h+1
//	Complete	log n 			 log�(n+1)-1		  2^(h+1)-1			    2^h
//	



#include<iostream>
#include<stdlib.h>
using namespace std;

struct node{
	int data;
	struct node*left;
	struct node*right;
};


void preorder(struct node *root){ // print the data then traverse the left , then traverse the right
	if(root==0)
		return ;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	
}

void inorder(struct node *root){ // traverse the left , print the data, traverse the right
	if(root==0)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);	
	
}

int total_level=0;

void postorder(struct node*root){ //traverse the left, traverse the right, print the data
	if(root==0)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
	
}

struct node* create(int level,string pos="left"){
 	node *newnode=new  node();  // or struct node *newnode=(struct node *)malloc(sizeof(structnode));
 	int x;
	total_level=max(level,total_level);
	cout<<endl<<"You are at level "<<level<<endl;
	cout<<"Enter data for "<<pos<<" child"<<endl;
	cout<<"Enter -1 for no node."<<endl;
	cin>>x;
	if(x==-1)
		return 0;
 	newnode->data=x;
 	newnode->left=create(level+1,"left");
 	newnode->right=create(level+1,"right");
 	return newnode;
}

int main(){
	struct node * root;
	root=create(0);
	cout<<"Preorder: ";
	preorder(root);
	cout<<endl<<"Inorder: ";
	inorder(root);
	cout<<endl<<"Postorder: ";
	postorder(root);
	cout<<endl<<"LEVELS: "<<total_level;
	return 0;
	
}


















// Luv


#include<iostream>
using namespace std;
struct node{
 	int data;
 	node *left , *right;
 };
 
 
node *create(int val){
	node *newnode =  new node();
	if(!newnode){
		return 0;
	} else {
		newnode->data = val;
		newnode->left = newnode->right = NULL;
		return newnode;
	}
}

node *insert(node *root,int val){
	if(root == NULL){
		return create(val);
	} else{
		if(val<root->data){
			root->left = insert(root->left,val);
		} else{
			root->right = insert(root->right,val);
		}
		return root;
	}
}


node *search(node *root , int val){
	if(root == NULL || root->data == val){
		return root;
	}
	else{
		if(val<root->data){
			return search(root->left , val);
		}
		else{
			return search(root->right,val);
		}
	}
}


void inorder(node *root){
	if(root==NULL){
		return;
	}
	else{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}


void postorder(node *root){
	if(root == NULL){
		return;
	}
	else{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}


void preorder(node *root){
	if(root==NULL){
		return;
	}
	else{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}

node* findlargest(node* root) {
    if (root == NULL || root->right == NULL) {
        return root;
    }
    return findlargest(root->right);
}

node* findsmallest(node* root) {
    if (root == NULL || root->left == NULL) {
        return root;
    }
    return findsmallest(root->left);
}


node *deletee(node *tree,int val){
	if(tree==NULL){
		cout<<"Value not found in the bst";
	}
	else if(val<tree->data){
		tree->left = deletee(tree->left,val);
	}
	else if(val>tree->data){
		tree->right = deletee(tree->right,val);
	}
	else if(tree->left!=0 && tree->right!=0){
		node *temp = findlargest(tree->left);
		tree->data = temp->data;
		tree->left = deletee(tree->left,temp->data);
	}
	else{
		node *temp = tree;
		if(tree->left == NULL && tree->right == NULL){
			tree = NULL;
		}
		else if(tree->left != NULL){
			tree = tree->left;
		}
		else{
			tree = tree->right;
		}
		delete temp;
	}
	return tree;
}







int main(){
	int choice;
	cout<<"Enter 1 for insertion: "<<endl;
	cout<<"Enter 2 for search: "<<endl;
	cout<<"Enter 3 for inorder: "<<endl;
	cout<<"Enter 4 for preorder: "<<endl;
	cout<<"Enter 5 for postorder: "<<endl;
	cout<<"Enter 6 for deletion: "<<endl;
	cout<<"Enter 7 for largest: "<<endl;
	cout<<"Enter 8 for smallest: "<<endl;
	cout<<"Enter 9 for exit: "<<endl;
	node *root = 0;
	do{
		cout<<"\nEnter the choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter the no of nodes: ";
				int n;
				cin>>n;
				cout<<"Enter the data into the node: ";
				int val;
				for(int i=0;i<n;i++){
					cin>>val;
					root = insert(root,val);
				}
				break;
			case 2:
				cout<<"Enter the val to search: ";
				int val2;
				cin>>val2;
				if(search(root,val2)){
					cout<<"Found"<<endl;
				}
				else{
					cout<<"Not found"<<endl;
				}
				break;
			case 3:
				cout<<"Inorder traversal: ";
				inorder(root);
				cout<<endl;
				break;
			case 4:
				cout<<"preorder traversal: ";
				preorder(root);
				cout<<endl;
				break;
			case 5:
				cout<<"Postorder traversal: ";
				postorder(root);
				cout<<endl;
				break;
			case 6:
				cout<<"Enter the val to delete: ";
				int val3;
				cin>>val3;
				deletee(root,val3);
				inorder(root);
				cout<<endl;
				break;
			case 7:
				cout<<"The largest element is: "<<findlargest(root)->data;
				break;
			case 8:
				cout<<"The smallest element is: "<<findsmallest(root)->data;
				break;
			case 9:
				exit(0);
				break;
			default:
				cout<<"Invalid ";
				break;
		}
	}while(choice!=9);
}



























// Jivesh


#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{

    cout << "Enter the data for the node - ";
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "Enter data for inserting in left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for inserting in right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}

/* [1, NULL, 3, 5, NULL, ]
Whenever we encounter NULL, we will cout<<endl;
Queue created -> 1 pushed. As it is root node, we manually enter NULL.
The queue is not empty => we move to else block and print the front element and pop it from the queue.
We then push left and right children of the node i.e. 3 and 5 in this case.
We need to check emptiness of the queue, if not empty, we push NULL.
When it is the turn of 3 and 5 to be printed, 7 and 11 are pushed in stack as children of 3 and 17 is pushed in stack as child of 17.
*/
void levelOrderTraversal(node *root)
{
    queue<node *> q; // Node* type queue
    q.push(root);
    q.push(NULL); // Separating levels from root(1st level)

    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            // Old level finished
            cout << endl;
            if (!q.empty())
            {   
                // New Level started
                q.push(NULL); 
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
    
int main()
{
    node *root = NULL;

    // Creating a tree
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildTree(root);

    // levelOrderTraversal
    cout<<endl;
    levelOrderTraversal(root);
    return 0;
}