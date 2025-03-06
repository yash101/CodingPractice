Node* Insert(Node* head, int data)
{
	if(head == NULL)
	{
		head = new Node;
		head->next = NULL;
		head->data = data;
		return head;
	}
	Node* unchanged = head;
	while(head->next != NULL)
		head = head->next;
	head->next = new Node;
	head->next->next = NULL;
	head->next->data = data;
	return unchanged;
}
