Node* Insert(Node* head, int data)
{
	Node* n = new Node;
	n->next = head;
	n->data = data;
	return n;
}
