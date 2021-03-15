#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stack.h>



typedef struct treeNode{
	
	 char* elem[];
	 struct treeNode* left;
	 struct treeNode* right;	 
} t_node;

t_node* parseExpression(char* str);
t_node* newNode(node* stack_node);

void preOrderprint(t_node *r)
void inOrderprint(t_node *r)
void postOrderprint(t_node *r)