#include "stack.h"

// Changed the name of the treenode to t_node
// Need to change the name of the stack node to s_node

t_node *newNode(char* val)
{

	t_node *ptr = (t_node *)malloc(sizeof(t_node));
	ptr->elem = val;
	ptr->left = NULL;
	ptr->right = NULL;
	return ptr;
}

t_node* parseExpression(char* e) {
	//char input[] = “60 43 18 * +57 +”;
	
	s_node* head;
	stackInit(head); // Create a new stack
	t_node *root; // Create the root note of the tree
	
	/*
	root->elem = " ";
	root->left = NULL;
	root->right = NULL;
	*/
	
	char *ptr = strtok(e, " ");
	while (ptr != NULL)
	{

		//printf(“% s “, ptr);
		ptr = strtok(NULL, " ");
		
		if (isdigit(atoi(ptr)) > 0)
		{
			push(head, newNode(ptr));
		}

		else {
			root = newNode(ptr);
			
			// Pop top value
			//t_node *temp = pop(head);
			root->right = pop(head);
			//t_node *temp2 = pop(root);
			root->left = pop(head);
			push(head, root);
		}

		root = pop(head);
		return root;
	}

}

void preOrderprint(t_node *r)
{
	if (r == NULL)
		return;
	//print node data
	printf("%s,  ", r->elem);

	// visit left subtree
	preOrderprint(r->left);
	//visit right subtree
	preOrderprint(r->right);
}

void inOrderprint(t_node *r)
{
	if (r == NULL)
		return;
	// visit left subtree
	inOrderprint(r->left);
	//print node data
	printf("%s,  ", r->elem);

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
	printf("%s,  ", r->elem);
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
