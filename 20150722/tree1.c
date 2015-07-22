// rb_tree
#include <stdio.h>
#include <stdlib.h>
#include "rbtree.h"

struct sawon
{
	int data;
	struct rb_node node;
};

struct AAA
{
	int data;
	int color;
};

struct sawon * insert_data(struct rb_root *root, int data, struct rb_node * node)
{
	struct rb_node ** p = &root->rb_node;
	struct rb_node * parent = NULL;
	struct sawon * s;

	while (*p)
	{
		parent = *p;
		s = rb_entry(parent, struct sawon, node);

		if (data < s->data)
			p = &(*p)->rb_left;
		else if (data > s->data)
			p = &(*p)->rb_right;
		else
			return s;
	}

	rb_link_node(node, parent, p);
	// 균형을 잡아주는 함수
	rb_insert_color(node, root);
	return NULL;
}

void __rb_display(struct rb_node *temp, struct AAA(*a)[10],
	int *row, int *col)
{
	struct sawon *s;
	if (temp == 0)
		return;
	++(*row);
	__rb_display(temp->rb_left, a, row, col);
	s = rb_entry(temp, struct sawon, node);
	a[*row][(*col)].data = s->data;
	a[*row][(*col)++].color = rb_color(temp);

	__rb_display(temp->rb_right, a, row, col);
	--(*row);
	return;
}

void rb_display(struct rb_root *root)
{
	struct AAA a[10][10] = { 0, };
	int row = -1;
	int col = 0;
	int i, j;

	__rb_display(root->rb_node, a, &row, &col);
	system("cls");
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (a[i][j].data != 0)
			{
				if (a[i][j].color)
					printf("[%2d]", a[i][j]);
				else
					printf("<%2d>", a[i][j]);
			}
			else
				printf("%4c", ' ');
		}
		printf("\n");
	}
	getchar();
}

int main()
{
	struct sawon s[8];
	struct rb_root root = { 0 };
	int i;
	for (i = 0; i < 8; i++)
	{
		s[i].data = i + 1;
		insert_data(&root, s[i].data, &s[i].node);
		rb_display(&root);
	}
}