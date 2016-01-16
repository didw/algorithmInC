// �˰���
// 1. �˰����� ������ �����ϴ� ���
// 2. �˰����� ������ �м��ϴ� ���
// 3. Ž���� ����
// 4. ����Ʈ�� Ʈ��
// 5. ����������
// 6. ������ȹ��
// 7. Ž���
// 8. �׷���
// 9. �ּҽ���Ʈ���� �ִܰŸ�

// 7. ����ü�� ���� ������ ������ 1�� �����ϴ� ���
// MSVC 
// #pragma pack(1)
// #pragma pack(push, 1)
// #pragma pack(pop)
// GCC
// __attribute__((__packed__))
// __attribute__((__alignof__(1)))

#if 1
#pragma pack(push, 1)
struct B
{
	char a;
	int b;
	char c;
};
#pragma pack(pop)

int main()
{
	printf("%d\n", sizeof(struct B));	// 8, 12
	printf("%d\n", __alignof(struct B));	// 8, 12
}
#endif

// 6. ����ü�� ���� ����
// ���� �����̶�
// �����Ͱ� �޸𸮿� ����� �� �ش� �޸� �ּҿ� ���� ���� ����
// �����Ͱ� ����� ��ġ�� Ư���� ������ ���ĵǾ� �־�� �Ѵ�.
// ���� ū ����� Ÿ������ ���� ������ ������.
// int : 4
// double : 8
// float : 4
// short : 2
// char : 1
// ����ü�� �е� : ���� ������ ���� �޸𸮿� ����� ���� ����
// �����Ͱ� �޸𸮿� ��ġ�� �����ּҸ� �����ϱ� ���� �������� ũ��
// MSVC : __alignof
// GCC  : __alignof__
#if 0
struct A
{
	int a;
	char b;
	char c;
	char d;
	char e;
};

struct B
{
	char a;
	char d;
	int b;
	char c;
	char e;
};

int main()
{
	printf("%d %d\n", sizeof(struct A), sizeof(struct B));	// 8, 12
	printf("%d %d\n", sizeof(__alignof(struct A)), __alignof(struct B));	// 8, 12
}
#endif


// 5. ������ �迭
// �����͸� ��� �迭
#if 0
#include <stdio.h>

void add(int a, int b) { printf("add\n"); }
void sub(int a, int b) { printf("sub\n"); }
void mul(int a, int b) { printf("mul\n"); }
void div(int a, int b) { printf("div\n"); }

int main()
{
	char *name[3] = { "�̼���", "ȫ�浿", "������" };
	// sizeof(name) : 12
	int x, y, z;
	int *val[3] = { &x, &y, &z };
	// �Լ��������� �迭
	// 
	void(*fp[4])(int, int) = { add, sub, mul, div };

	int i;
	for (i = 0; i < 4; i++)
		fp[i](1, 2);
}
#endif


// 4.�Լ�������
// �Լ��� �ּҸ� ���� ������
#if 0
#include <stdio.h>
void foo()
{
	printf("foo called!\n");
}

// �Լ������͸� ���ڷ� ������ ���
void goo(void(*p)())
{
	p();
}

// �Լ������͸� �����ϴ� �Լ�
void(*hoo())()
{
	return foo;
}

int main()
{
	void(*p)() = &foo;	// �������� ����.
	void(*p2)() = foo;	// �����ϴ�.
	(*p2)();
	p();
	goo(foo);
	hoo()();
}
#endif

#if 0
// 3. �������� ����
// �����Ϸ��� ÷�ڸ� �ؼ��ϴ� ��� -> ������ ����
// a[1] = *(a+1)
int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	a[1] = 0;
	// *(a + 1) = *(1+a)
	1[a] = 10;
	printf("%d\n", a[1]);
}
#endif

#if 0
// 2. �迭�� ������
#include <stdio.h>
// �迭�� �Լ��� ���޵� �� �迭 ��ü�� ������ ���� �ƴ϶�
// �迭�� ���� �ּҸ� ������.
// �迭�� call by reference
void foo(int *a) //void foo(int a[])
{
	printf("foo : %d\n", sizeof(a));	// 4
	// a[1] = 1;	
}

int main()
{
	// a�迭�� Ÿ�� : int? int[10]
	// decay
	// �迭�� �̸��� �Ϲ������� �迭�� ù��° ������ �����ּҷ� �ؼ��ȴ�.
	// sizeof, �ּҿ�����(&)
	int a[10] = { 0, };		// Ÿ�� : int[10]
	int *p = a;		// ù��° ���� : int
	int i = 10;
	int *ip = &i;	// Ÿ�� : int*, ���ü : int
	int(*p2)[10] = &a;	// int[10]

	int b[3][4] = { 0, };	// Ÿ���� int[3][4], ������ Ÿ��??
	int(*p3)[4] = b;	// p3
	p3[0][0] = 10;

	//int(*p)[10]

	printf("main : %d\n", sizeof(a));	// 40
	foo(a);
}
#endif

#if 0
#include <stdio.h>
// 1. ������ ������ ����
// ���� : ctrl+f5
void swap(int *a, int *b)
{
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}
// C����� �Լ� ȣ�� ��� : call by value
// ���ڷ� ���� ����(���ü)�� ���� �����ϱ� ���� ����ϴ� ��Ŀ����
int main()
{
	int a = 3, b = 4;
	swap(&a, &b);
	printf("%d %d\n", a, b);
}
#endif
