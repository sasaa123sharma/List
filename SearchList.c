//search in a linked list
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

int SearchNodeItr(NODE *head, int data)
{
	while(head && (head->data != data))
		head = head->next;

	if(head) 
		return 1;
	else	
		return 0;
	
}


int SearchNodeRec(NODE *head, int data)
{
	if(head)
	{
		if( head->data == data)
			return 1;
		else
			return SearchNodeRec(head->next, data);		
	}
	else	
		return 0;
}

void AddNode(NODE **head, int data)
{
	NODE *temp = malloc(sizeof(NODE));
	temp->data = data;

	temp->next = *head;

	*head = temp;	
}

int main()
{
	//search in a linked list
	NODE *head = NULL;
	AddNode(&head, 1);	
	AddNode(&head, 2);	
	AddNode(&head, 3);	
	AddNode(&head, 4);	

	if(SearchNodeItr(head, 1))
		printf("element is present\n");
	else
		printf("element is not present\n");
		
	if(SearchNodeRec(head, 5))
		printf("element is present\n");
	else
		printf("element is not present\n");

	return 0;
}
