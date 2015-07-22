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
void knapsack(int N, int W)
{
	int i, j;
	// i=0, j=0, cache[0][i] = 0, cache[j][0] = 0;
	for (i = 0; i <= W; i++)
		cache[0][i] = 0;
	for (j = 0; j <= N; j++)
		cache[j][0] = 0;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= W; j++)
		{
			if (j < weight[i - 1])
			{
				cache[i][j] = cache[i - 1][j];
			}
			else
			{
				cache[i][j] = max(cache[i - 1][j]
					, cache[i - 1][j - weight[i - 1]] + value[i - 1]);
			}

		}
	}
	printf("최대가치 : %d\n", cache[N][W]);
}

void traceback(int i, int j)
{
	// 탈출 조건
	if (i == 0 || j == 0 || cache[i][j] == 0)
		return;
	// 왼쪽, 위쪽, 대각선위쪽 보다 내가 클 경우 대각선 이동, 화면 출력
	if (cache[i][j] > cache[i][j - 1] && cache[i][j] > cache[i - 1][j]
		&& cache[i][j] > cache[i - 1][j - 1])
	{
		printf("item %d\n", i);
		traceback(i - 1, j - 1);
	}
	// 왼쪽과 같고, 위쪽보다 내가 클 경우 왼쪽으로 이동
	else if (cache[i][j] == cache[i][j - 1] && cache[i][j] > cache[i - 1][j])
	{
		traceback(i, j - 1);
	}
	// 위 두가지 경우가 아닌 경우 위쪽으로 이동
	else
		traceback(i - 1, j);
}

int main()
{
	int N, W;
	int i;
	scanf("%d %d", &N, &W);
	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &weight[i], &value[i]);
	}
	knapsack(N, W); 
	traceback(N, W);
}