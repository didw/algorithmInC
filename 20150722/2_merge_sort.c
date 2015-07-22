// 2_merge_sort.c
// 병합 정렬
// 알고리즘
// 1. 정렬할 데이터의 집합을 반으로 나눈다.
// 2. 하위 데이터 집합의 크기가 1이될때까지 1번을 반복한다.
// 3. 하위 데이터 집합 둘을 병합하여 하나의 데이터 집합으로 만든다. ( 순서에 맞춰 정렬 )
// 4. 데이터 집합이 하나가 될 때까지 3번을 반복한다.
// 병합 정렬의 시간 복잡도는 O(nlogn)
// merge() => n번 호출, merge_sort() => logn만큼 호출
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *a, int low, int high, int mid)
{
	int left = low;			// 왼쪽 구간의 시작 인덱스
	int right = mid + 1;	// 오른쪽 구간의 시작 인덱스
	int i = 0;
	// 정렬한 값을 저장할 임시 배열 선언
	int *temp = (int*)malloc(sizeof(int)*((high - low) + 1));

	// left->mid && right->high 동안
	// temp[i++] = min(a[left++], a[right++]);
	while (left <= mid && right <= high)
	{
		temp[i++] = a[left] < a[right] ? a[left++] : a[right++];
	}
	// left->mid 동안
	// temp[i++] = a[left++]
	while (left <= mid)
		temp[i++] = a[left++];

	// right->high 동안
	// temp[i++] = a[right++]
	while (right <= high)
		temp[i++] = a[right++];

	// 정렬된 임시 배열에 데이터를 원본 배열에 저장
	memcpy(a + low, temp, (high - low + 1)*sizeof(int));
	free(temp);
}

void merge_sort(int *a, int low, int high)
{
	int mid;

	if (high - low < 1)
		return;

	mid = (low + high) / 2;
	merge_sort(a, low, mid);
	merge_sort(a, mid + 1, high);

	// 병합 수행
	merge(a, low, high, mid);
}

int main()
{
	int a[] = { 1, 3, 5, 7, 9, 8, 6, 4, 2 };
	int n = sizeof(a) / sizeof(a[0]);
	int i;
	merge_sort(a, 0, n-1);

	for (i = 0; i < n; i++)
		printf("%4d", a[i]);
	printf("\n");
}