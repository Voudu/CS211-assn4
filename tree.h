#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stack.h>

// hi

typedef struct treeNode{
	
	 struct stackNode* elem;
	 struct treeNode* left;
	 struct treeNode* right;	 
} t_node;

t_node* parseExpression(char* str);
t_node* newNode(node* stack_node);