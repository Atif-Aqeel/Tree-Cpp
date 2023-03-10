/*
Given a binary tree, write a program to count the number of Single Valued Subtrees. 
A Single Valued Subtree is one in which all the nodes have same value. 
Expected time complexity is O(n).

-A Simple Solution is to traverse the tree. For every traversed node, check if all values under this node are same or not. 
	If same, then increment count. Time complexity of this solution is O(n2).

-An Efficient Solution is to traverse the tree in bottom up manner. 
	For every subtree visited, return true if subtree rooted under it is single valued and increment count. 
	So the idea is to use count as a reference parameter in recursive calls and use 
	returned values to find out if left and right subtrees are single valued or not.

*/

#include<bits/stdc++.h>
using namespace std;

struct Node{	

	int data;
	struct Node* left, *right;
};

Node* newNode(int data){
	
	Node* temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	
	return (temp);
}

// This function increments count by number of single valued subtrees under root. It returns true if subtree under root is Singly, else false.
bool countSingleRec(Node* root, int &count){
	
	// Return true to indicate NULL
	if (root == NULL)
		return true;

	// Recursively count in left and right subtrees also
	bool left = countSingleRec(root->left, count);
	bool right = countSingleRec(root->right, count);

	// If any of the subtrees is not singly, then this cannot be singly.
	if (left == false || right == false)
		return false;

	// If left subtree is singly and non-empty, but data doesn't match
	if (root->left && root->data != root->left->data)
		return false;

	// Same for right subtree
	if (root->right && root->data != root->right->data)
		return false;

	// If none of the above conditions is true, then tree rooted under root is single valued, increment count and return true.
	count++;
	return true;
}

// This function mainly calls countSingleRec() after initializing count as 0
int countSingle(Node* root){
	
	// Initialize result
	int count = 0;

	// Recursive function to count
	countSingleRec(root, count);

	return count;
}

int main(){
	
	/* Let us construct the below tree
			5
		   / \
		  4	  5
		 / \   \
		4   4	5 
	*/
	
	Node* root	 = newNode(5);
	root->left	 = newNode(4);
	root->right	 = newNode(5);
	root->left->left = newNode(4);
	root->left->right = newNode(4);
	root->right->right = newNode(5);

	cout << "Count of Single Valued Subtrees is "
		<< countSingle(root);

return 0;
}
