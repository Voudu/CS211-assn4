void stackInit(s_node* head){
	
	 *head = NULL;
}

void push(s_node* head, char *val){
	 
	 s_node* newNode = (s_node*) malloc(sizeof(s_node));
	 newNode->elem = *val;
	 newNode->next = *hd;
	 *hd = newNode;
	 
	 printf("Pushed %c\n", *val);
}

int isEmpty(s_node* head){
	
	 if(head == NULL){
		 return TRUE;
	 }
	 else{
		 return FALSE;
	 }
}

s_node* pop(s_node* head){
	 
	 if(isEmpty(*head) == TRUE){
		 return;
	 }
	 
	 s_node* temp = *head;
	 *head = temp->next;
	 
	 return temp;
}

void clear(s_node* head){
	
	 if(*head == NULL){
		 return;
	 }
	 
	 s_node* temp = *head;
	 
	 while(temp != NULL){
		 
		 free(temp);		 
		 temp = temp->next;
	 }
}