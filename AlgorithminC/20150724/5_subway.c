#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

double adj[MAX][MAX];
int n;
double INF = 9999.0;
double dist[MAX];
int heap[MAX];
int parent[MAX];
int nheap = 0;
int cost = 0;
int V, E;
char *name[MAX];

/*
13 24
0 1 3.0
1 0 3.0
1 2 2.5
2 1 2.5
1 4 1.8
4 1 1.8
2 3 3.2
3 2 3.2
2 7 2.0
7 2 2.0
2 10 3.5
10 2 3.5
4 5 2.4
5 4 2.4
4 7 2.0
7 4 2.0
5 6 4.0
6 5 4.0
7 8 3.0
8 7 3.0
8 9 2.5
9 8 2.5
7 11 3.2
11 7 3.2
11 12 5.0
12 11 5.0
아현
충정로
시청
을지로입구
애오개
공덕
마포
서울역
남영
용산
회현
숙대입구
삼각지

*/
int name2int(char* s)
{
	int i;
	for (i = 0; i < V; i++)
		if (strcmp(s, name[i]) == 0)
			return i;
	return -1;
}

char* int2name(int i)
{
	return name[i];
}

void upheap(int k)
{
	int value;
	value = heap[k];

	while (dist[heap[k / 2]] > dist[value] && k / 2 > 0)
	{
		heap[k] = heap[k / 2];
		k /= 2;
	}
	heap[k] = value;
}

void downheap(int k)
{
	int i;
	int value = heap[k];
	while (k <= nheap / 2)
	{
		i = k << 1; // k*2 = k의 왼쪽 자식이다.
		if (i < nheap && dist[heap[i]] > dist[heap[i + 1]])
			i++;
		if (dist[value] <= dist[heap[i]])
			break;

		heap[k] = heap[i];
		k = i;
	}

	heap[k] = value;;
}

void pq_insert(int value)
{
	heap[++nheap] = value;
	upheap(nheap);
}

void pq_init()
{
	nheap = 0;
}

int pq_empty()
{
	if (nheap == 0) return 1;
	return 0;
}

int pq_remove()
{
	int value = heap[1]; // root
	heap[1] = heap[nheap--];
	downheap(1);
	return value;
}

void dijkstra(int src)
{
	int i, u;
	double cost, next_cost;
	for (i = 0; i < V; i++)
		dist[i] = INF;
	dist[src] = 0;

	pq_init();
	parent[src] = src;
	pq_insert(src);
	while (!pq_empty())
	{
		u = pq_remove();
		cost = dist[u];

		for (i = 0; i < V; i++)
		{
			if (adj[u][i] != 0)
			{
				next_cost = adj[u][i] + cost;
				if (dist[i] > next_cost)
				{
					dist[i] = next_cost;
					parent[i] = u;
					pq_insert(i);
				}
			}
		}
	}
}

void input()
{
	scanf("%d %d", &V, &E);
	int a, b;
	double c;
	int i;
	char buff[100];

	// 그래프 생성
	for (i = 0; i < E; i++)
	{
		scanf("%d %d %lf", &a, &b, &c);
		adj[a][b] = c;
	}

	// 지하철역이름 저장
	for (i = 0; i < V; i++)
	{
		scanf("%s", buff);
		name[i] = (char*)malloc(strlen(buff) + 1);
		strcpy(name[i], buff);
	}
}

// 각 경로의 최단거리와 경유하는 정점을 화면에 출력하세요.
// 루트부터 u정점에 최단 경로를 구하는 함수
int path[100];
void shortest_path(int u)
{
	int idx = 0;
	int i;
	path[idx++] = u;
	while (parent[u] != u)
	{
		u = parent[u];	// 자신의 부모를 찾는다. 자신이 부모가 될때까지
		path[idx++] = u;
	}

	printf("-----이동 경로-----\n");
	for (i = idx - 1; i >= 0; i--)
		printf("%s\n", int2name(path[i]));
}

int main()
{
	int s_index, e_index;
	char start[20];
	char end[20];

	input();

	while (1) {
		// 출발지, 도착지 입력
		scanf("%s %s", start, end);

		// 지하철역 이름으로부터 index를 가져온다.
		s_index = name2int(start);
		e_index = name2int(end);

		if (s_index < 0) {
			printf("출발지가 존재하지 않습니다.\n");
			return 0;
		}
		if (s_index < 0) {
			printf("도착지가 존재하지 않습니다.\n");
			return 0;
		}
		dijkstra(s_index);
		printf("출발지(%s) -> 도착지(%s) 소요 시간 : %.1lf\n", start, end, dist[e_index]);
		shortest_path(e_index);
		getch();
	}
	return 0;
}