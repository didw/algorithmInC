#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int data;
	struct _node *next;
	struct _node *prev;
} NODE;

void __list_add(NODE *temp, NODE *prev, NODE *next)
{
	temp->next = next;
	prev->next = temp;
	temp->prev = prev;
	next->prev = temp;
}

void list_add(NODE *temp, NODE *head)
{
	__list_add(temp, head, head->next);
}

void list_add_tail(NODE *temp, NODE *head)
{
	__list_add(temp, head->prev, head);
}

//-----------------------------------------------------

void display(NODE *head)
{
	NODE *temp;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next)
		printf("<->[%d]", temp->data);
	printf("<->[head]\n");
	getchar();
}

int main()
{
	int i;
	NODE temp[7];
	NODE head = { 0, &head, &head };

	display(&head);
	for (i = 0; i<7; i++)
	{
		temp[i].data = i + 1;
		list_add(temp + i, &head);
		display(&head);
	}
	return 0;
}