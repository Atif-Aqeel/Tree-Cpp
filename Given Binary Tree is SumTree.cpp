/*
A SumTree is a Binary Tree where the value of a "node" is equal to the sum of the nodes present in its left subtree and right subtree. 
An empty tree is SumTree and the sum of an empty tree can be considered as 0. A leaf node is also considered as SumTree.

Get the sum of nodes in the left subtree and right subtree. 
Check if the sum calculated is equal to the root’s data. 
Also, recursively check if the left and right subtrees are SumTrees.

*/

#include<bits/stdc++.h>
using namespace std;

struct node{
	
	int data;
	struct node* left;
	struct node* right;
};

struct node* newNode(int data){
	
	struct node* node = (struct node*)malloc(sizeof(struct node));
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return(node);
}

// A utility function to get the sum of values in tree with root as root
int sum(struct node *root){
	
	if (root == NULL)
		return 0;
	
	int allSum = sum(root->left) + root->data + sum(root->right) ;
	
	return ( allSum );
}

// Returns 1 if sum property holds for the given node and both of its children
int isSumTree(struct node* node){

	// If node is NULL or it's a leaf node then return true
	if (node == NULL || (node->left == NULL && node->right == NULL))
		return 1;

	// Get sum of nodes in left and right subtrees
	int ls, rs;
	ls = sum(node->left);
	rs = sum(node->right);

	// If the node and both of its children satisfy the property return 1 else 0
	if ((node->data == ls + rs) && isSumTree(node->left) &&	isSumTree(node->right))
		return 1;

return 0;
}

int main(){
	
	struct node *root = newNode(26);
	root->left = newNode(10);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(6);
	root->right->right = newNode(3);
	//root->right->right = newNode(13);
	
	if (isSumTree(root))
		cout << "The given tree is a SumTree ";
	else
		cout << "The given tree is not a SumTree ";


return 0;
}
