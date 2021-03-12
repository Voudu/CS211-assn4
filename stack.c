void stackInit(s_node* head){
	
	 *head = NULL;
}

void push(s_node* head, t_node* treeNode){
	 
	 s_node* newNode = (s_node*) malloc(sizeof(s_node));
	 newNode->elem = *treeNode;
	 newNode->next = *hd;
	 *hd = newNode;
}

int isEmpty(s_node head){
	
	 if(head == NULL){
		 return TRUE;
	 }
	 else{
		 return FALSE;
	 }
}

t_node* pop(s_node* head){
	 
	 if(isEmpty(*head) == TRUE){
		 return;
	 }
	 
	 // create a t_node pointer which points to the head's element
	 t_node* retElem = *head->elem;
	 
	 // set a temp stack node = to the head
	 s_node* temp = *head;
	 
	 // set head equal to the next node in the stack
	 *head = temp->next;
	 
	 // free the old head & return its element
	 free(temp);	 
	 return retElem;
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