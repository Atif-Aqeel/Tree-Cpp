/*
The distance between two nodes is the minimum number of edges to be traversed to reach one node from another.

The distance between two nodes can be obtained in terms of lowest common ancestor-LCA.
We first find the LCA of two nodes. Then we find the distance from LCA to two nodes
*/

// find distance between n1 and n2 using one traversal
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

Node* LCA(Node* root, int n1, int n2){
	
	if (root == NULL)
		return root;
	
	if (root->key == n1 || root->key == n2)
		return root;

	//For left and right nodes
	Node* left = LCA(root->left, n1, n2);
	Node* right = LCA(root->right, n1, n2);

	//if both left and right nodes are not null then return root node
	if (left != NULL && right != NULL)
		return root;
	
	if (left == NULL && right == NULL)
		return NULL;
	
	if (left != NULL)
		return LCA(root->left, n1, n2);

	return LCA(root->right, n1, n2);
}

// Returns level of key k if it is present in tree, otherwise returns -1
int findLevel(Node* root, int k, int level){
	
	if (root == NULL)
		return -1;
		
	if (root->key == k)
		return level;

	//move to left node with +1 level
	int left = findLevel(root->left, k, level + 1);
	if (left == -1)
		return findLevel(root->right, k, level + 1);
	return left;
}

int findDistance(Node* root, int a, int b){

	//find LCA	
	Node* lca = LCA(root, a, b);

	int d1 = findLevel(lca, a, 0);
	int d2 = findLevel(lca, b, 0);

	return (d1 + d2);
}

int main(){
	
	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
	root->right->left->right = newNode(8);
	
	cout << "Dist(4, 5) = " << findDistance(root, 4, 5);
	cout << "\nDist(4, 6) = " << findDistance(root, 4, 6);
	cout << "\nDist(3, 4) = " << findDistance(root, 3, 4);
	cout << "\nDist(2, 4) = " << findDistance(root, 2, 4);
	cout << "\nDist(8, 5) = " << findDistance(root, 8, 5);

return 0;
}
