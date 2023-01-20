/*
<> Inorder		Left -> Root -> Right
<> Preorder		Root -> Left -> Right 
<> Postorder	Left -> Right -> Root

Algorithm Preorder(tree)
	Visit the root.
	Traverse the left subtree, i.e., call Preorder(left->subtree)
	Traverse the right subtree, i.e., call Preorder(right->subtree) 
	
Preorder traversal is used to create a copy of the tree. Preorder traversal is also used to get prefix expressions on an expression tree 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

//Creae New Node
Node* newNode(int data){
	
	Node* temp = new Node;
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	return temp;	
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

int main(){
	
	struct Node* root = newNode(1);
	root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "\nPre Order traversal of binary tree is \n";
    preOrder(root);
	
return 0;
}
