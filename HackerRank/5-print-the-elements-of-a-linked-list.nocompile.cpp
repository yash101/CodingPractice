#include <stdio.h>

void Print(Node* head)
{
	while(head != NULL)
	{
		printf("%d\n", head->data);
		head = head->next;
	}
}
