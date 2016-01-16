// binary search tree
// �̺� �˻��� �迭�� ������ Ž�� ����̴�.
// �̺� �˻��� ������, �˰��� ����������
// ���� ������ ���� �����ʹ� �����͸� �Ű���� �ϴ� ���� ����ϱ� ������
// �������� �������� ��쿡 �����ϴ�.

// ������ �����͸� ����ϴ� �ڷ� ������ ���� ���� �˻� ������ �������.

// Ʈ��
// root node : �θ� ���� ���
// leaf node : �ڽ��� ���� ���
// depth : �θ𿡼� �ܸ� ������ ���� ����� ����
// level : depth�� ���� ����� ����
// sibiling : ���� �θ� ������ ���
// ����Ŭ�� �������� �ʴ´�.
// -> �� ��忡�� �ٸ� ���� �̵��ϴ� ��ΰ� �ϳ��� �����Ѵٴ� �ǹ�

// ���� �˻� Ʈ��
// ���ʿ� ��Ʈ���� ���� ���� �����ʿ� ��Ʈ���� ū ���� ������ �ϴ� �ڷ� ����
// �ڽ��� 2���� Ʈ��
// �˻��� O(logN)�� ������ ���� �˻� �ڷ� ����

#include "algorithm.h"
struct node *root;

// �˻��Լ��� ����� ������.

struct node* bst_search(int key, struct node *temp)
{
	// Ʈ�� Ž���� key = data�̸�
	// return struct node* 
	// ��ġ�ϴ� �����Ͱ� ������
	// temp�� �����ͺ��� key���� ũ�� temp�� ������ �ڽ��̵�
	// temp�� �����ͺ��� key���� ������ temp�� ���� �ڽ��̵�
	// �ݺ��ϸ鼭 �˻�
	// �˻� ������� ��ġ�ϴ� �����Ͱ� �������� ������
	// return NULL;
	// 1. ���ȣ�� ���·� ���� �� �ִ�.
	
	if (temp == NULL)
		return NULL;

	if (temp->data == key)
		return temp;
	if (temp->data > key)
		return bst_search(key, temp->left);
	else
		return bst_search(key, temp->right);
	
	// 2. �ݺ��� ���·� ���� �� �ִ�.
	/*
	struct node* s = temp;
	// short circuit
	// AND ������ÿ�  ù��° ������ �����̸� ������ ������ �������� ���� -> ������ ����
	// OR ������ÿ� ù��° ������ ���̸� ������ ������ �������� ���� -> ������ ��
	while (s != NULL && s->data != key)
	{
		if (s->data > key)
			s = s->left;
		else
			s = s->right;
	}
	if (s == NULL)
		return NULL;
	else
		return s;
	*/
}

void insert_data(int data)
{
	struct node *temp;
	struct node **p = &root;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = 0;
	temp->right = 0;

	while (*p)
	{
		if ((*p)->data > data)
			p = &(*p)->left;
		else if ((*p)->data < data)
			p = &(*p)->right;
		else
			return;
	}
	*p = temp;
}

// ���� �˻� Ʈ���� ������ ��ƴ� �ִ� ���
// 1. �迭�� �����Ѵ�.
// 2. in-order�ϸ鼭 �迭�� �����͸� ä���.
// 3. mid = n/2
// 4. temp->data = a[mid];
//    temp->left = bal(a, mid);
//    temp->right = bal(a+mid+1, n-mid-1);
//    return temp;

void in_order(struct node* temp)
{
	if (temp == NULL)
		return;
	in_order(temp->left);
	printf("%d\n", temp->data);
	in_order(temp->right);
}

void __fill(struct node* temp, int *a, int *n)
{
	if (temp == NULL)
		return;
	__fill(temp->left, a, n);
	// a�� �迭�� temp->data
	a[(*n)++] = temp->data;
	__fill(temp->right, a, n);
}

struct node* __bal(int *a, int n)
{
	// 3. mid = n/2
	// 4. temp->data = a[mid];
	//    temp->left = bal(a, mid);
	//    temp->right = bal(a+mid+1, n-mid-1);
	//    return temp;
	int mid = n/2;
	struct node *temp;
	
	if (n < 1)
		return 0;

	temp = (struct node*)malloc(sizeof(struct node));

	temp->data = a[mid];
	temp->left = __bal(a, mid);
	temp->right = __bal(a + mid + 1, n - mid - 1);

	return temp;
}


void balance(struct node* temp)
{
	int a[100] = { 0, };
	int i, n = 0;
	__fill(temp, a, &n);
	// 1. �迭�� �����ϰ�
	// 2. �迭�� ä���.
	// 3. bal() ȣ��
	root = __bal(a, n);
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5, 6, 7 };
	int i;
	struct node* temp;
	//display(root);
	for (i = 0; i < 7; i++)
	{
		insert_data(a[i]);
		//display(root);
	}
	//display(root);

	balance(root);
	display(root);

	// �˻�����
	/*
	temp = bst_search(9, root);
	if (temp != NULL)
		printf("found\n");
	else
		printf("failed\n");
	*/
}
