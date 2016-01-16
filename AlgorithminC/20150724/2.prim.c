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

#define MAX 100

int weight[MAX];

int heap[MAX];
int nheap = 0;

// priority_queue의 값을 변경해 준다.
// 1. 우선순위는 가중치의 값이 작은 순으로 오름 차순한다.
//    루트가 가장 작은 가중치를 갖도록 변경
// 2. heap트리의 값은 정점의 index를 담는다.

// 정점의 index와 weight[]배열을 이용해서 다음 구현부를 수정하세요.
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

// 데이터 삽입
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
		visited[u] = 1;		// 방문여부 설정
		// 인접 정점을 우선순위 큐에 삽입한다.
		for (i = 0; i < V; i++)
		{
			// 1. 방문하지 않은 정점이고
			// 2. 기존에 보관한 weight값보다 작을 경우 큐에 추가한다.
			if (adj[u][i] != 0 && visited[i] == 0 && adj[u][i] < weight[i])
			{
				weight[i] = adj[u][i];
				pq_insert(i);
				priority[i] = u;		// priority[i] : fr-vertex, i:to-vertex
			}
		}
	}

	// ------------------------------------
	// 화면에 간선의 목록을 출력한다.
	for (i = 0; i < V; i++)
	{
		if (priority[i] != -1)
		{
			printf("%c %c\n", int2name(priority[i]), int2name(i));
			cost += weight[i];
		}
	}
	printf("최소 비용 : %d\n", cost);
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