// 4_maxsum.c
// �������� �ִ� �κ� ���� ���� ã�� ����
// a[] = {1, 4, -9, 2, 8, -1, 9, 3}
// 1. ���� Ž���� ( brute-force )
#include <stdio.h>
#include <time.h>
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

// �˰����� ����ð� �����ϱ�
// 1. �迭�� ���̸� 10000���� ����
// 2. init() �迭�� ���� rand()�Լ��� �̿��ؼ� ������ ä���.
//    ��, �迭�� ���� 100�̸����� �Ѵ�.
// 3. �ʱ�ȭ�� �迭�� �ε����� 3�� ����̸� ������ ä���.

#define SIZE 100000
void init(int *a, int n)
{
	int sign = 1, i;
	srand(time(0));
	for (i = 0; i < n; i++)
	{
		sign = i % 3 ? 1 : -1;
		a[i] = (rand() % 100) * sign;
	}
}

int main()
{
	int a[SIZE];
	int n = sizeof(a) / sizeof(a[0]);	// �迭 ������ ����
	clock_t t1, t2, t3, t4;

	init(a, n);
	t1 = clock();
	printf("maxSum			: %d\n", maxSum(a, n));
	t2 = clock();
	printf("fastMaxSum		: %d\n", fastMaxSum(a, n));
	t3= clock();
	printf("fastestMaxSum	: %d\n", fastestMaxSum(a, n));	
	t4 = clock();
	// ����ð� ����
	printf("maxSum			: %lf\n", (double)(t2 - t1) / CLOCKS_PER_SEC);
	printf("fastMaxSum		: %lf\n", (double)(t3 - t2) / CLOCKS_PER_SEC);
	printf("fastestMaxSum	: %lf\n", (double)(t4 - t3) / CLOCKS_PER_SEC);
	return 0;
}
