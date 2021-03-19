// This file contains all the code for building a stack
#include "stack.h"

// Initialize the values required for stack
void stackInit(s_node **head)
{
	*head = NULL;
}

// Push values onto head using the values from treeNode
void push(s_node **head, t_node *treeNode)
{
	s_node *newNode = (s_node *)malloc(sizeof(s_node));
	newNode->elem = treeNode;
	newNode->next = *head;
	*head = newNode;
}

// Returns true or false if the head is empty
int isEmpty(s_node *head)
{
	if (head == NULL)
		return TRUE;
	else
		return FALSE;
}

// Removes and returns the top value in the stack
t_node *pop(s_node **head)
{
	// Checks to see if the head is empty
	if (isEmpty(*head) == TRUE)
	{
		printf("stack is empty, not popping - returning NULL\n");
		return NULL;
	}
	s_node *temp = *head;
	t_node *retElem = temp->elem;
	*head = temp->next;
	free(temp);
	return retElem;
}

// Remove all the values in head
void clear(s_node **head)
{

	if (*head == NULL)
		return;

	s_node *temp = *head;

	while (temp != NULL)
	{
		free(temp);
		temp = temp->next;
	}
}