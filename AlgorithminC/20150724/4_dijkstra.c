// 4_dijkstra.c
// 다익스트라 알고리즘
// 단일 시작점에서 모든 경로로 가는 최단 경로를 구하는 알고리즘
// 1. 임의의 정점을 시작정점으로 준비하고, 
//    정점의 최단경로는 무한대로 초기화 한다.
// 2. 시작정점의 최단경로는 0으로 설정, 최단 경로에 추가한다.
// 3. 추가된 정점의 인접정점의 최단 경로를 구한다.
//    기존의 최단 경로보다 새로 구한 최단 경로 ( 정점의 최단경로 + 인접정점의 가중치)가
//    작다면 최단 경로를 갱신한다.
// 4. 그래프 내의 모든 최단 경로가 구해질 때까지 (큐가 빌 때까지 ) 반복한다.

// 2.prim.c
// 프림 알고리즘
// 너비 우선 탐색을 기반으로 한 탐욕적 알고리즘
// 1. 비어 있는 최소 신장 트리를 준비한다.
// 2. 임의의 정점을 시작 정점으로 해서 최소 신장 트리의 루트 노드로 삽입한다.
// 3. 인접한 정점 중 가중치가 가장 작은 것을 선택해 간선과 연결된 정점을 최소 신장 트리에
//    삽입한다.
//    (단, 삽입시 트리의 사이클이 생기지 않아야 한다.)
// 4. 3번 과정을 반복 후 모든 정점을 연결하면 종료한다.

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
		cost = dist[u];	// 현재 정점의 최단 경로를 가져온다.

		// 인접 정점을 우선순위 큐에 삽입한다.
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

// 각 경로의 최단거리와 경유하는 정점을 화면에 출력하세요.
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
		printf("출발지: ");
		gets(aa);
		printf("도착지: ");
		gets(bb);
		a = str2int(aa);
		b = str2int(bb);
		if (a == -1 || b == -1) {
			printf("정확한 역이름을 입력해주세요.\n");
			continue;
		}
		reset();
		dijkstra(a);
		shortest_path(b);
		getch();
	}
}