/*
Two trees are identical when they have the same data and the arrangement of data is also the same.

Approach: To solve the problem follow the below idea:
To identify if two trees are identical, we need to traverse both trees simultaneously, and while traversing we need to compare data and children of the trees

Follow the given steps to solve the problem:
	1-If both trees are empty then return 1(Base case)
	2-Else If both trees are non-empty
		Check data of the root nodes (tree1->data ==  tree2->data)
		Check left subtrees recursively
		Check right subtrees recursively
		If the above three statements are true then return 1
	3-Else return 0 (one is empty and the other is not)
*/

#include <bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node* left;
	node* right;
};

/* Helper function that allocates a new node with the given data and NULL left and right pointers. */
node* newNode(int data){

	node* Node = new node();
	Node->data = data;
	Node->left = NULL;
	Node->right = NULL;

	return (Node);
}

/* Given two trees, return true if they are structurally identical */
int identicalTrees(node* a, node* b){
	
	/*1. both empty */
	if (a == NULL && b == NULL)
		return 1;

	/* 2. both non-empty -> compare them */
	if (a != NULL && b != NULL) {
		return (a->data == b->data
				&& identicalTrees(a->left, b->left)
				&& identicalTrees(a->right, b->right));
	}

	/* 3. one empty, one not -> false */
	return 0;
}

//Pre order Traversal 
void preOrder(struct node* node){
	
	if(node == NULL){
		return ;
	}
	
	cout<< node->data <<" ";
	preOrder(node->left);	
	preOrder(node->right);
	
}

int main(){

	node* root1 = newNode(1);
	node* root2 = newNode(1);

	root1->left = newNode(2);
	root1->right = newNode(3);
	root1->left->left = newNode(4);
	root1->left->right = newNode(5);

	root2->left = newNode(2);
	root2->right = newNode(3);
	root2->left->left = newNode(4);
	root2->left->right = newNode(5);

	cout<<"Pre Order Traversal of Tree 1 :"<<endl;
	preOrder(root1);
	
	cout<<"\nPre Order Traversal of Tree 2 :"<<endl;
	preOrder(root2);

	// Function call
	if (identicalTrees(root1, root2))
		cout << "\nBoth trees are identical.";
	else
		cout << "\nTrees are not identical.";

return 0;
}
