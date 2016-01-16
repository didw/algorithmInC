// 5_0-1knapsack.c

/*
Cij =  if(j < w[i])
		C[i][j] = C[i - 1][j];
	   else
		C[i][j] = max(C[i - 1][j], C[i - 1][j - w[i]] + v[i])
*/
#define max(a, b) ((a) > (b) ? (a) : (b))

int weight[100];
int value[100];
int cache[100][100];
// W 무게를 들 수 있을 때 N개의 아이템중에서 취할 수 있는 최대 가치
void knapsack(int N, int W)
{
	int i, j;
	for (i = 0; i <= W; i++)
		cache[0][i] = 0;
	for (j = 0; j <= N; j++)
		cache[j][0] = 0;

	for (i = 1; i <= N; i++)
		for (j = 1; j <= W; j++)
			// j무게를 들 수 있을 때 i개 아이템중에 취할 수 있는 최대 가치
			// j무게로 i번째 아이템을 들 수 없는 경우의 최대 가치 값은 
			// j무게로 1 ~ i-1번째 아이템을 들었던 경우의 최대치와 같다.
			if (j < weight[i - 1])
				cache[i][j] = cache[i - 1][j];
			// j무게로 i번째 아이템을 들 수 있는 경우의 최대 가치 값은
			// i번째 아이템을 드는 경우와 들지 않는 경우로 나눠
			// 둘 중에 최대치를 취한다.
			else
				cache[i][j] = max(cache[i - 1][j],
				                  cache[i - 1][j - weight[i - 1]] + value[i - 1]);
	// W무게로 N개의 아이템중에 취할 수 있는 최대 가치
	printf("최대가치 : %d\n", cache[N][W]);
}

// 실재로 어떤 아이템을 들었는지를 알기 위해서는 cache의 값을 재참조해야 한다.
void traceback(int i, int j)
{
	// 탈출 조건
	if (i == 0 || j == 0 || cache[i][j] == 0)
		return;
	// 대각선으로 값이 커졌다는 뜻은 j무게를 가지고
	// i번째 아이템을 선택해서 넣었을 때 i-1번째 아이템을 선택했을 경우보다 가치가 커졌다는 의미이므로
	// i번째 아이템을 출력하고 대각선으로 이동한다. (i, j) -> (i-1, j-1)
	if (cache[i][j] > cache[i][j - 1] && cache[i][j] > cache[i - 1][j]
		&& cache[i][j] > cache[i - 1][j - 1]) {
		printf("item %d\n", i);
		traceback(i - 1, j - 1);
	}
	// j-1 무게로 i번째 아이템을 선택했을 경우가 j무게로 i번째 아이템을 선택했을 때와 같다.
	else if (cache[i][j] == cache[i][j - 1] && cache[i][j] > cache[i - 1][j])
		traceback(i, j - 1);
	// i가 i-1과 같다. 이전 아이템을 선택했을 때와 다르지 않음. 즉, 현재 아이템을 선택하지 않음.
	else
		traceback(i - 1, j);
}

int main()
{
	int N, W, i;
	scanf("%d %d", &N, &W);
	for (i = 0; i < N; i++)
		scanf("%d %d", &weight[i], &value[i]);
	knapsack(N, W); 
	traceback(N, W);
}