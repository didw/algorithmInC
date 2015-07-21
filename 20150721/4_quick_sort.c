// 4_quick_sort.c
// ������
// �ٸ� ���ҿ��� �񱳸����� ������ �����ϴ� �� ���� ���	
// Cǥ�� ���̺귯��. 

// ����
// 1. ����Ʈ ��� �ϳ��� ���Ҹ� ��� ��(pivot)���� �Ѵ�.
// 2. ���� �������� ���ʿ��� ���� ���ҵ��� ���̰� �ϰ�, �����ʿ��� �ຸ�� ū ���ҵ��� 
//    ������ �Ѵ�.
// 3. ����Ʈ�� ũ�Ⱑ 0 �Ǵ� 1�� �ɶ����� ��������� �� ������ �ݺ��Ѵ�.

// �˰���
// ��� - �������� : n <= 1
// 1. pivot ���ϱ� : a[n-1]
// 2. i�� �����ϸ鼭 �ຸ�� ū ���� ã�´�.
// 3. j�� �����ϸ鼭 �ຸ�� ���� ���� ã�´�.
// 4. i���� jũ�ų� ������
//    4-1) �����̸�, swap(a[i], a[j])
//    4-2) ���̸�, 5�� �̵�
// 5. swap(a[i], a[n-1]) - pivot���� i���� ��ȯ
// 6. quick_sort(a, i), quick_sort(a+i+1, n-i-1)

// Stack Overflow�� ������ ����� �÷��ַ���
// MSVC
// �⺻ ���� ���� ����� 1MB
// ������Ʈ �Ӽ�-> ��Ŀ -> �ý��� -> ���� ���� ������ ���� 1024*102*100 = 100MB
// Linux : ulimit -a : ���� ���� ������ Ȯ��
// ulimit -s 1024*1024*100 



#if 0
#include "algorithm.h"
void quick_sort(int *a, int n)
{
	int i, j, pivot;

	if (n <= 1)
		return;

	pivot = a[n - 1];
	i = -1;
	j = n - 1;

	while (1)
	{
		while (a[++i] < pivot)	// i�� pivot���� ū���� ���������� �ݺ�
			;
		while (a[--j] > pivot)	// j�� pivot���� �������� ���������� �ݺ�
			;

		if (i >= j)
			break;
		swap(&a[i], &a[j]);	// a[i]�� a[j] ��ȯ
	}
	// a[i]�� a[n-1] ��ȯ
	swap(&a[i], &a[n - 1]);

	quick_sort(a, i);
	quick_sort(a + i + 1, n - i - 1);
}

/*
int main()
{
	int a[] = { 9, 1, 6, 8, 4, 3, 2, 0 };
	int n = sizeof(a) / sizeof(a[0]);
	// �� ���� ����
	quick_sort(a, n);
	// �迭 ��� �Լ�
	print_array(a, n);
}
*/

int main()
{
	prepare_sample_datas();
	start_timer();
	quick_sort(reverse_data_100000, 100000);
	end_timer();
}
#endif



#if 1
// �������� ���� 1
// ���� ���ҹ�
// �ప�� �������� �����ϴ� ��
// ������ ���� ���� ���� ���� ������ ���� �������� ������ ���� ������ �� �� �ִ�.
// ���� : �Է°��� �������� ��� ���� ���� �ӵ��� �±� ������
// 1. 0~n-1�� ���̰��� ������ �߻����� ������ ���
//    �߻��� ���� ������ ���� ��ȯ
// 2. �Է°��� ������� ���� ������ �� �� �ִ� �Լ��� ���� �� �ִ�.
// 3. ������ �ప���� ����߱� ������ �ð� ���⵵�� ���ϱ� �������
//    ��������� O(nlogn)�� ������ ���´�.

#include "algorithm.h"
void quick_sort(int *a, int n)
{
	int i, j, pivot;
	int t;

	if (n <= 1)
		return;

	t = rand() % n;
	swap(&a[t], &a[n - 1]);

	pivot = a[n - 1];
	i = -1;
	j = n - 1;

	while (1)
	{
		while (a[++i] < pivot)	// i�� pivot���� ū���� ���������� �ݺ�
			;
		while (a[--j] > pivot)	// j�� pivot���� �������� ���������� �ݺ�
			;

		if (i >= j)
			break;
		swap(&a[i], &a[j]);	// a[i]�� a[j] ��ȯ
	}
	// a[i]�� a[n-1] ��ȯ
	swap(&a[i], &a[n - 1]);

	quick_sort(a, i);
	quick_sort(a + i + 1, n - i - 1);
}

/*
int main()
{
int a[] = { 9, 1, 6, 8, 4, 3, 2, 0 };
int n = sizeof(a) / sizeof(a[0]);
// �� ���� ����
quick_sort(a, n);
// �迭 ��� �Լ�
print_array(a, n);
}
*/

int main()
{
	srand(time(0));
	prepare_sample_datas();
	start_timer();
	quick_sort(sorted_data_100000, 100000);
	end_timer();
}
#endif