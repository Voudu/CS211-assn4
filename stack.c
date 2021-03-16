#include "stack.h"

void stackInit(s_node** head){
	
	 *head = NULL;
}

void push(s_node** head, t_node* treeNode){
	 
	 s_node* newNode = (s_node*) malloc(sizeof(s_node));
	 
	 newNode->elem = treeNode;
	 newNode->next = *head;
	 *head = newNode;
	 printf("pushed %s\n", newNode->elem->elem);
}

int isEmpty(s_node* head){
	
	 if(head == NULL){
		 return TRUE;
	 }
	 else{
		 return FALSE;
	 }
}

t_node* pop(s_node** head){
	 
	 if(isEmpty(*head) == TRUE){
		 printf("stack is empty, not popping - returning NULL\n");
		 return NULL;
	 }
	 s_node* temp = *head;
	 // create a t_node pointer which points to the head's element

	 t_node* retElem = temp->elem;
	 
	 // set a temp stack node = to the head

	 
	 // set head equal to the next node in the stack
	 *head = temp->next;
	 
	 printf("popped %s\n", retElem->elem);
	 // free the old head & return its element
	 free(temp);
	 //printf("popped %s\n", retElem->elem);
	 
	 return retElem;
}

void clear(s_node** head){
	
	 if(*head == NULL){
		 return;
	 }
	 
	 s_node* temp = *head;
	 
	 while(temp != NULL){
		 
		 free(temp);		 
		 temp = temp->next;
	 }
}