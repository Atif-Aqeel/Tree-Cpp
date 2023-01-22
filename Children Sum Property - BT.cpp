/*
Given a binary tree, the task is to check for every node, its value is equal to the sum of values of 
its immediate left and right child. For NULL values, consider the value to be 0.

To solve the problem follow the below idea:
Traverse the given binary tree. For each node check (recursively) if the node and 
both its children satisfy the Children Sum Property, if so then return true else return false
*/

#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data){
	
	//allocates a new node with the given data and NULL left and right pointers.
	//struct node* node = (struct node*)malloc(sizeof(struct node));
	
	struct node* Node = new node;
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

/* returns 1 if children sum property holds for the given node and both of its children*/
int isSumProperty(struct node* node){

	/* left_data is left child data and right_data is for right child data*/
	int sum = 0;

	/* If node is NULL or it's a leaf node then return true */
	if (node == NULL || (node->left == NULL && node->right == NULL))
		return 1;

	else {
		/* If left child is not present then 0 is used as data of left child */
		if (node->left != NULL)
			sum += node->left->data;

		/* If right child is not present then 0	is used as data of right child */
		if (node->right != NULL)
			sum += node->right->data;

		/* if the node and both of its children	satisfy the property return 1 else 0*/
		return ((node->data == sum)
				&& isSumProperty(node->left)
				&& isSumProperty(node->right));
	}
}

int main(){
	
	struct node* root = newNode(10);
	root->left = newNode(8);
	root->right = newNode(2);
	root->left->left = newNode(3);
	root->left->right = newNode(5);
	root->right->right = newNode(2);

	if (isSumProperty(root))
		cout << "The given tree satisfies the children sum property ";
	else
		cout << "The given tree does not satisfy the children sum property ";

return 0;
}
