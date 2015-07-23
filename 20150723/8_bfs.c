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
	init_queue();
	put(i);
	visited[i] = 1;
	printf("%c\n", (char)(i + 'A'));

	// 1. ť�� ���ִ� ���ȿ�
	// 2. ť���� ���� ������.
	// 3. �ش� ������ ������ ������ �� �湮���� ���� �������� "�湮����"���� ǥ���ϰ�
	//    ť�� �߰��Ѵ�.
	// 4. "�湮����"�̶� ���� ȭ�鿡 �ش� ������ ����ϴ� ���� �ǹ��Ѵ�.
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
	bfs_all();
}