/*
In the case of BST, we can find the distance faster. We start from the root and for every node, we do following.
If both keys are greater than the current node, we move to the right child of the current node.
If both keys are smaller than current node, we move to left child of current node.
If one keys is smaller and other key is greater, current node is Lowest Common Ancestor (LCA) of two nodes. 
We find distances of current node from two keys and return sum of the distances.

*/

//find distance between two nodes in BST
#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node* left; 
	struct Node* right;
};

Node* newNode(int key){
	
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	
	return temp;
}


// Standard BST insert function
Node* insert(struct Node* root, int key){
	
	if (!root)
		root = newNode(key);
		
	else if (root->key > key)
		root->left = insert(root->left, key);
		
	else if (root->key < key)
		root->right = insert(root->right, key);
		
	return root;
}

// This function returns distance of x from root. This function assumes that x exists in BST and BST is not NULL.
int distanceFromRoot(struct Node* root, int x){
	
	if (root->key == x)
		return 0;
		
	else if (root->key > x)
		return 1 + distanceFromRoot(root->left, x);
		
	else	
		return 1 + distanceFromRoot(root->right, x);
}

// Returns minimum distance between a and b. This function assumes that a and b exist in BST.
int distanceBetween2(struct Node* root, int a, int b){
	
	if (!root)
		return 0;

	// Both keys lie in left
	if (root->key > a && root->key > b)
		return distanceBetween2(root->left, a, b);

	// Both keys lie in right
	if (root->key < a && root->key < b) 
		return distanceBetween2(root->right, a, b);

	// Lie in opposite directions (Root is LCA of two nodes)
	if (root->key >= a && root->key <= b)
		return ( distanceFromRoot(root, a) + distanceFromRoot(root, b) );
}

// This function make sure that a is smaller than b before making a call to findDistWrapper()
int findDistWrapper(Node *root, int a, int b){
	
	if (a > b)
		swap(a, b);
	return distanceBetween2(root, a, b);
}

// Driver code
int main()
{
	struct Node* root = NULL;
	root = insert(root, 20);
	insert(root, 10);
	insert(root, 5);
	insert(root, 15);
	insert(root, 30);
	insert(root, 25);
	insert(root, 35);
	
	int a = 5, b = 55;
	cout<<"Distance between nodes " <<a<<" and "<< b<< " is :"<<endl;
	cout << findDistWrapper(root, 5, 35);

return 0;
}
