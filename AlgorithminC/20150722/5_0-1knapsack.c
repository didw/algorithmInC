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
// W ���Ը� �� �� ���� �� N���� �������߿��� ���� �� �ִ� �ִ� ��ġ
void knapsack(int N, int W)
{
	int i, j;
	for (i = 0; i <= W; i++)
		cache[0][i] = 0;
	for (j = 0; j <= N; j++)
		cache[j][0] = 0;

	for (i = 1; i <= N; i++)
		for (j = 1; j <= W; j++)
			// j���Ը� �� �� ���� �� i�� �������߿� ���� �� �ִ� �ִ� ��ġ
			// j���Է� i��° �������� �� �� ���� ����� �ִ� ��ġ ���� 
			// j���Է� 1 ~ i-1��° �������� ����� ����� �ִ�ġ�� ����.
			if (j < weight[i - 1])
				cache[i][j] = cache[i - 1][j];
			// j���Է� i��° �������� �� �� �ִ� ����� �ִ� ��ġ ����
			// i��° �������� ��� ���� ���� �ʴ� ���� ����
			// �� �߿� �ִ�ġ�� ���Ѵ�.
			else
				cache[i][j] = max(cache[i - 1][j],
				                  cache[i - 1][j - weight[i - 1]] + value[i - 1]);
	// W���Է� N���� �������߿� ���� �� �ִ� �ִ� ��ġ
	printf("�ִ밡ġ : %d\n", cache[N][W]);
}

// ����� � �������� ��������� �˱� ���ؼ��� cache�� ���� �������ؾ� �Ѵ�.
void traceback(int i, int j)
{
	// Ż�� ����
	if (i == 0 || j == 0 || cache[i][j] == 0)
		return;
	// �밢������ ���� Ŀ���ٴ� ���� j���Ը� ������
	// i��° �������� �����ؼ� �־��� �� i-1��° �������� �������� ��캸�� ��ġ�� Ŀ���ٴ� �ǹ��̹Ƿ�
	// i��° �������� ����ϰ� �밢������ �̵��Ѵ�. (i, j) -> (i-1, j-1)
	if (cache[i][j] > cache[i][j - 1] && cache[i][j] > cache[i - 1][j]
		&& cache[i][j] > cache[i - 1][j - 1]) {
		printf("item %d\n", i);
		traceback(i - 1, j - 1);
	}
	// j-1 ���Է� i��° �������� �������� ��찡 j���Է� i��° �������� �������� ���� ����.
	else if (cache[i][j] == cache[i][j - 1] && cache[i][j] > cache[i - 1][j])
		traceback(i, j - 1);
	// i�� i-1�� ����. ���� �������� �������� ���� �ٸ��� ����. ��, ���� �������� �������� ����.
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