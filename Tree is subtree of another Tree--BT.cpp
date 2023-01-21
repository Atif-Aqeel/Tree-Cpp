/*
Approach:
The idea is to check at every node for the subtree.

Follow the steps below to solve the problem:
	Traverse the tree T in preorder fashion (root-left-right)
	For every visited node in the traversal, see if the subtree rooted with this node is identical to S.
	To check the subtree is identical or not traverse on the tree S and T simultaneously
	If a visited node is not equal then return false else continue traversing the whole tree S is traversed
*/

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, left child and right child */
struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* newNode(int data){

	Node* node = new Node();
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	
	return (node);
}

/* A utility function to check whether trees with roots as root1 and root2 are identical or not */
bool areIdentical(Node* root1, Node* root2){
	
	/* base cases */
	if (root1 == NULL && root2 == NULL)
		return true;

	if (root1 == NULL || root2 == NULL)
		return false;

	/* Check if the data of both roots is same and data of left and right subtrees are also same */
	return (root1->data == root2->data
			&& areIdentical(root1->left, root2->left)
			&& areIdentical(root1->right, root2->right));
}

/* This function returns true if S is a subtree of T, otherwise false */
bool isSubtree(Node* T, Node* S)
{
	/* base cases */
	if (S == NULL)
		return true;

	if (T == NULL)
		return false;

	/* Check the tree with root as current node */
	if (areIdentical(T, S))
		return true;

	/* If the tree with root as current node doesn't match then try left and right subtrees one by one */
	return (isSubtree(T->left, S) || isSubtree(T->right, S));
}

//Pre order Traversal 
void preOrder(struct Node* node){
	if(node == NULL){
		return ;
	}
	
	//Print root
	cout<< node->data <<" ";
	//inOrder(node->data); error
	
	//Print Left Subtree by recursion
	preOrder(node->left);
	
	//print Right Subtree
	preOrder(node->right);
	
}

int main()
{
	/* TREE 1 
	Construct the following tree
	   		 26
			/ \
		   10 3
		  / \  \
	    4   6   3
	     \
		 30
	*/
	
	Node* T = newNode(26);
	T->right = newNode(3);
	T->right->right = newNode(3);
	T->left = newNode(10);
	T->left->left = newNode(4);
	T->left->left->right = newNode(30);
	T->left->right = newNode(6);

	/* TREE 2
	Construct the following tree
	 	 10
		/ \
	   4   6
	    \
		30
	*/
	
	Node* S = newNode(10);
	S->right = newNode(6);
	S->left = newNode(4);
	S->left->right = newNode(30);

	cout<< "Pre Order traversal of binary tree T : "<<endl;
    preOrder(T);
    
    cout<<endl<< "\nPre Order traversal of binary tree S : "<<endl;
    preOrder(S);
    
    
	if (isSubtree(T, S))
		cout <<endl<< "\nTree 2 is subtree of Tree 1";
	else
		cout <<endl<< "\nTree 2 is not a subtree of Tree 1";

return 0;
}
