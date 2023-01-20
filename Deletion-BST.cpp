/*
A binary Search Tree is a node-based binary tree data structure which has the following properties:  
-The left subtree of a node contains only nodes with keys lesser than the node’s key.
-The right subtree of a node contains only nodes with keys greater than the node’s key.
-The left and right subtree each must also be a binary search tree. There must be no duplicate nodes.

There are three cases for deleting a node from a binary search tree.
Case I:
In the first case, the node to be deleted is the leaf node. In such a case, simply delete the node from the tree.

Case II:
In the second case, the node to be deleted lies has a single child node. In such a case follow the steps below:
	1-Replace that node with its child node.
	2-Remove the child node from its original position.

Case III:
In the third case, the node to be deleted has two children. In such a case follow the steps below:
	1-Get the inorder successor of that node.
	2-Replace the node with the inorder successor.
	3-Remove the inorder successor from its original position

(Inorder successor of a node is the next node in Inorder traversal of the Binary Tree)
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

//Create a New Nod
Node* newNode(int data){
	
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;	
}

//Inorder Traversal 
void inOrder(struct Node* node){
	if(node == NULL){
		return ;
		//return NULL; 		//get error
	}
	
	//Print Left Subtree by recursion
	inOrder(node->left);
	
	//Print root
	cout<< node->data <<" ";
	//inOrder(node->data); error
	
	//print Right Subtree
	inOrder(node->right);
	
}

//Insert
struct Node* insert(struct Node* node, int data){
	
	//If tree is empty, return a new node to create it
	if(node == NULL){
		return newNode(data);
	}
	
	//Traverse to the right place and insert 
	if(data < node->data){
		node->left = insert(node->left, data);
	}
	else{
		node->right = insert(node->right, data);
	}
	
	return node;
}

//Get inorder successor for caseIII
struct Node* minValueNode(struct Node* node){
	struct Node* current = node;
	
	//Find leftmost leaf
	while(current && current->left != NULL){
		current = current->left;
	}
	
	return current;
}

//Deleting 
struct Node* deleteNode(struct Node* node, int data){
	struct Node* temp;
	//Return Null if tree is empty
	if(node == NULL){
		return NULL;
	}
	
	//Find node to be deleteNoded
	if(data < node->data){
		node->left = deleteNode(node->left, data);
	}
	else if(data > node->data){
		node->right = deleteNode(node->right, data);
	}
	else{

		//If Node has only one child or No Child
		if(node->left == NULL){
			temp = node->right;
			free(node);
			
			return temp;
		}
		else if(node->right == NULL){
			temp = node->left;
			free(node);
			
			return temp;
		}
		
		//If Node has 2 child
		temp = minValueNode(node->right);
		//root->right because inorder successor is the next/right nodes
							
		// Place the inorder successor in position of the node to be deleteNoded
    	node->data = temp->data;
    	
    	// deleteNode the inorder successor
    	node->right = deleteNode(node->right, temp->data);
		
	}
	
	return node;
}


int main(){
	//insert function we call instead of newNode because we apply insertion operation and newNode operation call in insert function
	struct Node* root = NULL;
	root = insert(root, 8);
	root = insert(root, 3);
	root = insert(root, 1);
	root = insert(root, 6);
	root = insert(root, 7);
	root = insert(root, 10);
	root = insert(root, 14);
	root = insert(root, 4);

	cout << "Inorder traversal: "<<endl;
	inOrder(root);
	
	cout<<endl<<"After Deletion 10 : "<<endl;
	root = deleteNode(root, 10);
	inOrder(root);

return 0;
}
