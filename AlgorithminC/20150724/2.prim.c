// 2.prim.c
// ���� �˰���
// �ʺ� �켱 Ž���� ������� �� Ž���� �˰���
// 1. ��� �ִ� �ּ� ���� Ʈ���� �غ��Ѵ�.
// 2. ������ ������ ���� �������� �ؼ� �ּ� ���� Ʈ���� ��Ʈ ���� �����Ѵ�.
// 3. ������ ���� �� ����ġ�� ���� ���� ���� ������ ������ ����� ������ �ּ� ���� Ʈ����
//    �����Ѵ�.
//    (��, ���Խ� Ʈ���� ����Ŭ�� ������ �ʾƾ� �Ѵ�.)
// 4. 3�� ������ �ݺ� �� ��� ������ �����ϸ� �����Ѵ�.

#include <stdio.h>

#define MAX 100

int weight[MAX];

int heap[MAX];
int nheap = 0;

// priority_queue�� ���� ������ �ش�.
// 1. �켱������ ����ġ�� ���� ���� ������ ���� �����Ѵ�.
//    ��Ʈ�� ���� ���� ����ġ�� ������ ����
// 2. heapƮ���� ���� ������ index�� ��´�.

// ������ index�� weight[]�迭�� �̿��ؼ� ���� �����θ� �����ϼ���.
void upheap(int k)
{
	int value;
	value = heap[k];
	while (k / 2 > 0 && weight[heap[k / 2]] >= weight[value])
	{
		heap[k] = heap[k / 2];
		k /= 2;
	}
	heap[k] = value;
}

void pq_insert(int value)
{
	heap[++nheap] = value;
	upheap(nheap);
}

void downheap(int k)
{
	int i;
	int value = heap[k];
	while (k <= nheap / 2)
	{
		i = k * 2;
		if (i < nheap && weight[heap[i]] > weight[heap[i + 1]])
			i++;
		if (weight[value] > weight[heap[i]])
			break;
		heap[k] = heap[i];
		k = i;
	}
	heap[k] = value;
}

int pq_remove()
{
	int value = heap[1];
	heap[1] = heap[nheap--];
	downheap(1);
	return value;
}

int pq_init()
{
	nheap = 0;
}

int pq_empty()
{
	if (nheap == 0)
		return 1;
	return 0;
}
//--------------------------------------------

int adj[MAX][MAX];
int priority[MAX];
int visited[MAX];
int cost;
int V, E;

// ������ ����
// AB 10
// BC 20
int name2int(char c)
{
	return c - 'A';
}

char int2name(int i)
{
	return i + 'A';
}

void prim()
{
	int i, u;
	pq_init();

	for (i = 0; i < V; i++)
	{
		weight[i] = 9999;
		priority[i] = -1;
	}

	pq_insert(0);
	weight[0] = 0;

	while (!pq_empty())
	{
		u = pq_remove();
		visited[u] = 1;		// �湮���� ����
		// ���� ������ �켱���� ť�� �����Ѵ�.
		for (i = 0; i < V; i++)
		{
			// 1. �湮���� ���� �����̰�
			// 2. ������ ������ weight������ ���� ��� ť�� �߰��Ѵ�.
			if (adj[u][i] != 0 && visited[i] == 0 && adj[u][i] < weight[i])
			{
				weight[i] = adj[u][i];
				pq_insert(i);
				priority[i] = u;		// priority[i] : fr-vertex, i:to-vertex
			}
		}
	}

	// ------------------------------------
	// ȭ�鿡 ������ ����� ����Ѵ�.
	for (i = 0; i < V; i++)
	{
		if (priority[i] != -1)
		{
			printf("%c %c\n", int2name(priority[i]), int2name(i));
			cost += weight[i];
		}
	}
	printf("�ּ� ��� : %d\n", cost);
}

void input()
{
	scanf("%d %d", &V, &E);
	int a, b, c;
	char vertex[3];
	int i;
	for (i = 0; i < E; i++)
	{
		scanf("%s %d", vertex, &c);
		a = name2int(vertex[0]);
		b = name2int(vertex[1]);
		adj[a][b] = c;
		adj[b][a] = c;
	}
}

int main()
{
	input();
	prim();
}