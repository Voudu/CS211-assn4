#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
	int elem;
	struct TreeNode *left;
	struct TreeNode *right;
} node;

node *newNode(int val)
{

	node *ptr = (node *)malloc(sizeof(node));
	ptr->elem = val;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

void preOrderprint(node *r)
{
	if (r == NULL)
		return;
	//print node data
	printf("%d,  ", r->elem);

	// visit left subtree
	preOrderprint(r->left);
	//visit right subtree
	preOrderprint(r->right);
}

void inOrderprint(node *r)
{
	if (r == NULL)
		return;
	// visit left subtree
	inOrderprint(r->left);
	//print node data
	printf("%d,  ", r->elem);

	//visit right subtree
	inOrderprint(r->right);
}

void postOrderprint(node *r)
{
	if (r == NULL)
		return;
	// visit left subtree
	postOrderprint(r->left);

	//visit right subtree
	postOrderprint(r->right);
	//print node data
	printf("%d,  ", r->elem);
}

int main(int argc, char const *argv[])
{

	node *root = newNode(6);
	root->left = newNode(8);
	root->right = newNode(3);
	root->left->left = newNode(9);
	root->right->left = newNode(1);
	root->right->right = newNode(5);

	preOrderprint(root);
	printf("\n");
	inOrderprint(root);
	printf("\n");
	postOrderprint(root);
	printf("\n");

	return 0;
}
