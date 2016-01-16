//2_insertion_sort.c
// ��������
// �̹� ���ĵ� �κп� ���ο� Ű�� ������ ��ҿ� �����ϴ� ������ �ݺ������� �ϴ� ���� ���
// ����
// 1. �׷쿡 ù��° ���ڸ� �߰��Ѵ�.
// 2. �׷쿡 �ι�° ���ڸ� �߰��Ͽ� ù��° ���ڿ� ���ؼ�, 
//    ���� 2������ < 1�����ڸ� �ڸ��� �ٲ۴�.
// 3. �׷쿡 ����° ���ڸ� �߰��Ͽ� �ι��� ���ڿ� ��, 3������ < 2�� ���ڸ� �ڸ��� �ٲ۴�.
// 4. �ڱ⺸�� �� ���� ���ڰ� ������ ������ ���Ѵ�.
// �˰���
// 1. i = 1;
// 2. j = i;
// 3. a[j-1] > a[i] �̰� j > 0 ����
//		a[j] = a[j-1];
//      j--;
// 4. a[j] = a[i]

#include "algorithm.h"
// ���� ������ �ð� ���⵵�� O(N^2)
// ���ĵ� ������ �Է� �����Ͱ� ��� ���� �����ð��� �ð� ���⵵�� ���´�. �ֻ��� O(N)
// ������ �Է� �����Ͱ� ����ִٸ� ���� ������ ���� ���ĺ��� ������.
// ���� �������̸鼭 ��� ���� ������ �Ǿ� �ִ� �������� ��� ������ ���� ������ ����.

void insertion_sort(int *a, int n)
{
	int i, j, remember;
	for (i = 1; i < n; i++)
	{
		remember = a[i];
		j = i;
		// j-1�� ���� remember���� j-1���� remember������ ���� ������ ���� ����
		while (--j >= 0 && remember < a[j])
		{
			a[j + 1] = a[j];	// a[j] = a[j-1];
		}
		a[j + 1] = remember;
	}
}

// ������ ���鼭 �ε����� �����ϴ� �ͺ���
// memcpy�� ����ϸ� 25~30% ������ ������.
// memcpy�� ����� ������ �����͸� ������ ��ܾ� �Ǳ⶧���� �������� �����Ѵ�.
void insertion_sort2(int *data, int n)
{
	int i, j, remember;
	i = n - 1;
	while (i-- > 0)
	{
		remember = data[(j = i)];
		while (++j < n && remember > data[j]);

		if (--j == i) continue;
		memcpy(data + i, data + i + 1, sizeof(*data) * (j - i));
		data[j] = remember;
	}
}

#if 0
int main()
{
	int a[] = { 9, 1, 6, 8, 4, 3, 2, 0 };
	int n = sizeof(a) / sizeof(a[0]);
	// ���� ���� ����
	insertion_sort(a, n);
	// �迭 ��� �Լ�
	print_array(a, n);
}
#endif

#if 1
int main()
{
	prepare_sample_datas();
	start_timer();
	insertion_sort2(reverse_data_100000, 100000);
	end_timer();
}
#endif