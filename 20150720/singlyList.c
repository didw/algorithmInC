#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
} NODE;

NODE head;

void init(NODE *head)
{
	head->next = head;
}

void insert_data(NODE *temp, NODE *head)
{
	temp->next = head->next;
	head->next = temp;
}
//-----------------------------------------------------

void display(NODE *head)
{
	NODE *temp;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next)
		printf("->[%d]", temp->data);
	printf("->[head]\n");
	getchar();
}

int main()
{
	int i;
	NODE temp[7];
	init(&head);
	display(&head);
	for (i = 0; i<7; i++)
	{
		temp[i].data = i + 1;
		insert_data(temp + i, &head);
		display(&head);
	}
	return 0;
}