#include <stdio.h>
#include <stdlib.h>

// 구조체 멤버의 offset을 구하는 방법
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
	printf("%d\n", &((AAA*)0)->b);	// 구조체의 시작주소를 0으로 설정하고, 멤버에 접근
	p = (AAA*)((char*)temp - (unsigned long)&((AAA*)0)->b);
	printf("%d\n", p->a);
}
#endif

#if 1
// 일반화 리스트 만들기 2단계
// node의 데이터 관련 멤버 삭제, 데이터 자료구조에 노드를 삽입한다.
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
		// 리스트의 주소를 알 때, 구조체 전체의 주소를 가져오는 방법?
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
	AAA a[2] = { { "주몽", 34, }, { "대소", 37, } };
	// AAA a[2] = { { { 0, }, "주몽", 34 }, { { 0, }, "대소", 37} };
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
// 일반화 리스트 만들기 1단계
// void*를 이용한 일반화 -> 약한 결합
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
	AAA a[2] = { "주몽", "대소" };
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