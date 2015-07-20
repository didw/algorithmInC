// 4_maxsum.c
// �������� �ִ� �κ� ���� ���� ã�� ����
// a[] = {1, 4, -9, 2, 8, -1, 9, 3}
// 1. ���� Ž���� ( brute-force )
#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

// �ð� ���⵵ : O(N^2)
int maxSum(int *a, int n)
{
	// 2�� for������ �����ϸ� �˴ϴ�.
	int sum = 0;		// �κ���
	int ret = -9999;		// �κ����� �ִ밪
	int i, j;

	for (i = 0; i < n; i++)
	{
		// sum���� ���� ���� ����� �ʱ�ȭ 
		sum = 0;
		for (j = i; j < n; j++)
		{
			sum += a[j];
			ret = max(ret, sum);
		}
	}
	return ret;
}

// �ð� ���⵵
// n * ���ȣ���� ȣ��Ǵ� Ƚ��
// O(nlogn)
int _fastMaxSum(int *a, int lo, int hi)
{
	int left = -9999;	// ���� �迭�� �ִ�κа�
	int right = -9999;	// ���� �迭�� �ִ�κа�
	int sum = 0;
	int mid, single = 0;
	int i, j;

	// Ż������
	if (lo == hi) return a[lo];

	// �迭�� 2�������� ������.
	mid = (lo + hi) / 2;

	// ���ʱ����� �ִ밪
	for (i = mid; i >= lo; i--)
	{
		sum += a[i];
		left = max(left, sum);
	}

	sum = 0;
	// �����ʱ����� �ִ밪
	for (j = mid+1; j <= hi; j++)
	{
		sum += a[j];
		right = max(right, sum);
	}

	// ���� ������ �ִ밪�� ������ ������ �ִ밪�� ���ؼ� ū ���� ���Ѵ�.
	single = max(_fastMaxSum(a, lo, mid), _fastMaxSum(a, mid + 1, hi));

	// ������ �ִ� ����
	// single ���� ��ü �ջ� �� �� ū���� ���Ѵ�.
	return max(left + right, single);
}

int fastMaxSum(int *a, int n)
{
	_fastMaxSum(a, 0, n - 1);
}

// maxAt(i) = max(0, maxAt(i-1)) + A[i]
// �ð����⵵ : O(n)
int fastestMaxSum(int *a, int n)
{
	int sum = 0;
	int ret = -9999;
	int i;
	for (i = 0; i < n; i++)
	{
		sum = max(0, sum) + a[i];
		ret = max(ret, sum);
	}
	return ret;
}

int main()
{
	int a[] = { 1, 4, -9, 2, 8, -1, 9, 3 };
	int n = sizeof(a) / sizeof(a[0]);	// �迭 ������ ����
	printf("maxSum : %d\n", maxSum(a, n));
	printf("fastMaxSum : %d\n", fastMaxSum(a, n));
	printf("fastestMaxSum : %d\n", fastestMaxSum(a, n));
	return 0;
}
