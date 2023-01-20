/*
A binary Search Tree is a node-based binary tree data structure which has the following properties:  
-The left subtree of a node contains only nodes with keys lesser than the node’s key.
-The right subtree of a node contains only nodes with keys greater than the node’s key.
-The left and right subtree each must also be a binary search tree. There must be no duplicate nodes.

The algorithm depends on the property of BST.
If the value is below the root, we can say for sure that the value is not in the right subtree; we need to only search in the left subtree and 
if the value is above the root, we can say for sure that the value is not in the left subtree; we need to only search in the right subtree.

Algorithm:
If root == NULL 
    return NULL;
If number == root->data 
    return root->data;
If number < root->data 
    return search(root->left)
If number > root->data 
    return search(root->right)
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

//Search
struct Node* search(struct Node* node, int data){

	if(node == NULL){
    	cout<<"Element You Enter \""<< data <<"\" in present in the BST.";
	}
	
	if( data == node->data ){
    	return node;
	}
	else if( data < node->data ){
    	return search(node->left, data);
	}
	else if( data > node->data ){                       
    	return search(node->right, data);
	}
	else{
		return node;
	}
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
	
	cout<<endl<<endl<<"Search Element is"<<endl;
	root = search(root, 16);
	inOrder(root);
	
return 0;
}
