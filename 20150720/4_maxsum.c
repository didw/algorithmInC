// 4_maxsum.c
// 수열에서 최대 부분 구간 합을 찾는 문제
// a[] = {1, 4, -9, 2, 8, -1, 9, 3}
// 1. 완전 탐색법 ( brute-force )
#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))

// 시간 복잡도 : O(N^2)
int maxSum(int *a, int n)
{
	// 2중 for문으로 구현하면 됩니다.
	int sum = 0;		// 부분합
	int ret = -9999;		// 부분합의 최대값
	int i, j;

	for (i = 0; i < n; i++)
	{
		// sum값은 내부 루프 수행시 초기화 
		sum = 0;
		for (j = i; j < n; j++)
		{
			sum += a[j];
			ret = max(ret, sum);
		}
	}
	return ret;
}

// 시간 복잡도
// n * 재귀호출이 호출되는 횟수
// O(nlogn)
int _fastMaxSum(int *a, int lo, int hi)
{
	int left = -9999;	// 좌측 배열의 최대부분값
	int right = -9999;	// 우측 배열의 최대부분값
	int sum = 0;
	int mid, single = 0;
	int i, j;

	// 탈출조건
	if (lo == hi) return a[lo];

	// 배열을 2조각으로 나눈다.
	mid = (lo + hi) / 2;

	// 왼쪽구간의 최대값
	for (i = mid; i >= lo; i--)
	{
		sum += a[i];
		left = max(left, sum);
	}

	sum = 0;
	// 오른쪽구간의 최대값
	for (j = mid+1; j <= hi; j++)
	{
		sum += a[j];
		right = max(right, sum);
	}

	// 왼쪽 구간의 최대값과 오른쪽 구간의 최대값을 비교해서 큰 값을 취한다.
	single = max(_fastMaxSum(a, lo, mid), _fastMaxSum(a, mid + 1, hi));

	// 리턴해 주는 값은
	// single 값과 전체 합산 값 중 큰것을 취한다.
	return max(left + right, single);
}

int fastMaxSum(int *a, int n)
{
	_fastMaxSum(a, 0, n - 1);
}

// maxAt(i) = max(0, maxAt(i-1)) + A[i]
// 시간복잡도 : O(n)
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
	int n = sizeof(a) / sizeof(a[0]);	// 배열 원소의 갯수
	printf("maxSum : %d\n", maxSum(a, n));
	printf("fastMaxSum : %d\n", fastMaxSum(a, n));
	printf("fastestMaxSum : %d\n", fastestMaxSum(a, n));
	return 0;
}
