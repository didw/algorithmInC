// 8_bfs.c
// 너비 우선 탐색 ( Breadth First Search )
// 1. 시작 정점을 "방문했음"으로 표시하고, 시작 정점을 큐에 삽입한다.
// 2. 큐로 부터 정점을 제거하고, 제거한 정점의 인접 정점 중 아직 방문하지 않은 정점을
//    "방문했음"으로 표시하고, 큐에 삽입한다.
// 3. 큐가 빌 때까지 반복한다.

#include "queue.h"
/*
7 16
0 1
0 2
0 6
0 3
1 0
1 4
1 2
2 0
2 1
2 5
3 0
4 1
5 2
5 6
6 0
6 5
*/
typedef struct _node
{
	int vertex;
	struct _node *next;
} node;

node *adj[100];
int visited[100];
int n;

void bfs(int i)
{
	init_queue();
	put(i);
	visited[i] = 1;
	printf("%c\n", (char)(i + 'A'));

	// 1. 큐가 차있는 동안에
	// 2. 큐에서 값을 꺼낸다.
	// 3. 해당 정점과 인접한 정점들 중 방문하지 않은 정점들을 "방문했음"으로 표시하고
	//    큐에 추가한다.
	// 4. "방문했음"이라 함은 화면에 해당 정점을 출력하는 것을 의미한다.
	while (!is_empty()) {
		node* t = adj[get()];
		while (t != NULL) {
			if (!visited[t->vertex]){
				put(t->vertex);
				visited[t->vertex] = 1;
				printf("%c\n", (char)(t->vertex + 'A'));
			}
			t = t->next;
		}
	}
	
}

void bfs_all()
{
	int i;
	for (i = 0; i < n; i++)
		if (visited[i] == 0)
			bfs(i);
}

int main()
{
	int i, k;
	int a = 0, b = 0;
	node *t, *s;
	scanf("%d %d", &n, &k);
	for (i = 0; i < k; i++)
	{
		scanf("%d %d", &a, &b);
		t = (node*)malloc(sizeof(node));

		// 인접리스트를 만들어 보세요.
		// 1. t->vertex값에 b를 입력하고
		// 2. t->next 는 null 초기화
		t->vertex = b;
		t->next = NULL;

		s = adj[a];
		// 1. s == null이면 
		if (s == NULL)
			adj[a] = t;
		// adj[a] = t;
		// 2. s != null이면
		else
		{
			// 기존의 인접 정점이 있다는 의미기 때문에
			// loop를 돌면서, insert_back 실행
			// 리스트의 마지막에 새로운 정점을 추가한다.
			while (s->next != NULL)
			{
				s = s->next;
			}
			s->next = t;
		}
	}
	bfs_all();
}