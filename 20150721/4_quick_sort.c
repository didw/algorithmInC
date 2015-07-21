// 4_quick_sort.c
// 퀵정렬
// 다른 원소와의 비교만으로 정렬을 수행하는 비교 정렬 방법	
// C표준 라이브러리. 

// 개요
// 1. 리스트 가운데 하나의 원소를 골라 축(pivot)으로 한다.
// 2. 축을 기준으로 왼쪽에는 작은 원소들이 모이게 하고, 오른쪽에는 축보다 큰 원소들이 
//    오도록 한다.
// 3. 리스트의 크기가 0 또는 1이 될때까지 재귀적으로 이 과정을 반복한다.

// 알고리즘
// 재귀 - 종료조건 : n <= 1
// 1. pivot 정하기 : a[n-1]
// 2. i는 증가하면서 축보다 큰 값을 찾는다.
// 3. j는 감소하면서 축보다 작은 값을 찾는다.
// 4. i보다 j크거나 같으면
//    4-1) 거짓이면, swap(a[i], a[j])
//    4-2) 참이면, 5로 이동
// 5. swap(a[i], a[n-1]) - pivot값과 i값을 교환
// 6. quick_sort(a, i), quick_sort(a+i+1, n-i-1)

// Stack Overflow시 스택의 사이즈를 늘려주려면
// MSVC
// 기본 스택 예약 사이즈가 1MB
// 프로젝트 속성-> 링커 -> 시스템 -> 스택 예약 사이즈 조정 1024*102*100 = 100MB
// Linux : ulimit -a : 스택 예약 사이즈 확인
// ulimit -s 1024*1024*100 



#if 0
#include "algorithm.h"
void quick_sort(int *a, int n)
{
	int i, j, pivot;

	if (n <= 1)
		return;

	pivot = a[n - 1];
	i = -1;
	j = n - 1;

	while (1)
	{
		while (a[++i] < pivot)	// i는 pivot보다 큰값을 만날때까지 반복
			;
		while (a[--j] > pivot)	// j는 pivot보다 작은값을 만날때까지 반복
			;

		if (i >= j)
			break;
		swap(&a[i], &a[j]);	// a[i]와 a[j] 교환
	}
	// a[i]와 a[n-1] 교환
	swap(&a[i], &a[n - 1]);

	quick_sort(a, i);
	quick_sort(a + i + 1, n - i - 1);
}

/*
int main()
{
	int a[] = { 9, 1, 6, 8, 4, 3, 2, 0 };
	int n = sizeof(a) / sizeof(a[0]);
	// 퀵 정렬 실행
	quick_sort(a, n);
	// 배열 출력 함수
	print_array(a, n);
}
*/

int main()
{
	prepare_sample_datas();
	start_timer();
	quick_sort(reverse_data_100000, 100000);
	end_timer();
}
#endif


#if 0
// 퀵정렬의 개선 1
// 난수 분할법
// 축값을 랜덤으로 선택하는 것
// 임의의 값을 선택 했을 때가 마지막 값을 선택했을 때보다 좋은 성능을 낼 수 있다.
// 이유 : 입력값이 랜덤했을 경우 가장 좋은 속도를 냈기 때문에
// 1. 0~n-1의 사이값의 난수를 발생시켜 축으로 사용
//    발생한 수를 오른쪽 값과 교환
// 2. 입력값에 상관없이 좋은 성능을 낼 수 있는 함수를 만들 수 있다.
// 3. 난수를 축값으로 사용했기 때문에 시간 복잡도를 구하기 어렵지만
//    평균적으로 O(nlogn)의 성능을 갖는다.

#include "algorithm.h"
void quick_sort(int *a, int n)
{
	int i, j, pivot;
	int t;

	if (n <= 1)
		return;

	t = rand() % n;
	swap(&a[t], &a[n - 1]);

	pivot = a[n - 1];
	i = -1;
	j = n - 1;

	while (1)
	{
		while (a[++i] < pivot)	// i는 pivot보다 큰값을 만날때까지 반복
			;
		while (a[--j] > pivot)	// j는 pivot보다 작은값을 만날때까지 반복
			;

		if (i >= j)
			break;
		swap(&a[i], &a[j]);	// a[i]와 a[j] 교환
	}
	// a[i]와 a[n-1] 교환
	swap(&a[i], &a[n - 1]);

	quick_sort(a, i);
	quick_sort(a + i + 1, n - i - 1);
}

/*
int main()
{
int a[] = { 9, 1, 6, 8, 4, 3, 2, 0 };
int n = sizeof(a) / sizeof(a[0]);
// 퀵 정렬 실행
quick_sort(a, n);
// 배열 출력 함수
print_array(a, n);
}
*/

int main()
{
	srand(time(0));
	prepare_sample_datas();
	start_timer();
	quick_sort(sorted_data_100000, 100000);
	end_timer();
}
#endif

#if 0
// 퀵정렬의 개선 2
// 퀵정렬로 리스트가 어느 정도 작아졌을 경우에
// 데이터 크기가 작고, 어느 정도 정렬이 된 입력데이터에서 굉장히 빠른 성능을 갖는
// 삽입 정렬로 정렬을 추가한다.
// n의 개수가 200이하일 경우 삽입정렬로 데이터를 정렬한다.
#include "algorithm.h"

// 루프를 돌면서 인덱스를 변경하는 것보다
// memcpy를 사용하면 25~30% 성능이 빠르다.
// memcpy를 사용할 때에는 데이터를 앞으로 당겨야 되기때문에 역순으로 실행한다.
void insertion_sort(int *data, int n)
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

