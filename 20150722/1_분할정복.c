// 1_��������.c
// ������ ���� ������ ������ �ذ��ϴ� �˰���
// ����� Ǯ�̹� : ������ �������� ������ �κ� ����
// ���� ������ : ������ �յ��� �κ����� ����
// ��) ������, ��������, ����Ž��Ʈ���� �˻�

// ���� ���� �˰��� ( Divide and Conquer )
// 1. ����(divide) : ������ �ذ��ϱ� ������ ���� ������ ������.
// 2. ����(conquer) : ���� ������ ���� �ذ��Ѵ�.
// 3. ����(combine) : �ذ�� ���� ������.

// ���� ������ top-down ������� ������ �ذ� �Ѵ�.
// ���� ������ �����ؼ� ������ �ذ��Ϸ���
// ������ �� �̻��� �κ����� ���� �� �־�� �Ѵ�. ( �ִ��� �յ��ϰ�..)

// �Ϲ����� ��ʹ� O(N) ������ ������, ���� ������ O(logN) ������ ���´�.

#include "algorithm.h"

// ����. sum(n) = 1+2+...+n�� ���Ѵ�.
// 1. �Ϲ��� ����Լ��� Ǫ�� ���
//    ������ �ð��� ���� �Լ� O(n)
int sum(int n)
{
	if (n == 1)
		return 1;
	return sum(n - 1) + n;
}

// ����. fastsum(n) = 1+2+...+n 
//                  = (1+2+...+n/2) + ((1+n/2)+(2+n/2)+...+(n/2+n/2)) (n�� 2����� ���)
//					= 2*(1+2+...+n/2)+n/2*n/2
//                  = 2*fastsum(n/2)+n/2*n/2

// 2. ���� ���������� Ǫ�� ���
//    �ð� ���⵵�� O(logn)
int fastsum(int n)
{
	if (n == 1)
		return 1;
	// Ȧ��
	if (n % 2)
		return fastsum(n - 1) + n;
	// ¦��
	return 2 * fastsum(n / 2) + n / 2 * n / 2;
}

int* mergesort(int* a, int n) {
	int* res = (int*)malloc(sizeof(int)*n);
	int i = 0, j = 0, idx = 0;
	int* aa = mergesort(a, n / 2);
	int* bb = mergesort(a + n / 2, n - n / 2);
	int na = n / 2, nb = n - n / 2;
		
	while (i < na || j < nb) {
		if (aa[i] > bb[j])
			res[idx++] = bb[j++];
		else
			res[idx++] = aa[i++];
	}
	return res;
}

int main()
{
	//start_timer();
	//printf("%d\n", sum(100000));
	//end_timer();

	start_timer();
	printf("%d\n", fastsum(100000));
	end_timer();
}