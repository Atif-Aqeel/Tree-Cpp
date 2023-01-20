/*
An ancestor node of a node is either the parent of the node or the parent of some ancestor of the node. 
A descendant of a node is either a child of the node or a child of some descendant of the node

The lowest common ancestor is the lowest node in the tree that has both n1 and n2 as descendants, 
where n1 and n2 are the nodes for which we wish to find the LCA. 
Hence, the LCA of a binary tree with nodes n1 and n2 is the shared ancestor of n1 and n2 that is located farthest from the root. 

if n1 and n2 are present in the tree first and then finding the LCA of n1 and n2. 
To check whether the node is present in the binary tree or not then traverse on the tree for both n1 and n2 nodes separately

*/
/* C++ program to find LCA of n1 and n2 using one traversal
of Binary Tree. It handles all cases even when n1 or n2
is not there in Binary Tree */

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int key;
	struct Node *left, *right;
};

//create a new tree Node
Node* newNode(int key)
{
	Node* temp = new Node;
	temp->key = key;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

// This function returns pointer to LCA of two given values n1 and n2.
struct Node* findLCAUtil(struct Node* root, int n1, int n2)
{
	// Base case
	if (root == NULL)
		return NULL;

	// If either n1 or n2 matches with root's key, report the presence by returning root
	if (root->key == n1 || root->key == n2)
		return root;

	// Look for keys in left and right subtrees
	Node* left_lca = findLCAUtil(root->left, n1, n2);
	Node* right_lca = findLCAUtil(root->right, n1, n2);

	// If both of the above calls return Non-NULL nodes,
	// then one key is present in once subtree and other is present in other, So this node is the LCA
	if (left_lca and right_lca)
		return root;

	// Otherwise check if left subtree or right subtree is LCA
	return (left_lca != NULL) ? left_lca : right_lca;
	
}

// Returns true if key k is present in tree rooted with root
bool find(Node* root, int k)
{
	// Base Case
	if (root == NULL)
		return false;

	// If key is present at root, or in left subtree or right subtree, return true;
	if (root->key == k || find(root->left, k) || find(root->right, k))
		return true;

	// Else return false
	return false;
}

// This function returns LCA of n1 and n2 only if both n1 and n2 are present in tree, otherwise returns NULL;
Node* findLCA(Node* root, int n1, int n2)
{
	// Return LCA only if both n1 and n2 are present in tree
	if (find(root, n1) and find(root, n2))
		return findLCAUtil(root, n1, n2);

	// Else return NULL
	return NULL;
}

int main()
{

	Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);

	Node* lca = findLCA(root, 4, 5);

	if (lca != NULL)
		cout << "LCA(4, 5) = " << lca->key;
	else
		cout << "Keys are not present ";


	lca = findLCA(root, 4, 10);
	if (lca != NULL)
		cout << "\nLCA(4, 10) = " << lca->key;
	else
		cout << "\nKeys are not present ";

return 0;
}
