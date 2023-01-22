/*
The diameter of a tree is the number of nodes on the longest path between two leaves in the tree. 

Diameter of a tree can be calculated by only using the height function, 
because the diameter of a tree is nothing but maximum value of (left_height + right_height + 1) for each node. 
So we need to calculate this value (left_height + right_height + 1) for each node and update the result. 
Time complexity – O(n) 
*/

#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

int height(Node* root, int& ans){
	
	if (root == NULL)
		return 0;

	int left_height = height(root->left, ans);

	int right_height = height(root->right, ans);

	// update the answer, because diameter of a tree is nothing but maximum value of
	// (left_height + right_height + 1) for each node
	ans = max(ans, 1 + left_height + right_height);		//max() builtin method

	return ( max(left_height, right_height) + 1 );
}

/* Computes the diameter of binary tree with given root. */
int diameter(Node* root){
	
	if (root == NULL)
		return 0;
	
	int ans = INT_MIN; // This will store the final answer
	
	height(root, ans);
	return ans;
}

Node* newNode(int data){
	
	struct Node* node = new Node;
	node->data = data;
	node->left = node->right = NULL;

	return (node);
}

int main(){
	
	struct Node* root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->left->left = newNode(4);
	root->left->right = newNode(5);

	printf("Diameter is %d\n", diameter(root));


return 0;
}


//INT_MIN specifies that an integer variable cannot store any value below this limit. 
//Values of INT_MAX and INT_MIN may vary from compiler to compiler. 
//Following are typical values in a compiler where integers are stored using 32 bits. 
//Value of INT_MAX is +2147483647, 	INT_MIN is -2147483647 -1
