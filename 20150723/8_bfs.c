// 8_bfs.c
// �ʺ� �켱 Ž�� ( Breadth First Search )
// 1. ���� ������ "�湮����"���� ǥ���ϰ�, ���� ������ ť�� �����Ѵ�.
// 2. ť�� ���� ������ �����ϰ�, ������ ������ ���� ���� �� ���� �湮���� ���� ������
//    "�湮����"���� ǥ���ϰ�, ť�� �����Ѵ�.
// 3. ť�� �� ������ �ݺ��Ѵ�.

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
	node *t;
	int j;
	init_queue();

	put(i);
	visited[i] = 1;
	// visit(i);
	printf("%c\n", (char)(i + 'A'));

	// 1. ť�� ���ִ� ���ȿ�
	// 2. ť���� ���� ������.
	// 3. �ش� ������ ������ ������ �� �湮���� ���� �������� "�湮����"���� ǥ���ϰ�
	//    ť�� �߰��Ѵ�.
	// 4. "�湮����"�̶� ���� ȭ�鿡 �ش� ������ ����ϴ� ���� �ǹ��Ѵ�.
	while (!is_empty())
	{
		j = get();
		for (t = adj[j]; t != NULL; t = t->next)
		{
			if (visited[t->vertex] == 0)
			{
				put(t->vertex);
				visited[t->vertex] = 1;
				printf("%c\n", (char)(t->vertex + 'A'));
			}
		}
	}
}

// ����ġ�� ���� �׷��������� �ִ� �Ÿ���
// ������ ���� ���Ѵ�.
// ����ġ�� ���� �׷��������� �ִ� �Ÿ��� �ʺ� �켱 Ž�������� �ذ��� �� �ִ�.
int dist[100];
int parent[100];

void bfs2(int i)
{
	node *t;
	int j;
	init_queue();

	for (i = 0; i < n; i++)
	{
		dist[i] = -1;
		parent[i] = -1;
	}
	i = 0;
	put(i);
	dist[i] = 0;
	parent[i] = i;

	while (!is_empty())
	{
		j = get();
		for (t = adj[j]; t != NULL; t = t->next)
		{
			if (dist[t->vertex] == -1)
			{
				put(t->vertex);
				dist[t->vertex] = dist[j] + 1;	// �ִ� ��� �Ÿ���
				parent[t->vertex] = j;			// �θ� �������ϱ� ���� ��
			}
		}
	}
}

// ��Ʈ���� u������ �ִ� ��θ� ���ϴ� �Լ�
int path[100];
// A - B - C
// C - B - A
void shortest_path(int u)
{
	int idx = 0;
	int i;
	path[idx++] = u;
	printf("�ִ� �Ÿ� : %d\n", dist[u]);
	while (parent[u] != u)
	{
		u = parent[u];	// �ڽ��� �θ� ã�´�. �ڽ��� �θ� �ɶ�����
		path[idx++] = u;
	}

	for (i = idx - 1; i >= 0; i--)
		printf("%c\n", (char)(path[i] + 'A'));
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

		// ��������Ʈ�� ����� ������.
		// 1. t->vertex���� b�� �Է��ϰ�
		// 2. t->next �� null �ʱ�ȭ
		t->vertex = b;
		t->next = NULL;

		s = adj[a];
		// 1. s == null�̸� 
		if (s == NULL)
			adj[a] = t;
		// adj[a] = t;
		// 2. s != null�̸�
		else
		{
			// ������ ���� ������ �ִٴ� �ṉ̀� ������
			// loop�� ���鼭, insert_back ����
			// ����Ʈ�� �������� ���ο� ������ �߰��Ѵ�.
			while (s->next != NULL)
			{
				s = s->next;
			}
			s->next = t;
		}
	}
	// �ʺ� �켱 Ž�� ȣ��
	bfs2(0);
	shortest_path(4);
}