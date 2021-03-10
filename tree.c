t_node* parseExpression(string e){
	 
	 
	
}

t_node* newNode(node* stack_node){
	
	 t_node* leafNode = (t_node*) malloc(sizeof(t_node));
	 leafNode->elem = *stack_node;
	 leafNode->left = NULL;
	 leafNode->right = NULL;
	 
	 return leafNode;	
}