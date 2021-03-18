#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct treeNode
{

	char *elem;
	struct treeNode *left;
	struct treeNode *right;
} t_node;

t_node *parseExpression(char *str);
t_node *newNode(char *val);
void destroyTree(t_node *r);

//int evalExpression(t_node *r);
void inFixPrint(t_node *r);
void preOrderprint(t_node *r);
void inOrderprint(t_node *r);
void postOrderprint(t_node *r);