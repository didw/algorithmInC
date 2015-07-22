// 2_merge_sort.c
// ���� ����
// �˰���
// 1. ������ �������� ������ ������ ������.
// 2. ���� ������ ������ ũ�Ⱑ 1�̵ɶ����� 1���� �ݺ��Ѵ�.
// 3. ���� ������ ���� ���� �����Ͽ� �ϳ��� ������ �������� �����. ( ������ ���� ���� )
// 4. ������ ������ �ϳ��� �� ������ 3���� �ݺ��Ѵ�.
// ���� ������ �ð� ���⵵�� O(nlogn)
// merge() => n�� ȣ��, merge_sort() => logn��ŭ ȣ��
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int *a, int low, int high, int mid)
{
	int left = low;			// ���� ������ ���� �ε���
	int right = mid + 1;	// ������ ������ ���� �ε���
	int i = 0;
	// ������ ���� ������ �ӽ� �迭 ����
	int *temp = (int*)malloc(sizeof(int)*((high - low) + 1));

	// left->mid && right->high ����
	// temp[i++] = min(a[left++], a[right++]);
	while (left <= mid && right <= high)
	{
		temp[i++] = a[left] < a[right] ? a[left++] : a[right++];
	}
	// left->mid ����
	// temp[i++] = a[left++]
	while (left <= mid)
		temp[i++] = a[left++];

	// right->high ����
	// temp[i++] = a[right++]
	while (right <= high)
		temp[i++] = a[right++];

	// ���ĵ� �ӽ� �迭�� �����͸� ���� �迭�� ����
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

	// ���� ����
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