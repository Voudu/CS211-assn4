// This file contains all the code for building a binary tree
#include "stack.h"

// Changed the name of the treenode to t_node
// Need to change the name of the stack node to s_node

// Tree node struct
t_node *newNode(char *val)
{
	// Value, left and right connecting nodes to build tree
	t_node *ptr = (t_node *)malloc(sizeof(t_node));
	ptr->elem = val;
	ptr->left = NULL;
	ptr->right = NULL;

	return ptr;
}

// Function that splits the user input into tokenized values
// that allow for the program to perform operations and get
// the desired values from the user input
t_node *parseExpression(char *e)
{
	//char input[] = “60 43 18 * + 57 +”;

	s_node *head;
	stackInit(&head); // Create a new stack
	t_node *root;	  // Create the root note of the tree

	char *ptr = strtok(e, " ");
	while (ptr != NULL)
	{
		// If the value is an operator
		if (*ptr == '+' || *ptr == '*' || *ptr == '/' || *ptr == '-')
		{
			// Initialize space for a new root node
			root = newNode(ptr);

			// Get the left and right values from the head
			root->right = pop(&head);
			root->left = pop(&head);

			// Push the values from pop into the root
			push(&head, root);
		}
		// Otherwise, just push the integer value onto the head
		else
		{
			push(&head, newNode(ptr));
		}

		// Get the next val
		ptr = strtok(NULL, " ");
	}

	// Set root to the final value in head, clear head, return the desired value
	root = pop(&head);
	clear(&head);
	return root;
}

// Helper function for evalExpression
// Does mathematical operations based on the values passed to it
int doOperation(char operation, int leftVal, int rightVal)
{
	if (operation == '+')
		return leftVal + rightVal;
	else if (operation == '-')
		return leftVal - rightVal;
	else if (operation == '*')
		return leftVal * rightVal;
	else
		return leftVal / rightVal;
}

// Function that takes the tree node and returns the calculated final value
int evalExpression(t_node *r)
{
	// Root is null, return 0
	if (r == NULL)
	{
		return 0;
	}

	// If left and right of the root are both null
	else if (r->left == NULL && r->right == NULL)
	{
		return atoi(r->elem);
	}

	// Recursively go through the tree and get the values
	int leftVal = evalExpression(r->left);
	int rightVal = evalExpression(r->right);
	// Return the values to be calculated in the helper function
	return doOperation(r->elem[0], leftVal, rightVal);
}

// Print out the values in the tree with proper parentheses
// Print out the values using inorder traversal
void inFixPrint(t_node *r)
{
	if (r->elem[0] == '+' || r->elem[0] == '-' || r->elem[0] == '*' || r->elem[0] == '/')
	{
		printf("(");
	}
	if (r->left != NULL)
		inFixPrint(r->left);
	printf(" %s ", r->elem);
	if (r->right != NULL)
		inFixPrint(r->right);
	if (r->elem[0] == '+' || r->elem[0] == '-' || r->elem[0] == '*' || r->elem[0] == '/')
	{
		printf(")");
	}
}

// Print out the values using preorder traversal
void preOrderprint(t_node *r)
{
	if (r == NULL)
		return;
	//print node data
	printf("%s  ", r->elem);
	// visit left subtree
	preOrderprint(r->left);
	// visit right subtree
	preOrderprint(r->right);
}

// Print out the values using postorder traversal
void postOrderprint(t_node *r)
{
	if (r == NULL)
		return;
	// visit left subtree
	postOrderprint(r->left);
	//visit right subtree
	postOrderprint(r->right);
	//print node data
	printf("%s  ", r->elem);
}

// Recursively free the memory held in the tree
void destroyTree(t_node *r)
{
	if (r == NULL)
	{
		return;
	}

	destroyTree(r->left);
	destroyTree(r->right);
	printf("node memory freed\n");

	free(r);
	// clear all tree node memory...

	// recursively traverse through tree and free memory from
	// left to right.. EZ
}