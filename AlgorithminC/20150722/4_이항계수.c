// 4_이항계수.c
// 조합 nCr : n개의 수 중에 순서없이 r개의 수를 꺼내는 방법

// nCr = n-1Cr + n-1Cr-1
// nC0 = 1, nCn = 1
#include <stdio.h>

int cnt1 = 0, cnt2 = 0;
// 1. 점화식을 재귀함수를 호출해서 만들어 보세요.
int bino(int n, int r)
{
	cnt1++;
	if (r == 0 || r == n)
		return 1;
	return bino(n - 1, r) + bino(n - 1, r - 1);
}

// 2. cache를 이용해서 동적계획법으로 만들어 보세요
int cache[100][100];
int bino2(int n, int r)
{
	cnt2++;
	// 최초에 한번 호출 될 경우 cache값 셋팅
	// 두번 이상 호출시 cache값 리턴
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