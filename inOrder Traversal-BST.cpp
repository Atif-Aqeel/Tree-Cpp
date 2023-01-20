/*
<> Inorder		Left -> Root -> Right
<> Preorder		Root -> Left -> Right 
<> Postorder	Left -> Right -> Root

Algorithm Inorder(tree)
	Traverse the left subtree, i.e., call Inorder(left->subtree)
	Visit the root.
	Traverse the right subtree, i.e., call Inorder(right->subtree)

In the case of binary search trees (BST), Inorder traversal gives nodes in non-decreasing order. 
To get nodes of BST in non-increasing order, a variation of Inorder traversal where Inorder traversal is reversed can be used. 
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

//Inorder Traversal 
void inOrder(struct Node* node){
	if(node == NULL){
		return ;
	}
	
	//Print Left Subtree by recursion
	inOrder(node->left);
	
	//Print root
	cout<< node->data <<" ";
	//inOrder(node->data); error
	
	//print Right Subtree
	inOrder(node->right);
	
}

int main(){
	
	struct Node* root = newNode(1);
	root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    cout << "\nInorder traversal of binary tree is \n";
    inOrder(root);
	
return 0;
}
