// 7_dfs.c
// ���� �켱 Ž�� ( Depth First Search )
// 1. ���� ������ �湮�� �� '�湮����'���� ǥ���Ѵ�.
// 2. ���� ������ �̿��� ���� �߿� �湮���� ���� ���� �ٽ� ������������ 1���� �ݺ��Ѵ�.
// 3. ���̻� �湮�� ���� ������ ������ 2�� ���ư��� 2�� �����Ѵ�.
// 4. ���̻� �湮�� ������ ������ Ž���� �����Ѵ�.

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

		// ��������Ʈ�� ����� ������.
		// 1. t->vertex���� b�� �Է��ϰ�
		// 2. t->next �� null �ʱ�ȭ
		t->vertex = b;
		t->next = NULL;

		s = adj[a];
		// 1. s == null�̸� 
		// adj[a] = t;
		// 2. s != null�̸�
		// ������ ���� ������ �ִٴ� �ṉ̀� ������
		// loop�� ���鼭, insert_back ����
		// ����Ʈ�� �������� ���ο� ������ �߰��Ѵ�.
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