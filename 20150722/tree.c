// binary search tree
#include "algorithm.h"
struct node *root;

void insert_data(int data)
{
	struct node *temp;
	struct node **p = &root;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = 0;
	temp->right = 0;

	while (*p)
	{
		if ((*p)->data > data)
			p = &(*p)->left;
		else if ((*p)->data < data)
			p = &(*p)->right;
		else
			return;
	}
	*p = temp;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };
	int i;
	struct node* temp;
	display(root);
	for (i = 0; i < 7; i++)
	{
		insert_data(a[i]);
		display(root);
	}
	display(root);
}
