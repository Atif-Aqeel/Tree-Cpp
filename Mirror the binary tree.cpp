/*
Given a binary tree, the task is to convert the binary tree into its Mirror tree. 
Mirror of a Binary Tree T is another Binary Tree M(T) with left and right children of all non-leaf nodes interchanged. 
*/

#include<bits/stdc++.h>
using namespace std;

//BT has two childs left and right
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

//Helper function that allocates a new node with the given data and NULL the left and right pointer
struct Node* newNode(int data){
	
	struct Node* node = (struct Node*) malloc(sizeof(struct Node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;

return (node);
}

//Change the tree so that left and right nodes swap
void mirror(struct Node* node){
	struct Node* temp;
	
	if(node == NULL){
		return ;
	}
	else{
		//do the subtrees
		mirror(node->left);
		mirror(node->right);
	
		//swap the pointers in this node
		temp = node->left;
		node->left = node->right;
		node->right = temp;
	}
}

//Helper Function to print Traversal
void print(struct Node* node){
	if(node == NULL){
		return;
	}
	
	print(node->left);
	cout<<node->data <<" ";
	print(node->right);
}

int main(){
/*So the tree...
     4
    / \
   2   5
  / \
 3   1
 
is changed to...
     4
    / \
   5   2
      / \
     1   3
*/
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	//root->left->left->right = newNode(6);
	
	//print the BTree
	cout<<" BT "<<endl;
	print(root);
	
	//Convert Tree to its Binary Tree
	mirror(root);
	
	//Print the mirror
	cout<<endl<<"Mirror"<<endl;
	print(root);
	
return 0;
}


/*
The idea is to traverse recursively and swap the right and left subtrees after traversing the subtrees.

Follow the steps below to solve the problem:
Call Mirror for left-subtree i.e., Mirror(left-subtree)
Call Mirror for right-subtree i.e., Mirror(right-subtree)
Swap left and right subtrees.
	temp = left-subtree
	left-subtree = right-subtree
	right-subtree = temp
*/
