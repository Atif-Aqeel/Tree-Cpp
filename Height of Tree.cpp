/*
Given a binary tree, the task is to find the height of the tree. 
Height of the tree is the number of edges in the tree from the root to the deepest node, Height of the empty tree is 0.

Follow the below steps to Implement the idea:
-Traverse the tree in level order traversal starting from root.
	-Initialize an empty queue Q, a variable depth and push root, then push null into the Q.
	-Run a while loop till Q is not empty.
		-Store the front element of Q and Pop out the front element.
		-If the front of Q is NULL then increment depth by one and if queue is not empty then push NULL into the Q.
		-Else if the element is not NULL then check for its left and right children and if they are not NULL push them into Q.
-Return depth.

Another Method to find height using Level Order Traversal:
This method also uses the concept of Level Order Traversal but we wont be adding null in the Queue. 
Simply increase the counter when the level increases and push the children of current node into the queue, 
then remove all the nodes from the queue of the current Level.
*/


#include <bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node *left, *right;
};

Node* newNode(int key){
	
	Node* temp = new Node;
	temp->key = key;
	temp->left = temp->right = NULL;
	
	return (temp);
}

/*Function to find the height(depth) of the tree*/
int height(Node* root){

	// Initialising a variable to count the height of tree
	queue<Node*> q;
	
	//puch()-bulit in method to enter root in queue
	q.push(root);

	int height = 0;
	while (!q.empty()) {
		
		//size()-bulit in method to get the size of queue
		int size = q.size();
		for (int i = 0; i < size; i++){
			
			Node* temp = q.front();
			q.pop();
			
			if (temp->left != NULL) {
				q.push(temp->left);
			}
			
			if (temp->right != NULL) {
				q.push(temp->right);
			}
		}
		height++;
	}
	return height;
}

int main(){

	Node* root = newNode(1);

	root->left = newNode(2);
	root->right = newNode(3);
	
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	cout << "Height(Depth) of tree is: " << height(root);


}