void quick_sort(int *a, int n)
{
	int i, j, pivot;
	int t;

	if (n <= 1)
		return;

	if (n <= 200)
	{
		insertion_sort(a, n);
		return;
	}

	t = rand() % n;
	swap(&a[t], &a[n - 1]);

	pivot = a[n - 1];
	i = -1;
	j = n - 1;

	while (1)
	{
		while (a[++i] < pivot)	// i는 pivot보다 큰값을 만날때까지 반복
			;
		while (a[--j] > pivot)	// j는 pivot보다 작은값을 만날때까지 반복
			;

		if (i >= j)
			break;
		swap(&a[i], &a[j]);	// a[i]와 a[j] 교환
	}
	// a[i]와 a[n-1] 교환
	swap(&a[i], &a[n - 1]);

	quick_sort(a, i);
	quick_sort(a + i + 1, n - i - 1);
}

/*
int main()
{
int a[] = { 9, 1, 6, 8, 4, 3, 2, 0 };
int n = sizeof(a) / sizeof(a[0]);
// 퀵 정렬 실행
quick_sort(a, n);
// 배열 출력 함수
print_array(a, n);
}
*/

int main()
{
	srand(time(0));
	prepare_sample_datas();
	start_timer();
	quick_sort(reverse_data_100000, 100000);
	end_timer();
}
#endif

#if 1
// 퀵정렬의 개선 3
// 세 값의 중위(Three of Median)
// 세값 : 가장 왼쪽 값 a[l], 가장 오른쪽 : a[r], 가장 중간값 : a[(r+1)/2]
// 1) 이 세값을 정렬하여, 가장 작은 값이 왼쪽, 가장 큰 값이 오른쪽, 중간값은 중간에 오도록 한다.
// 2) 중간값 a[(r+1)/2]와 a[r-1]의 값을 교환
// 3) 기준의 값을 a[r-1]값으로 분할을 시작한다.
// 4) 가장 왼쪽의 값은 축보다 작고, 가장 오른쪽에 있는 것은 축보다 크다.
//  -> 가장 왼쪽의 값과 가장 오른쪽 값은 분할시 제외할 수 있다.
// 범위를 줄이는 것은 재귀함수의 호출 횟수를 줄일 수 있기 때문에, 성능이 빨라진다.

#include "algorithm.h"

// 루프를 돌면서 인덱스를 변경하는 것보다
// memcpy를 사용하면 25~30% 성능이 빠르다.
// memcpy를 사용할 때에는 데이터를 앞으로 당겨야 되기때문에 역순으로 실행한다.
void insertion_sort(int *data, int n)
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

void quick_sort(int *a, int n)
{
	int i, j, pivot;
	int t, center;

	if (n <= 1)
		return;

	if (n <= 200)
	{
		insertion_sort(a, n);
		return;
	}

	// 세값 : 가장 왼쪽 값 a[l], 가장 오른쪽 : a[r], 가장 중간값 : a[(r+1)/2]
	// 1) 이 세값을 정렬하여, 가장 작은 값이 왼쪽, 가장 큰 값이 오른쪽, 중간값은 중간에 오도록 한다.
	// 2) 중간값 a[(r+1)/2]와 a[r-1]의 값을 교환
	// 3) 기준의 값을 a[r-1]값으로 분할을 시작한다.
	center = n >> 1;
	if (a[0] > a[center])
		swap(&a[0], &a[center]);
	if (a[0] > a[n - 1])
		swap(&a[0], &a[n - 1]);
	if (a[center] > a[n - 1])
		swap(&a[center], &a[n - 1]);

	swap(&a[center], &a[n - 2]);

	pivot = a[n - 2];
	i = 0;
	j = n - 2;

	while (1)
	{
		while (a[++i] < pivot)	// i는 pivot보다 큰값을 만날때까지 반복
			;
		while (a[--j] > pivot)	// j는 pivot보다 작은값을 만날때까지 반복
			;

		if (i >= j)
			break;
		swap(&a[i], &a[j]);	// a[i]와 a[j] 교환
	}
	// a[i]와 a[n-1] 교환
	swap(&a[i], &a[n - 1]);

	quick_sort(a, i);
	quick_sort(a + i + 1, n - i - 1);
}

/*
int main()
{
int a[] = { 9, 1, 6, 8, 4, 3, 2, 0 };
int n = sizeof(a) / sizeof(a[0]);
// 퀵 정렬 실행
quick_sort(a, n);
// 배열 출력 함수
print_array(a, n);
}
*/

int main()
{
	srand(time(0));
	prepare_sample_datas();
	start_timer();
	quick_sort(reverse_data_100000, 100000);
	end_timer();
}
#endif

// glibc의 qsort
// 1) Non-recursive
// 2) pivot - Three of Median
// 3) insertion_sort

// 선택, 삽입, 버블, 퀵정렬에 대한 정리
// 선택정렬 O(N^2) : 비교가 많고 교환의 횟수가 적다.
//           비교적 큰 데이터일 경우에 유용하다.
//           안정성이 없다.
// 삽입정렬 O(N^2): 비교가 적고, 교환의 횟수가 많다.
//        비교적 작은 데이터 또 어느 정도 정렬된 데이터일 경우 유용하다.
//        안정하다.
//        비교 후에도 같은 키값을 갖는 원소의 순서가 변하지 않는다.
// 버블정렬 O(N^2): 비교도 많고, 교환도 많아서 실제 정렬할 때 사용하지는 않다.
//        안정하다.
// 퀵정렬 O(NlogN): 비교 알고리즘
//        pivot값에 따라 정렬 속도가 다르므로, pivot의 기준을 중간 값으로 맞추는 것이
//        중요하다.
//        가장 빠른 알고리즘, C의 표준 정렬 라이브러리

