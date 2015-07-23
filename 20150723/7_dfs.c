// 7_dfs.c
// 깊이 우선 탐색 ( Depth First Search )
// 1. 시작 정점을 방문한 후 '방문했음'으로 표시한다.
// 2. 시작 정점과 이웃한 정점 중에 방문하지 않은 곳을 다시 시작정점으로 1번을 반복한다.
// 3. 더이상 방문할 인접 정점이 없으면 2로 돌아가서 2를 수행한다.
// 4. 더이상 방문할 정점이 없으면 탐색을 종료한다.

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
	int vertex;
	struct _node *next;
} node;

node *adj[100];
int visited[100];
int n;

void dfs(int i)
{
	node *t;
	visited[i] = 1;
	// visit(i);
	printf("%c\n", (char)(i + 'A'));
	for (t = adj[i]; t != NULL; t = t->next)
	{
		if (visited[t->vertex] != 1)
			dfs(t->vertex);
	}
}

void dfs_all()
{
	int i;
	for (i = 0; i < n; i++)
		if (visited[i] == 0)
			dfs(i);
}

int main()
{
	int i, j, k;
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
		// adj[a] = t;
		// 2. s != null이면
		// 기존의 인접 정점이 있다는 의미기 때문에
		// loop를 돌면서, insert_back 실행
		// 리스트의 마지막에 새로운 정점을 추가한다.
		if (s == NULL)
			adj[a] = t;
		else {
			while (s->next != NULL) {
				s = s->next;
			}
			s->next = t;
		}
	}

	dfs_all();
}