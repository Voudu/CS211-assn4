#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "tree.h"

#define TRUE 1
#define FALSE 0

typedef struct stackNode{
	
	struct treeNode* elem;
	struct stackNode* next;
	
} s_node;

void stackInit(s_node** head); // Initializes head to NULL
void push(s_node** head, t_node* treeNode);
int isEmpty(s_node* head);
t_node* pop(s_node** head);
void clear(s_node** head);