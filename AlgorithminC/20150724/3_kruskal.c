// 3_kruskal.c
// ũ�罺Į �˰���
// 1. �׷��� ���� ��� ������ �������������� �����Ѵ�.
//    ������ ����ġ�� ���� ���� ���� �켱������ ���� ���ٴ� ���� �ǹ�
// 2. ���� �켱 ������ ���� ���� ���� �ּ� ���� Ʈ���� �߰��Ѵ�.
//    ��, �ּ� ���� Ʈ�� ���� ����Ŭ�� ������ �ʵ��� �Ѵ�.
//    ����Ŭ�� ������ �ʰ� üũ�ϴ� ������ �и� ���� ���
#include <stdio.h>

#define MAX 100

typedef struct _edge
{
	int v1, v2;
	int weight; 
} EDGE;

EDGE edge[MAX];
int height[MAX];
int parent[MAX];
int heap[MAX];
int nheap = 0;
int V, E;
int cost;

void upheap(int k)
{
	int value;
	value = heap[k];
	while (k / 2 > 0 && edge[heap[k / 2]].weight > edge[value].weight)
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
		if (i < nheap && edge[heap[i]].weight >= edge[heap[i + 1]].weight)
			i++;
		if (edge[value].weight <= edge[heap[i]].weight)
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

// 1. �и������� �ʱ�ȭ�Ѵ�.
void find_init()
{
	int i;
	for (i = 0; i < V; i++)
		parent[i] = -1;
}

// 3. �и������� �������Ѵ�.
void union_set(int v1, int v2)
{
	int t;
	if (height[v1] == height[v2])
		height[v2]++;
	if (height[v1] > height[v2])
	{
		t = height[v1];
		height[v1] = height[v2];
		height[v2] = t;
	}
	parent[v1] = v2;
}

// 2. ���� �и��������� Ȯ���Ѵ�.
// ���� �и��������� Ȯ���ϴ� ����� �θ� ã�Ƽ� �θ� ���� ������ ���̸� �ȴ�.
// �θ��� ���� -1
int find_set(int v1, int v2)
{
	int i = v1, j = v2;
	while (parent[i] >= 0)
		i = parent[i];
	while (parent[j] >= 0)
		j = parent[j];
	if (i != j)
		union_set(i, j);	// ���� �θ� ã�� �������� ����
	return i != j;
}

void kruskal()
{
	int i, e;
	pq_init();
	find_init();

	//1. ��� ������ pq�����Ѵ�.
	// �켱���� ť�� ����ġ�� ���� ���� ���� ��Ʈ�� �ǵ��� ����
	for (i = 0; i < E; i++)
		pq_insert(i);

	while (!pq_empty())
	{
		e = pq_remove();
		//2. �и��������� Ȯ���Ѵ�.
		//   edge[e]�� ���� ������ ���� ���տ� ���� �ִ��� Ȯ�� �� ��
		//   ���� ������ �ƴϸ� �ּ� ���� Ʈ���� �߰�
		//   ������ ��ģ��.
		if (find_set(edge[e].v1, edge[e].v2))
		{
			printf("%c %c\n", int2name(edge[e].v1), int2name(edge[e].v2));
			cost += edge[e].weight;
		}
	}
	printf("�ּҺ�� : %d\n", cost);
}

// AB 10 ������ �ڷḦ �Է¹޴´�.
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
		edge[i].v1 = a;
		edge[i].v2 = b;
		edge[i].weight = c;
	}
}

int main()
{
	input();
	kruskal();
}