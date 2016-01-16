// 3_meeting.c
// 탐욕법
// 여러 경우 중 하나를 결정해야 할 때마다 그 순간의 최적이라고 생각되는 것을
// 선택해 나가는 방식으로 최종적인 해를 구하는 방법
// 순간마다 하는 선택은 그 순간에 대해 "지역적 최적"이지만, 그 선택들을 계속
// 수집하여 최종적인 해답을 만들었다고 해서, 그것이 "전역적 최적"이라는 보장이 없다.

// 탐욕적 알고리즘은 최적해에 대한 검증을 해야한다.

// 탐욕 알고리즘이 잘 동작하는 문제
// 탐욕스러운 선택 속성 ( greedy choice property )
// 앞의 선택이 이후의 선택에 영향을 주지 않는 것
// 최적 부분 구조(optimal substructure)
// 문제에 대한 최적해가 부분문제에 대해서도 최적해라는 것

// 탐욕 알고리즘
// 1. 해 선택 ( selection procedure ) : 현재 상태에서 부분 문제에 대한 최적해를 구한 뒤,
// 이를 부분해의 집합에 추가한다.
// 2. 실행 가능성 검사 ( feasibility check) : 새로운 부분해 집합에 실행 가능한지 확인
// 문제의 제약 조건을 위반하지 않았는지 검사한다.
// 3. 해 검사(solution check) : 새로운 부분해 집합에 문제의 해가 되는지 확인한다.

// 동적 계획법보다 탐욕 알고리즘이 빠른 이유
// 탐욕 알고리즘은 정렬을 통해서 현재 상황의 최적을 찾아낸다.
// O(NlogN)의 성능을 갖는 정렬을 통해서 데이터를 정렬하고, 선형적 시간을 갖기 때문에
// 일반적으로 O(N^2)의 성능을 갖는 동적 계획법보다 빠르다.

// 회의실 예약 예제
typedef struct
{
	int fr;
	int to;
} ORDER;

int n;
ORDER arr[100];

int cmp(const void* a, const void* b)
{
	// 종료시간이 빠른 순으로 정렬되도록 비교 구문 작성
	return ((ORDER*)a)->to > ((ORDER*)b)->to;
}

int meeting()
{
	int i;
	int earliest = 0, count = 0;
	int meeting_start, meeting_end;
	// 1. 해의 선택
	// 최적해를 찾기 위해서는 기준을 선택한 후 값을 정렬한다.
	qsort(arr, n, sizeof(arr[0]), cmp);

	// 2. 선택한 해를 해의 집합에 추가한다.
	for (i = 0; i < n; i++)
	{
		// 선택한 해가 해의 집합에 추가할 수 있는지 제약 조건 체크
		meeting_start = arr[i].fr;
		meeting_end = arr[i].to;
		if (earliest <= meeting_start)
		{
			earliest = meeting_end;
			count++;
		}
	}
	return count;
}

int main()
{
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d %d", &arr[i].fr, &arr[i].to);
	}
	printf("%d\n", meeting());
}

