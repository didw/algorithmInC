// 5_search.c
// Ž��(Search) �˰���
// Ž���� Ư���� ������ �����Ǿ� �ִ� �ڷῡ�� �־��� Ű�� ���� �����͸� ã�Ƴ��� ���� ���Ѵ�.
// ���İ� �Բ� ���� ���� ������ �˰����̴�.

// ���� Ž��(Linear Search) - ���� �˻� ( Sequential Search)
// �־��� �����͸� ã���� �Ҷ�, ���������� �˻��ϴ� ���� �ܼ��� ������ �˻� �˰���
// ó������ �����͸� ���ϸ鼭 Ű�� �ش��ϴ� �����͸� ã���� �����Ѵ�.

// ������ N�� ���ؼ� N/2�� �񱳸� �����ϹǷ� ȿ���� ���� �˻� ����� �ƴϴ�.
#if 0
#include <stdio.h>

int linear_search(int *a, int n, int key)
{
	int i = 0;
	while (a[i] != key && i < n)
		i++;
	return (i < n) ? i : -1;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int ret = linear_search(a, 5, 5);

	if (ret != -1)
		printf("found index : %d\n", ret);
	else
		printf("failed.");
}
#endif

#if 1
#include <stdio.h>
// ���� Ž���� �����ϴ� ���
// �󵵼��� ���� �˻����� ����Ʈ�� �տ� ��ġ�ؼ� Ž�� �ð��� ���δ�.
// ������ �˻� �˰���, ���� ����Ʈ�� �ǽð� �˻� ���� ���� ���� ���� �� ���
// �˻� �󵵰� ���� �����͸� ���ο� �ű�� ����� ���� ����Ѵ�.
// �ڱ� ����ȭ ( Self Organization)
// �� ���� ���ؼ� �ڱ� ������ ���� �������ϴ� ���� ���Ѵ�.
// �˻��� �� �ε����� ù��° �ε����� ����
int __linear_search(int *a, int n, int key)
{
	int i = 0;
	while (a[i] != key && i < n)
		i++;
	return (i < n) ? i : -1;
}

int linear_search(int *a, int n, int key)
{
	int i, result;
	result = __linear_search(a, n, key);
	if (result > 0)	// �˻� ����
	{
		// ���������� �ߴ� ��� ��� ������ȭ �ϸ� �ȴ�.
		for (i = result - 1; i >= 0; i--)
			a[i + 1] = a[i];		// 2->3, 3->4
		a[0] = key;
		return 0;
	}
	else {
		return -1;
	}
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int ret = linear_search(a, 5, 5);

	if (ret != -1)
		printf("found index : %d\n", ret);
	else
		printf("failed.");
}
#endif

int binary_search(int *a, int n, int key) {
	int lo = 0, hi = n - 1;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (a[mid] > key)
			hi = mid;
		else
			lo = mid;
	}
	return hi;
}