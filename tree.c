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
	//char input[] = “60 43 18 * + 57 +”;
	
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
		printf("1: %s \n", ptr);
		
		
		if (*ptr == '+' || *ptr == '*' || *ptr == '/' || *ptr == '-'){

			root = newNode(ptr);

			// Pop top value
			//t_node *temp = pop(head);
			root->right = pop(head);

			//t_node *temp2 = pop(root);
			root->left = pop(head);
			
			push(head, root);

		}
		else
		{
			push(head, newNode(ptr));
		}

		ptr = strtok(NULL, " ");
		printf("\n2: %s \n", ptr);
	}
	
	root = pop(head);
	printf("exited loop\n");
	return root;
}

void preOrderprint(t_node *r)
{
	printf("start preorderprint\n");
	if (r == NULL)
	{
		printf("root is NULL\n");
		return;
	}
	printf("after if\n");
	//print node data
	//printf("%s,  ", r->elem);
	//printf("after print\n");

	// visit left subtree
	printf("visit left subtree\n");
	printf("r-left: %s", r->left->elem);
	preOrderprint(r->left);
	//visit right subtree
    printf("visit right subtree\n");
	preOrderprint(r->right);
	
	printf("end\n");
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
