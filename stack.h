// Header file stack.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "tree.h"

#define TRUE 1
#define FALSE 0

// Stack node struct containing the value and the next element pointer
typedef struct stackNode
{

	struct treeNode *elem;
	struct stackNode *next;

} s_node;

// Function prototypes
void stackInit(s_node **head);
void push(s_node **head, t_node *treeNode);
int isEmpty(s_node *head);
t_node *pop(s_node **head);
void clear(s_node **head);