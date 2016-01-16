// 알고리즘
// 1. 알고리즘의 성능을 측정하는 방법
// 2. 알고리즘의 성능을 분석하는 방법
// 3. 탐색과 정렬
// 4. 리스트와 트리
// 5. 분할정복법
// 6. 동적계획법
// 7. 탐욕법
// 8. 그래프
// 9. 최소신장트리와 최단거리

// 7. 구조체의 정렬 제한을 강제로 1로 변경하는 방법
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

// 6. 구조체의 정렬 제한
// 정렬 제한이란
// 데이터가 메모리에 저장될 때 해당 메모리 주소에 대한 제약 사항
// 데이터가 저장될 위치가 특정한 단위로 정렬되어 있어야 한다.
// 가장 큰 멤버의 타입으로 정렬 제한을 따른다.
// int : 4
// double : 8
// float : 4
// short : 2
// char : 1
// 구조체의 패딩 : 정렬 제한을 통해 메모리에 생기는 공백 영역
// 데이터가 메모리에 배치할 시작주소를 결정하기 위한 데이터의 크기
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


// 5. 포인터 배열
// 포인터를 담는 배열
#if 0
#include <stdio.h>

void add(int a, int b) { printf("add\n"); }
void sub(int a, int b) { printf("sub\n"); }
void mul(int a, int b) { printf("mul\n"); }
void div(int a, int b) { printf("div\n"); }

int main()
{
	char *name[3] = { "이순신", "홍길동", "강감찬" };
	// sizeof(name) : 12
	int x, y, z;
	int *val[3] = { &x, &y, &z };
	// 함수포인터의 배열
	// 
	void(*fp[4])(int, int) = { add, sub, mul, div };

	int i;
	for (i = 0; i < 4; i++)
		fp[i](1, 2);
}
#endif


// 4.함수포인터
// 함수의 주소를 담은 포인터
#if 0
#include <stdio.h>
void foo()
{
	printf("foo called!\n");
}

// 함수포인터를 인자로 보냈을 경우
void goo(void(*p)())
{
	p();
}

// 함수포인터를 리턴하는 함수
void(*hoo())()
{
	return foo;
}

int main()
{
	void(*p)() = &foo;	// 가독성이 높다.
	void(*p2)() = foo;	// 간결하다.
	(*p2)();
	p();
	goo(foo);
	hoo()();
}
#endif

#if 0
// 3. 포인터의 연산
// 컴파일러가 첨자를 해석하는 방법 -> 포인터 연산
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
// 2. 배열과 포인터
#include <stdio.h>
// 배열은 함수에 전달될 때 배열 전체를 보내는 것이 아니라
// 배열의 시작 주소를 보낸다.
// 배열은 call by reference
void foo(int *a) //void foo(int a[])
{
	printf("foo : %d\n", sizeof(a));	// 4
	// a[1] = 1;	
}

int main()
{
	// a배열의 타입 : int? int[10]
	// decay
	// 배열의 이름은 일반적으로 배열의 첫번째 원소의 시작주소로 해석된다.
	// sizeof, 주소연산자(&)
	int a[10] = { 0, };		// 타입 : int[10]
	int *p = a;		// 첫번째 원소 : int
	int i = 10;
	int *ip = &i;	// 타입 : int*, 대상체 : int
	int(*p2)[10] = &a;	// int[10]

	int b[3][4] = { 0, };	// 타입은 int[3][4], 원소의 타입??
	int(*p3)[4] = b;	// p3
	p3[0][0] = 10;

	//int(*p)[10]

	printf("main : %d\n", sizeof(a));	// 40
	foo(a);
}
#endif

#if 0
#include <stdio.h>
// 1. 간단한 포인터 정리
// 실행 : ctrl+f5
void swap(int *a, int *b)
{
	int temp; 
	temp = *a;
	*a = *b;
	*b = temp;
}
// C언어의 함수 호출 방식 : call by value
// 인자로 받은 변수(대상체)의 값을 변경하기 위해 사용하는 매커니즘
int main()
{
	int a = 3, b = 4;
	swap(&a, &b);
	printf("%d %d\n", a, b);
}
#endif
