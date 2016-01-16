// 4_fractional_knapsack.c
// �κ� �賶 ����
// 0-1 �賶 ������ �׸��� �˰������� Ǯ���.
// N = 3, W = 30
// item1 5  50		10
// item2 10 60		6
// item3 20 140		7

// 1. item�� ������ ������ �賶�� ���� ������
// 2. item�� v/w ���Դ� ��ġ�� ������ �賶�� ���� ������

// �κ� �賶 ������ �׸��� �˰����� �̿��ؼ� �����ظ� ���� �� �ִ�.
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

// Ž�� �˰���
// 1. ���Դ� ��ġ�� ���� ū ������� �����Ѵ�.
// 2. ù��° ���� ������� ������ �ؿ� ���Խ�Ų��.
// 3. ���Խ�ų �� �賶�� ���� ���Ը� ���� �ʰ� �ؾ� �Ѵ�.
//    3.1) �賶�� ���� ���Կ� ������ ��ü�� ���� �������� value�� �߰�
//    3.2) �賶�� ���� ���Կ� ������ ��ü�� ���� ������
//         ������ �ɰ��� ������ �ȴ�.
//         ���� ����*���Դ簡ġ �� �߰�
//    ������ �賶�� �־��ٸ� �賶�� ���� = ���� ���� - ������ ����
// 4. �賶�� ���� ���԰� 0�� �ɶ����� �ݺ��Ѵ�.

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