// 4_fractional_knapsack.c
// 부분 배낭 문제
// 0-1 배낭 문제를 그리드 알고리즘으로 풀어보자.
// N = 3, W = 30
// item1 5  50		10
// item2 10 60		6
// item3 20 140		7

// 1. item이 가벼운 순으로 배낭에 집어 넣으면
// 2. item을 v/w 무게당 가치의 순으로 배낭에 집어 넣으면

// 부분 배낭 문제는 그리드 알고리즘을 이용해서 최적해를 구할 수 있다.
// 

typedef struct
{
	int id;
	int weight;
	int value;
	double vw;
} ITEM;

int N, W;
ITEM arr[100];

// 탐욕 알고리즘
// 1. 무게당 가치가 가장 큰 순서대로 정렬한다.
// 2. 첫번째 부터 순서대로 꺼내서 해에 포함시킨다.
// 3. 포함시킬 때 배낭의 남은 무게를 넘지 않게 해야 한다.
//    3.1) 배낭의 남은 무게에 물건이 전체가 들어가면 기존값에 value값 추가
//    3.2) 배낭의 남은 무게에 물건이 전체가 들어가지 않으면
//         물건을 쪼개서 넣으면 된다.
//         남은 무게*무게당가치 값 추가
//    물건을 배낭에 넣었다면 배낭의 무게 = 이전 무게 - 물건의 무게
// 4. 배낭의 남은 무게가 0이 될때까지 반복한다.

int cmp(const void* a, const void* b)
{
	ITEM *aa = (ITEM*)a;
	ITEM *bb = (ITEM*)b;
	return aa->value / aa->weight < bb->value / bb->weight ? 1 : -1;
}

double knapsack()
{
	qsort(arr, N, sizeof(arr[0]), cmp);
	double res = 0;
	int i = 0;
	while (W > 0 && i < N) {
		if (W >= arr[i].weight) {
			res += arr[i].value;
			W -= arr[i].weight;
		}
		else {
			res += arr[i].value / (double)(arr[i].weight - W);
			W = 0;
		}
		i++;
	}
	return res;
}

int main()
{
	int i;
	scanf("%d %d\n", &N, &W);
	for (i = 0; i < N; i++)
	{
		scanf("%d %d\n", &arr[i].weight, &arr[i].value);
		arr[i].id = i + 1;
		arr[i].vw = (double)arr[i].value / arr[i].weight; 
	}

	printf("%lf\n", knapsack());
}