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
#include <string.h>

#define MAX 100

float adj[MAX][MAX];
float dist[MAX];
int priority[MAX];
int visited[MAX];
int parent[MAX];
int cost;
int V, E;
int heap[MAX];
char cities[MAX][12];
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
	float cost = 0, next_cost = 0;
	pq_init();

	for (i = 0; i < V; i++)
	{
		dist[i] = 9999;
	}

	pq_insert(k);
	dist[k] = 0;
	parent[k] = k;

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
	int a, b;
	float c;
	int i;
	for (i = 0; i < E; i++)
	{
		scanf("%d %d %f\n", &a, &b, &c);
		adj[a][b] = c;
	}
	for (i = 0; i < V; ++i)
		gets(cities[i]);
}

// �� ����� �ִܰŸ��� �����ϴ� ������ ȭ�鿡 ����ϼ���.
void shortest_path(int b)
{
	int i = b;
	int path[MAX];
	int idx = 0;
	while (parent[i] != i) {
		path[idx++] = i;
		i = parent[i];
	}
	path[idx] = i;
	for (int j = idx; j >= 0; --j) {
		printf("%s ", cities[path[j]]);
		if (j) printf("-> ");
	}
	printf("\n total length : %f\n\n", dist[b]);
}

int str2int(char *a) {
	for (int i = 0; i < V; ++i) {
		if (strcmp(cities[i], a) == 0)
			return i;
	}
	return -1;
}

void reset() {
	memset(dist, 0, sizeof(dist));
	memset(priority, 0, sizeof(priority));
	memset(visited, 0, sizeof(visited));
	memset(parent, 0, sizeof(parent));
	memset(heap, 0, sizeof(heap));
}

int main()
{
	int i;
	input();
	while (1) {
		char aa[10], bb[10];
		int a = 0, b = 0;
		printf("�����: ");
		gets(aa);
		printf("������: ");
		gets(bb);
		a = str2int(aa);
		b = str2int(bb);
		if (a == -1 || b == -1) {
			printf("��Ȯ�� ���̸��� �Է����ּ���.\n");
			continue;
		}
		reset();
		dijkstra(a);
		shortest_path(b);
		getch();
	}
}