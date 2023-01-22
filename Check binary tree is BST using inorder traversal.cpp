/*
Check whether the binary tree is BST or not using inorder traversal:
The idea is to use Inorder traversal of a binary search tree generates output, sorted in ascending order. 
So generate inorder traversal of the  given binary tree and check if the values are sorted or not

***If the value of the currently visited node is less than the previous value, then the tree is not BST.
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	struct Node *left, *right;

	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

bool isBSTUtil(struct Node* root, Node*& prev){
	
	// traverse the tree in inorder fashion and keep track of prev node
	if(root) {
		
		if(!isBSTUtil(root->left, prev))
			return false;

		// Allows only distinct valued nodes
		if(prev != NULL && root->data <= prev->data)
			return false;

		prev = root;

		return isBSTUtil(root->right, prev);
	}

	return true;
}

bool isBST(Node* root){
	
	Node* prev = NULL;
	return isBSTUtil(root, prev);
}

int main(){
	
	struct Node* root = new Node(3);
	root->left = new Node(2);
	root->right = new Node(5);
	root->left->left = new Node(1);
	root->left->right = new Node(4);

	if (isBST(root))
		cout << "Is BST";
	else
		cout << "Not a BST";

return 0;
}
