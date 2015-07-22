// 4_���װ��.c
// ���� nCr : n���� �� �߿� �������� r���� ���� ������ ���

// nCr = n-1Cr + n-1Cr-1
// nC0 = 1, nCn = 1
#include <stdio.h>

int cnt1 = 0, cnt2 = 0;
// 1. ��ȭ���� ����Լ��� ȣ���ؼ� ����� ������.
int bino(int n, int r)
{
	cnt1++;
	if (r == 0 || r == n)
		return 1;
	return bino(n - 1, r) + bino(n - 1, r - 1);
}

// 2. cache�� �̿��ؼ� ������ȹ������ ����� ������
int cache[100][100];
int bino2(int n, int r)
{
	cnt2++;
	// ���ʿ� �ѹ� ȣ�� �� ��� cache�� ����
	// �ι� �̻� ȣ��� cache�� ����
	if (r == 0 || r == n)
		return 1;
	if (cache[n][r] != 0)
		return cache[n][r];
	return cache[n][r] = bino2(n - 1, r) + bino2(n - 1, r - 1);
}

int main()
{
	printf("%d\n", bino(20, 8));
	printf("%d\n", bino2(20, 8));
	printf("bino : %d\n", cnt1);
	printf("bino2 : %d\n", cnt2);

}