void stackInit(node* head){
	
	 *head = NULL;
}

void push(node* head, char *val){
	 
	 node* newNode = (node*) malloc(sizeof(node));
	 newNode->elem = *val;
	 newNode->next = *hd;
	 *hd = newNode;
}

int isEmpty(node* head){
	
	 if(head == NULL){
		 return TRUE;
	 }
	 else{
		 return FALSE;
	 }
}

node* pop(node* head){
	 
	 if(isEmpty(*head) == TRUE){
		 return;
	 }
	 
	 node* temp = *head;
	 *head = temp->next;
	 
	 return temp;
}

void clear(node* head){
	
	 if(*head == NULL){
		 return;
	 }
	 
	 node* temp = *head;
	 
	 while(temp != NULL){
		 
		 free(temp);		 
		 temp = temp->next;
	 }
}