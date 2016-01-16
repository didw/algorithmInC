// 3_bubble.c
// 거품 정렬
// 배열의 인접한 요소를 비교해서 교환하는 정렬
// 알고리즘
// 1. i = 0;
// 2. i<n-1이 되면 끝난다.
// 3. j = 1;
// 4. j < n-i이 되면 끝난다.
// 5. a[j-1] > a[j] 이면 교환한다.

#if 0
#include "algorithm.h"

void bubble_sort(int *a, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
				swap(&a[j - 1], &a[j]);
		}
	}
}


int main()
{
	int a[] = { 9, 1, 6, 8, 4, 3, 2, 0 };
	int n = sizeof(a) / sizeof(a[0]);
	// 거품 정렬 실행
	bubble_sort(a, n);
	// 배열 출력 함수
	print_array(a, n);
}
#endif

#if 0
// 일반화된 swap()함수 만들기
void swap_int(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void swap_double(double *a, double *b)
{
	double temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	int ai = 3, bi = 4;
	double ad = 3.0, bd = 4.0;

	swap_int(&ai, &bi);
	swap_double(&ad, &bd);

	printf("%d %d\n", ai, bi);
	printf("%lf %lf\n", ad, bd);
}
#endif

#if 0
#include <stdio.h>
// 일반화된 swap()함수 만들기
// 모든 타입을 swap()할 수 있는 함수를 만들려면?
// 바이트 단위로 swap을 진행하면 일반화된 swap()을 만들 수 있다.
// 사용자가 swap()호출시 캐스팅을 해줘야 했다. 불편하다.
void swap(char *a, char *b, int width)
{
	char temp;
	int i;
	// 바이트 단위로 swap을 진행, width만큼 루프를 돈다.
	// 1바이트씩 width만큼 교환
	for (i = 0; i < width; i++, a++, b++)
	{
		temp = *a;
		*a = *b;
		*b = temp;
	}
}
//===============================================
int main()
{
	int ai = 3, bi = 4;
	double ad = 3.0, bd = 4.0;

	swap((char*)&ai, (char*)&bi, sizeof(ai));
	swap((char*)&ad, (char*)&bd, sizeof(ad));

	printf("%d %d\n", ai, bi);
	printf("%lf %lf\n", ad, bd);
}
#endif

#if 0
#include <stdio.h>
// 일반화된 swap()함수 만들기
// 모든 타입을 swap()할 수 있는 함수를 만들려면?
// void*를 이용해서 일반화 하자.
// void*는 모든 포인터를 형변환없이 받을 수 있다.
// void*는 대상체가 없는 포인터이기 때문에, 사용할 때에는 형변환을 반드시 해줘야 한다.
void swap(void *a, void *b, int width)
{
	char temp;
	int i;
	char *p = (char*)a;
	char *q = (char*)b;
	// 바이트 단위로 swap을 진행, width만큼 루프를 돈다.
	// 1바이트씩 width만큼 교환
	for (i = 0; i < width; i++, p++, q++)
	{
		temp = *p;
		*p = *q;
		*q = temp;
	}
}
//===============================================
int main()
{
	int ai = 3, bi = 4;
	double ad = 3.0, bd = 4.0;

	swap(&ai, &bi, sizeof(ai));
	swap(&ad, &bd, sizeof(ad));

	printf("%d %d\n", ai, bi);
	printf("%lf %lf\n", ad, bd);
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 일반화된 swap()함수 만들기
// 모든 타입을 swap()할 수 있는 함수를 만들려면?
// void*를 이용해서 일반화 하자.
// 기존의 라이브러리인 memcpy를 이용하자.
// 성능 : for루프보다 빠르다.
// 설계 철학 : 기존의 라이브러리를 활용하자.

void swap(void *a, void *b, int width)
{
	// temp의 메모리를 heap에 만든다.
	// memcpy사용해서 a, b swap
	// memcpy(void * dest, void* src, size_t width);
	void *temp = malloc(width);
	memcpy(temp, a, width);
	memcpy(a,	 b, width);
	memcpy(b, temp, width);
	free(temp);
}
//===============================================
int main()
{
	int ai = 3, bi = 4;
	double ad = 3.0, bd = 4.0;

	swap(&ai, &bi, sizeof(ai));
	swap(&ad, &bd, sizeof(ad));

	printf("%d %d\n", ai, bi);
	printf("%lf %lf\n", ad, bd);
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 일반화된 swap()함수 만들기
// 모든 타입을 swap()할 수 있는 함수를 만들려면?
// void*를 이용해서 일반화 하자.
// 기존의 라이브러리인 memcpy를 이용하자.
// 성능 : for루프보다 빠르다.
// 설계 철학 : 기존의 라이브러리를 활용하자.

void swap(void *a, void *b, int width)
{
	// temp의 메모리를 heap에 만든다.
	// memcpy사용해서 a, b swap
	// memcpy(void * dest, void* src, size_t width);
	void *temp = malloc(width);
	memcpy(temp, a, width);
	memcpy(a, b, width);
	memcpy(b, temp, width);
	free(temp);
}
//===============================================
void bubble_sort(int *a, int n)
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 1; j < n - i; j++)
		{
			if (a[j - 1] > a[j])
				swap(a + j - 1, a + j, 4);	// j-1
		}
	}
}


int main()
{
	int a[] = { 9, 1, 6, 8, 4, 3, 2, 0 };
	int n = sizeof(a) / sizeof(a[0]);
	int i;
	// 거품 정렬 실행
	bubble_sort(a, n);
	// 배열 출력 함수
	for (i = 0; i < n; i++)
		printf("%5d", a[i]);
	printf("\n");
}
#endif

#if 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 일반화된 sort()함수 만들기
// 

void swap(void *a, void *b, int width)
{
	// temp의 메모리를 heap에 만든다.
	// memcpy사용해서 a, b swap
	// memcpy(void * dest, void* src, size_t width);
	void *temp = malloc(width);
	memcpy(temp, a, width);
	memcpy(a, b, width);
	memcpy(b, temp, width);
	free(temp);
}

int cmp_int(void *a, void *b)
{
	return *(int*)a - *(int*)b;
}

int cmp_double(const void *a, const void *b)
{
	return *(double*)a - *(double*)b;
}

void bubble_sort(void *a, int n, int width, int(*cmp)(const void*, const void*))
{
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 1; j < n - i; j++)
		{
			//if (a[j - 1] > a[j])		// 첨자연산 a[j] =>*(a+j) => (int*)
			if (cmp((char*)a+(j-1)*width, (char*)a+j*width) > 0)
				swap((char*)a + (j - 1)*width, (char*)a + j*width, width);	// j-1
		}
	}
}

//===============================================

int main()
{
	int a[] = { 9, 1, 6, 8, 4, 3, 2, 0 };
	int n = sizeof(a) / sizeof(a[0]);
	int i;
	// 거품 정렬 실행
	//bubble_sort(a, n, sizeof(a[0]), cmp_int);
	qsort(a, n, sizeof(a[0]), cmp_int);

	// 배열 출력 함수
	for (i = 0; i < n; i++)
		printf("%5d", a[i]);
	printf("\n");
}
#endif
