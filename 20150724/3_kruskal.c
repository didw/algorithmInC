// 3_kruskal.c
// 크루스칼 알고리즘
// 1. 그래프 내의 모든 간선을 오름차순순으로 정렬한다.
//    간선의 가중치가 가장 작은 것이 우선선위가 제일 높다는 것을 의미
// 2. 가장 우선 순위가 높은 간선 부터 최소 신장 트리에 추가한다.
//    단, 최소 신장 트리 내에 사이클이 생기지 않도록 한다.
//    사이클이 생기지 않게 체크하는 기준은 분리 집합 사용
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

// 데이터 삽입
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

// 1. 분리집합을 초기화한다.
void find_init()
{
	int i;
	for (i = 0; i < V; i++)
		parent[i] = -1;
}

// 3. 분리집합을 합집합한다.
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

// 2. 같은 분리집합인지 확인한다.
// 같은 분리집합인지 확인하는 방법은 부모를 찾아서 부모가 갖지 않음을 보이면 된다.
// 부모의 값은 -1
int find_set(int v1, int v2)
{
	int i = v1, j = v2;
	while (parent[i] >= 0)
		i = parent[i];
	while (parent[j] >= 0)
		j = parent[j];
	if (i != j)
		union_set(i, j);	// 최종 부모를 찾아 합집합을 진행
	return i != j;
}

void kruskal()
{
	int i, e;
	pq_init();
	find_init();

	//1. 모든 정점을 pq삽입한다.
	// 우선순위 큐가 가중치가 가장 낮은 것이 루트가 되도록 정렬
	for (i = 0; i < E; i++)
		pq_insert(i);

	while (!pq_empty())
	{
		e = pq_remove();
		//2. 분리집합인지 확인한다.
		//   edge[e]의 양쪽 정점이 같은 집합에 속해 있는지 확인 한 후
		//   같은 집합이 아니면 최소 신장 트리에 추가
		//   집합을 합친다.
		if (find_set(edge[e].v1, edge[e].v2))
		{
			printf("%c %c\n", int2name(edge[e].v1), int2name(edge[e].v2));
			cost += edge[e].weight;
		}
	}
	printf("최소비용 : %d\n", cost);
}

// AB 10 형태의 자료를 입력받는다.
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