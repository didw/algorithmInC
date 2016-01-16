// 1_분할정복.c
// 문제를 작은 문제로 나눠서 해결하는 알고리즘
// 재귀적 풀이법 : 문제를 한조각과 나머지 부분 분할
// 분할 정복법 : 문제를 균등한 부분으로 분할
// 예) 퀵정렬, 병합정렬, 이진탐색트리의 검색

// 분할 정복 알고리즘 ( Divide and Conquer )
// 1. 분할(divide) : 문제를 해결하기 쉽도록 작은 문제로 나눈다.
// 2. 정복(conquer) : 작은 문제를 각각 해결한다.
// 3. 통합(combine) : 해결된 답을 모은다.

// 분할 정복은 top-down 방식으로 문제를 해결 한다.
// 분할 정복을 적용해서 문제를 해결하려면
// 문제를 둘 이상의 부분으로 나눌 수 있어야 한다. ( 최대한 균등하게..)

// 일반적인 재귀는 O(N) 성능을 갖지만, 분할 정복은 O(logN) 성능을 갖는다.

#include "algorithm.h"

// 문제. sum(n) = 1+2+...+n을 구한다.
// 1. 일반적 재귀함수로 푸는 방법
//    선형적 시간을 갖는 함수 O(n)
int sum(int n)
{
	if (n == 1)
		return 1;
	return sum(n - 1) + n;
}

// 문제. fastsum(n) = 1+2+...+n 
//                  = (1+2+...+n/2) + ((1+n/2)+(2+n/2)+...+(n/2+n/2)) (n이 2배수일 경우)
//					= 2*(1+2+...+n/2)+n/2*n/2
//                  = 2*fastsum(n/2)+n/2*n/2

// 2. 분할 정복법으로 푸는 방법
//    시간 복잡도가 O(logn)
int fastsum(int n)
{
	if (n == 1)
		return 1;
	// 홀수
	if (n % 2)
		return fastsum(n - 1) + n;
	// 짝수
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