#include <stdio.h>
#include <stdlib.h>

typedef struct _qnode
{
	int key;
	struct _qnode *next;
	struct _qnode *prev;
} qnode;

qnode *head, *tail;
void init_queue();
void clear_queue();
int is_empty();
int put(int k);
int get();