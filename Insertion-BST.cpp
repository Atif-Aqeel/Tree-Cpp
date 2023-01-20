/*
A binary Search Tree is a node-based binary tree data structure which has the following properties:  
-The left subtree of a node contains only nodes with keys lesser than the node’s key.
-The right subtree of a node contains only nodes with keys greater than the node’s key.
-The left and right subtree each must also be a binary search tree. There must be no duplicate nodes.

inserting a value in the correct position is similar to searching because we try to maintain the rule that 
the left subtree is lesser than root and the right subtree is larger than root.
We keep going to either right subtree or left subtree depending on the value and 
when we reach a point left or right subtree is null, we put the new node there.

Algorithm:
If node == NULL 
    return createNode(data)
if (data < node->data)
    node->left  = insert(node->left, data);
else if (data > node->data)
    node->right = insert(node->right, data);  
return node;
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
	
return 0;
}
