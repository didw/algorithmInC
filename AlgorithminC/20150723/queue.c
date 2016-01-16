#include "queue.h"

void init_queue()
{
	head = (qnode*)malloc(sizeof(qnode));
	tail = (qnode*)malloc(sizeof(qnode));
	head->next = tail;
	head->prev = head;
	tail->next = tail;
	tail->prev = head;
}

void clear_queue()
{
	qnode *t, *s;
	for (t = head->next; t != tail; t = t->next)
	{
		s = t;
		free(s);
	}
	head->next = tail;
	tail->prev = head;
}

int is_empty()
{
	if (head->next == tail)
		return 1;
	return 0;
}

int put(int k)
{
	qnode *t = (qnode*)malloc(sizeof(qnode));
	t->key = k;

	tail->prev->next = t;
	t->next = tail;
	t->prev = tail->prev;
	tail->prev = t;
	return k;
}

int get()
{
	qnode *t;
	int i;
	t = head->next;
	if (t == tail)
	{
		printf("\n queue underflow.");
		return -1;
	}
	i = t->key;
	head->next = t->next;
	t->next->prev = head;
	free(t);
	return i;
}