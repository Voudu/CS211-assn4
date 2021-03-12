#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1;
#define FALSE 0;

typedef struct stackNode{
	
	struct treeNode* elem;
	struct stackNode* next;
	
} s_node;

void stackInit(node* head); // Initializes head to NULL
void push(node* head, char* val);
int isEmpty(node* head);
node* pop(node* head);
void clear(node* head);