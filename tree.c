#include "stack.h"

// Changed the name of the treenode to t_node
// Need to change the name of the stack node to s_node

t_node *newNode(char *val)
{

	t_node *ptr = (t_node *)malloc(sizeof(t_node));
	ptr->elem = val;
	ptr->left = NULL;
	ptr->right = NULL;

	return ptr;
}

t_node *parseExpression(char *e)
{
	//char input[] = “60 43 18 * + 57 +”;

	s_node *head;
	stackInit(&head); // Create a new stack
	t_node *root;	  // Create the root note of the tree

	/*
	root->elem = " ";
	root->left = NULL;
	root->right = NULL;
	*/

	char *ptr = strtok(e, " ");
	while (ptr != NULL)
	{

		if (*ptr == '+' || *ptr == '*' || *ptr == '/' || *ptr == '-')
		{

			root = newNode(ptr);

			// Pop top value
			//t_node *temp = pop(head);
			// !!!!!!! IF TOP IS NOT NULL - THEN WE CAN POP
			root->right = pop(&head);

			//t_node *temp2 = pop(root);
			root->left = pop(&head);

			push(&head, root);
		}
		else
		{
			push(&head, newNode(ptr));
		}

		ptr = strtok(NULL, " ");
	}

	root = pop(&head);
	//printf("exited parseExpression()\n");
	clear(&head);
	return root;
}
/*
int evalExpression(t_node *r) {
	int sum = 0;
	int leftVal, rightVal;
	char operand;
	// See if the root is a operand
	if (r->elem[0] != '+' || r->elem[0] != '-' || r->elem[0] != '*' || r->elem[0] != '/') {
		// If it is an operand, just return the value
		return r->elem;
	}
	
	else {
		if (r->left != NULL) {
			evalExpression(r->left);
		}
		if (r->elem[0] == '+' || r->elem[0] == '-' || r->elem[0] == '*' || r->elem[0] == '/') {
			operand = r->elem[0];
		}
		else {
			leftVal = atoi(r->elem);
		}
	}
}
*/

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

void inOrderprint(t_node *r)
{
	if (r == NULL)
		return;
	// visit left subtree
	inOrderprint(r->left);
	//print node data
	printf("%s  ", r->elem);
	//visit right subtree
	inOrderprint(r->right);
}

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

/*
int main(int argc, char const *argv[])
{

	t_node *root = newNode(6);
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
*/
