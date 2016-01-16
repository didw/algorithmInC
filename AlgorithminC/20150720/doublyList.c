#include <stdio.h>
#include <stdlib.h>

// ����ü ����� offset�� ���ϴ� ���
#if 0
typedef struct
{
	int a;
	int b;
	int c;
} AAA;

int main()
{
	AAA A = { 1, 2, 3 };
	int *temp = &A.b;
	AAA *p;
	printf("%p\n", &A);
	printf("%p\n", &A.a);
	printf("%p\n", &A.b);
	printf("%p\n", &A.c);
	printf("%d\n", &((AAA*)0)->b);	// ����ü�� �����ּҸ� 0���� �����ϰ�, ����� ����
	p = (AAA*)((char*)temp - (unsigned long)&((AAA*)0)->b);
	printf("%d\n", p->a);
}
#endif

#if 1
// �Ϲ�ȭ ����Ʈ ����� 2�ܰ�
// node�� ������ ���� ��� ����, ������ �ڷᱸ���� ��带 �����Ѵ�.
typedef struct _node
{
	struct _node *next;
	struct _node *prev;
} NODE;

typedef struct
{
	char name[20];
	int age;
	NODE list;
} AAA;

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

#define list_entry(ptr, type, member) \
	(type*)((char*)ptr - (unsigned long)&((type*)0)->member)

void display(NODE *head)
{
	NODE *temp;
	AAA *a;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next)
	{
		// ����Ʈ�� �ּҸ� �� ��, ����ü ��ü�� �ּҸ� �������� ���?
		// a = (AAA*)temp;
		// p + 1 => p + sizeof(*p)*1
		//a = (AAA*)((char*)temp - (sizeof(AAA) - sizeof(NODE)));
		// a = (AAA*)((char*)temp - (unsigned long)&((AAA*)0)->list);
		a = list_entry(temp, AAA, list);

		printf("<->[%s, %d]", a->name, a->age);
	}
	printf("<->[head]\n");
	getchar();
}

int main()
{
	int i;
	AAA a[2] = { { "�ָ�", 34, }, { "���", 37, } };
	// AAA a[2] = { { { 0, }, "�ָ�", 34 }, { { 0, }, "���", 37} };
	NODE head = { &head, &head };

	display(&head);
	for (i = 0; i<2; i++)
	{
		list_add(&a[i].list, &head);
		display(&head);
	}
	return 0;
}
#endif

#if 0
// �Ϲ�ȭ ����Ʈ ����� 1�ܰ�
// void*�� �̿��� �Ϲ�ȭ -> ���� ����
typedef struct _node
{
	void* data;
	struct _node *next;
	struct _node *prev;
} NODE;

typedef struct
{
	char name[20];
} AAA;

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
	AAA *a;
	system("cls");
	printf("[head]");
	for (temp = head->next; temp != head; temp = temp->next)
	{
		a = (AAA*)temp->data;
		printf("<->[%s]", a->name);
	}
	printf("<->[head]\n");
	getchar();
}

int main()
{
	int i;
	NODE temp[2];
	AAA a[2] = { "�ָ�", "���" };
	NODE head = { 0, &head, &head };

	display(&head);
	for (i = 0; i<2; i++)
	{
		temp[i].data = a + i;
		list_add(temp + i, &head);
		display(&head);
	}
	return 0;
}
#endif