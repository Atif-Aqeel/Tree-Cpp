/*
1-Create a temp array arr[] that stores inorder traversal of the tree. This step takes O(n) time.
2-Sort the temp array arr[]. Time complexity of this step depends upon the sorting algorithm. 
	In the following implementation, Quick Sort is used which takes (n^2) time. 
	This can be done in O(nLogn) time using Heap Sort or Merge Sort.
3-Again do inorder traversal of tree and copy array elements to tree nodes one by one. This step takes O(n) time.

*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

/* A helper function that stores inorder traversal of a tree rooted with node */
void storeInorder(struct Node* node, int inorder[], int* index_ptr){
	
	// Base Case
	if (node == NULL)
		return;

	/* first store the left subtree */
	storeInorder(node->left, inorder, index_ptr);

	/* Copy the root's data */
	inorder[*index_ptr] = node->data;
	(*index_ptr)++; // increase index for next entry

	/* finally store the right subtree */
	storeInorder(node->right, inorder, index_ptr);
}

/* A helper function to count nodes in a Binary Tree */
int countNodes(struct Node* root){
	
	if (root == NULL)
		return 0;
	
	return countNodes(root->left) + countNodes(root->right) + 1;
}

// Following function is needed for library function qsort()
int compare(const void* a, const void* b){
	
	return (*(int*)a - *(int*)b);
}

/* A helper function that copies contents of arr[] to Binary Tree. 
This function basically does Inorder traversal of Binary Tree and one by one copy arr[] elements to Binary Tree nodes */
void arrayToBST(int* arr, struct Node* root, int* index_ptr){
	
	// Base Case
	if (root == NULL)
		return;

	/* first update the left subtree */
	arrayToBST(arr, root->left, index_ptr);

	/* Now update root's data and increment index */
	root->data = arr[*index_ptr];
	(*index_ptr)++;

	/* finally update the right subtree */
	arrayToBST(arr, root->right, index_ptr);
}

// This function converts a given Binary Tree to BST
void binaryTreeToBST(struct Node* root){
	
	// base case: tree is empty
	if (root == NULL)
		return;

	/* Count the number of nodes in Binary Tree so that	we know the size of temporary array to be created */
	int n = countNodes(root);

	// Create a temp array arr[] and store inorder traversal of tree in arr[]
	int* arr = new int[n];
	int i = 0;
	storeInorder(root, arr, &i);

	// Sort the array using library function for quick sort
	qsort(arr, n, sizeof(arr[0]), compare);

	// Copy array elements back to Binary Tree
	i = 0;
	arrayToBST(arr, root, &i);

	// delete dynamically allocated memory to avoid memory leak
	delete[] arr;
}

/* Utility function to create a new Binary Tree node */
struct Node* newNode(int data){
	
	struct Node* temp = new struct Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;
}

/* Utility function to print inorder traversal of Binary Tree */
void printInorder(struct Node* node){
	
	if (node == NULL)
		return;

	/* first recur on left child */
	printInorder(node->left);

	/* then print the data of node */
	cout <<" "<< node->data;

	/* now recur on right child */
	printInorder(node->right);
}

/* Driver function to test above functions */
int main(){
	
	struct Node* root = NULL;
	
	root = newNode(10);
	root->left = newNode(30);
	root->right = newNode(15);
	root->left->left = newNode(20);
	root->right->right = newNode(5);

	cout <<"Inorder Traversal of the Binary Tree:" << endl ;
	printInorder(root);
	
	// convert Binary Tree to BST
	binaryTreeToBST(root);

	cout <<"\nInorder Traversal of the BST:" << endl ;
	printInorder(root);

return 0;
}
