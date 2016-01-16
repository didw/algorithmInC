//2_insertion_sort.c
// 삽입정렬
// 이미 정렬된 부분에 새로운 키를 적절한 장소에 삽입하는 동작을 반복적으로 하는 정렬 방법
// 개요
// 1. 그룹에 첫번째 숫자를 추가한다.
// 2. 그룹에 두번째 숫자를 추가하여 첫번째 숫자와 비교해서, 
//    만약 2번숫자 < 1번숫자면 자리를 바꾼다.
// 3. 그룹에 세번째 숫자를 추가하여 두번재 숫자와 비교, 3번숫자 < 2번 숫자면 자리를 바꾼다.
// 4. 자기보다 더 작은 숫자가 나오기 전까지 비교한다.
// 알고리즘
// 1. i = 1;
// 2. j = i;
// 3. a[j-1] > a[i] 이고 j > 0 동안
//		a[j] = a[j-1];
//      j--;
// 4. a[j] = a[i]

#include "algorithm.h"
// 삽입 정렬은 시간 복잡도가 O(N^2)
// 정렬된 형태의 입력 데이터가 들어 오면 선형시간의 시간 복잡도를 갖는다. 최상일 O(N)
// 임의의 입력 데이터가 들어있다면 삽입 정렬이 선택 정렬보다 빠르다.
// 작은 데이터이면서 어느 정도 정렬이 되어 있는 데이터일 경우 굉장히 빠른 성능을 낸다.

void insertion_sort(int *a, int n)
{
	int i, j, remember;
	for (i = 1; i < n; i++)
	{
		remember = a[i];
		j = i;
		// j-1의 값과 remember값을 j-1값이 remember값보다 작을 때까지 루프 실행
		while (--j >= 0 && remember < a[j])
		{
			a[j + 1] = a[j];	// a[j] = a[j-1];
		}
		a[j + 1] = remember;
	}
}

// 루프를 돌면서 인덱스를 변경하는 것보다
// memcpy를 사용하면 25~30% 성능이 빠르다.
// memcpy를 사용할 때에는 데이터를 앞으로 당겨야 되기때문에 역순으로 실행한다.
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
	// 삽입 정렬 실행
	insertion_sort(a, n);
	// 배열 출력 함수
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