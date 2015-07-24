// 4_dijkstra.c
// ���ͽ�Ʈ�� �˰���
// ���� ���������� ��� ��η� ���� �ִ� ��θ� ���ϴ� �˰���
// 1. ������ ������ ������������ �غ��ϰ�, 
//    ������ �ִܰ�δ� ���Ѵ�� �ʱ�ȭ �Ѵ�.
// 2. ���������� �ִܰ�δ� 0���� ����, �ִ� ��ο� �߰��Ѵ�.
// 3. �߰��� ������ ���������� �ִ� ��θ� ���Ѵ�.
//    ������ �ִ� ��κ��� ���� ���� �ִ� ��� ( ������ �ִܰ�� + ���������� ����ġ)��
//    �۴ٸ� �ִ� ��θ� �����Ѵ�.
// 4. �׷��� ���� ��� �ִ� ��ΰ� ������ ������ (ť�� �� ������ ) �ݺ��Ѵ�.

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

int adj[MAX][MAX];
int dist[MAX];
int priority[MAX];
int visited[MAX];
int parent[MAX];
int cost;
int V, E;
int heap[MAX];
int nheap = 0;

void upheap(int k)
{
	int value;
	value = heap[k];
	while (k / 2 > 0 && dist[heap[k / 2]] > dist[value])
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
		if (i < nheap && dist[heap[i]] >= dist[heap[i + 1]])
			i++;
		if (dist[value] <= dist[heap[i]])
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


// ������ ����
// AB 10
// BC 20
int name2int(char c)
{
	return c - 'A';
}

int int2name(int i)
{
	return i + 'A';
}

void dijkstra(int k)
{
	int i, u;
	int cost = 0, next_cost = 0;
	pq_init();

	for (i = 0; i < V; i++)
	{
		dist[i] = 9999;
	}

	pq_insert(k);
	dist[k] = 0;
	parent[k] = 0;

	while (!pq_empty())
	{
		u = pq_remove();
		cost = dist[u];	// ���� ������ �ִ� ��θ� �����´�.

		// ���� ������ �켱���� ť�� �����Ѵ�.
		for (i = 0; i < V; i++)
		{
			if (adj[u][i] != 0)
			{
				next_cost = cost + adj[u][i];
				if (dist[i] > next_cost)
				{
					dist[i] = next_cost;
					pq_insert(i);
					parent[i] = u;
				}
			}
		}
	}
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
	}
}

// �� ����� �ִܰŸ��� �����ϴ� ������ ȭ�鿡 ����ϼ���.
void shortest_path()
{
	int i;
	int path[MAX];
	for (i = 0; i < V; ++i) {
		int end = i, idx = 0;
		while (parent[end] != end) {
			path[idx++] = end;
			end = parent[end];
		}
		path[idx] = 0;
		for (int j = idx; j >= 0; --j) {
			printf("%d ", path[j]);
			if (j) printf("-> ");
		}
		printf("\n");
	}
}

int main()
{
	int i;
	input();
	dijkstra(0);
	for (i = 0; i < V; i++)
		printf("%c %c shortest path : %d\n", int2name(0), int2name(i), dist[i]);
	shortest_path();
}