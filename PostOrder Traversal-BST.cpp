/*
<> Inorder		Left -> Root -> Right
<> Preorder		Root -> Left -> Right 
<> Postorder	Left -> Right -> Root

Algorithm Postorder(tree)
	Traverse the left subtree, i.e., call Postorder(left->subtree)
	Traverse the right subtree, i.e., call Postorder(right->subtree)
	Visit the root

Postorder traversal is used to delete the tree.
Postorder traversal is also useful to get the postfix expression of an expression tree
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

//Post order Traversal 
void postOrder(struct Node* node){
	if(node == NULL){
		return ;
	}
	
	//Print Left Subtree by recursion
	postOrder(node->left);
	
	//print Right Subtree
	postOrder(node->right);
	
	//Print root
	cout<< node->data <<" ";
	//psotOrder(node->data); error
	
}

int main(){
	
	struct Node* root = newNode(1);
	root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "\nPre Order traversal of binary tree is \n";
    postOrder(root);
	
return 0;
}
