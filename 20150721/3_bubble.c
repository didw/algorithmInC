// 3_bubble.c
// ��ǰ ����
// �迭�� ������ ��Ҹ� ���ؼ� ��ȯ�ϴ� ����
// �˰���
// 1. i = 0;
// 2. i<n-1�� �Ǹ� ������.
// 3. j = 1;
// 4. j < n-i�� �Ǹ� ������.
// 5. a[j-1] > a[j] �̸� ��ȯ�Ѵ�.

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
	// ��ǰ ���� ����
	bubble_sort(a, n);
	// �迭 ��� �Լ�
	print_array(a, n);
}
#endif

#if 0
// �Ϲ�ȭ�� swap()�Լ� �����
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
// �Ϲ�ȭ�� swap()�Լ� �����
// ��� Ÿ���� swap()�� �� �ִ� �Լ��� �������?
// ����Ʈ ������ swap�� �����ϸ� �Ϲ�ȭ�� swap()�� ���� �� �ִ�.
// ����ڰ� swap()ȣ��� ĳ������ ����� �ߴ�. �����ϴ�.
void swap(char *a, char *b, int width)
{
	char temp;
	int i;
	// ����Ʈ ������ swap�� ����, width��ŭ ������ ����.
	// 1����Ʈ�� width��ŭ ��ȯ
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
// �Ϲ�ȭ�� swap()�Լ� �����
// ��� Ÿ���� swap()�� �� �ִ� �Լ��� �������?
// void*�� �̿��ؼ� �Ϲ�ȭ ����.
// void*�� ��� �����͸� ����ȯ���� ���� �� �ִ�.
// void*�� ���ü�� ���� �������̱� ������, ����� ������ ����ȯ�� �ݵ�� ����� �Ѵ�.
void swap(void *a, void *b, int width)
{
	char temp;
	int i;
	char *p = (char*)a;
	char *q = (char*)b;
	// ����Ʈ ������ swap�� ����, width��ŭ ������ ����.
	// 1����Ʈ�� width��ŭ ��ȯ
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

// �Ϲ�ȭ�� swap()�Լ� �����
// ��� Ÿ���� swap()�� �� �ִ� �Լ��� �������?
// void*�� �̿��ؼ� �Ϲ�ȭ ����.
// ������ ���̺귯���� memcpy�� �̿�����.
// ���� : for�������� ������.
// ���� ö�� : ������ ���̺귯���� Ȱ������.

void swap(void *a, void *b, int width)
{
	// temp�� �޸𸮸� heap�� �����.
	// memcpy����ؼ� a, b swap
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

// �Ϲ�ȭ�� swap()�Լ� �����
// ��� Ÿ���� swap()�� �� �ִ� �Լ��� �������?
// void*�� �̿��ؼ� �Ϲ�ȭ ����.
// ������ ���̺귯���� memcpy�� �̿�����.
// ���� : for�������� ������.
// ���� ö�� : ������ ���̺귯���� Ȱ������.

void swap(void *a, void *b, int width)
{
	// temp�� �޸𸮸� heap�� �����.
	// memcpy����ؼ� a, b swap
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
	// ��ǰ ���� ����
	bubble_sort(a, n);
	// �迭 ��� �Լ�
	for (i = 0; i < n; i++)
		printf("%5d", a[i]);
	printf("\n");
}
#endif

#if 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �Ϲ�ȭ�� sort()�Լ� �����
// 

void swap(void *a, void *b, int width)
{
	// temp�� �޸𸮸� heap�� �����.
	// memcpy����ؼ� a, b swap
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
			//if (a[j - 1] > a[j])		// ÷�ڿ��� a[j] =>*(a+j) => (int*)
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
	// ��ǰ ���� ����
	//bubble_sort(a, n, sizeof(a[0]), cmp_int);
	qsort(a, n, sizeof(a[0]), cmp_int);

	// �迭 ��� �Լ�
	for (i = 0; i < n; i++)
		printf("%5d", a[i]);
	printf("\n");
}
#endif
