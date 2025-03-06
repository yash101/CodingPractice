Node* InsertNth(Node* head, int data, int position)
{
	Node* unchanged = head;
	if(head == NULL)
	{
		head = new Node;
		node->next = NULL;
		node->data = data;
	}

	int pos = 0;
	while(head != NULL && pos < position)
		head = head->next;

	Node* n = new Node;
	n->next = head->next;
	head->next = n;
	return (position != 0) ? 0 : unchanged;
}
