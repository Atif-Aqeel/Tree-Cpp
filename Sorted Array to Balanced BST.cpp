/*
Given a sorted array. Write a function that creates a Balanced Binary Search Tree using array elements.

The idea is to find the middle element of the array and make it the root of the tree, 
then perform the same operation on the left subarray for the root’s left child and 
the same operation on the right subarray for the root’s right child.

Follow the steps mentioned below to implement the approach:
-Set The middle element of the array as root.
-Recursively do the same for the left half and right half.
	-Get the middle of the left half and make it the left child of the root created in step 1.
	-Get the middle of the right half and make it the right child of the root created in step 1.
-Print the preorder of the tree.
*/

#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
		int data;
		Node* left;
		Node* right;
};

Node* newNode(int data);

/* A function that constructs Balanced Binary Search Tree from a sorted array */
Node* sortedArrayToBST(int arr[], int start, int end){
	
	/* Base Case */
	if (start > end)
		return NULL;

	/* Get the middle element and make it root */
	int mid = (start + end)/2;
	Node *root = newNode(arr[mid]);

	/* Recursively construct the left subtree and make it left child of root */
	root->left = sortedArrayToBST(arr, start, mid - 1);
									
	/* Recursively construct the right subtree and make it right child of root */
	root->right = sortedArrayToBST(arr, mid + 1, end);

	return root;
}

/* Helper function that allocates a new node with the given data and NULL left and right pointers. */
Node* newNode(int data){
	
	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;

	return node;
}

/* A utility function to print preorder traversal of BST */
void preOrder(Node* node){
	
	if (node == NULL)
		return;
	
	cout << node->data << " ";
	preOrder(node->left);
	preOrder(node->right);
}

int main(){
	
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(arr) / sizeof(arr[0]);

	/* Convert List to BST */
	Node *root = sortedArrayToBST(arr, 0, n-1);
	
	cout << "PreOrder Traversal of constructed BST \n";
	preOrder(root);

return 0;
}
