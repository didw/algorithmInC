// 5_search.c
// 탐색(Search) 알고리즘
// 탐색은 특정한 구조로 구성되어 있는 자료에서 주어진 키에 대한 데이터를 찾아내는 것을 말한다.
// 정렬과 함께 가장 많이 연구된 알고리즘이다.

// 선형 탐색(Linear Search) - 순차 검색 ( Sequential Search)
// 주어진 데이터를 찾고자 할때, 순차적으로 검색하는 가장 단순한 형태의 검색 알고리즘
// 처음부터 데이터를 비교하면서 키에 해당하는 데이터를 찾으면 리턴한다.

// 데이터 N에 대해서 N/2번 비교를 수행하므로 효율이 높은 검색 방법은 아니다.
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
// 선형 탐색을 개선하는 방법
// 빈도수가 높은 검색값을 리스트에 앞에 배치해서 탐색 시간을 줄인다.
// 구글의 검색 알고리즘, 포털 사이트의 실시간 검색 순위 같은 것을 만들 때 사용
// 검색 빈도가 높은 데이터를 선두에 옮기는 방법을 많이 사용한다.
// 자기 조직화 ( Self Organization)
// 빈도 수에 의해서 자기 조직을 새로 재조직하는 것을 말한다.
// 검색이 된 인덱스를 첫번째 인덱스로 변경
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
	if (result > 0)	// 검색 성공
	{
		// 삽입정렬을 했던 방법 대로 재조직화 하면 된다.
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