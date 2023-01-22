/*
Symmetric Tree (Mirror Image of itself)

The idea is to write a recursive function isMirror() that takes two trees as an argument and 
returns true if trees are the mirror and false if trees are not mirrored. 
The isMirror() function recursively checks two roots and subtrees under the root.

For two trees to be mirror images, the following three conditions must be true
    1.) Their root node's key must be same
    2.) left subtree of left tree and right subtree of right tree have to be mirror images
    3.) right subtree of left tree and left subtree of right tree have to be mirror images

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

Node* newNode(int data){
	
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
}

//Function that return true if trees with roots 	as root1 and root2 are mirror 
bool isMirror(Node* root1, Node* root2){
	
	//If both trees are empty then they are mirror images
	if(root1 == NULL && root2 == NULL){
		return true;
	}

	// For two trees to be mirror images, the following three conditions must be true
    // 1.) Their root node's key must be same
    // 2.) left subtree of left tree and right subtree of right tree have to be mirror images
    // 3.) right subtree of left tree and left subtree of right tree have to be mirror images
	
	if(root1 && root2 && root1->data == root2->data){
		
		return ( isMirror(root1->left, root2->right) && isMirror(root1->right, root2->left) );
	}
	
	//If 3 conditions are not true then they are not mirror images, so return false
	return false;
}

//chech a tree that it is mirror or not
bool isSymmetric(Node* root){
	
	return isMirror(root, root);
}

int main(){

	Node* root = newNode(1);
	
	root->left = newNode(2);	
	root->right = newNode(2);
	
	root->left->right = newNode(3);
	root->right->left = newNode(3);
	
	if(isSymmetric(root))
		cout<<"Symmetric Tree";
	else
		cout<<"Not Symmetric";
	
return 0;
}
