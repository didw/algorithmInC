// binary search tree
// 이분 검색은 배열만 가능한 탐색 방법이다.
// 이분 검색은 빠르고, 알고리즘도 간단하지만
// 삽입 삭제가 많은 데이터는 데이터를 옮겨줘야 하는 일이 빈번하기 때문에
// 고정적인 데이터일 경우에 유용하다.

// 동적인 데이터를 사용하는 자료 구조를 위해 이진 검색 나무를 사용하자.

// 트리
// root node : 부모가 없는 노드
// leaf node : 자식이 없는 노드
// depth : 부모에서 단말 노드까지 가는 경로의 길이
// level : depth가 같은 노드의 집합
// sibiling : 같은 부모를 가지는 노드
// 사이클이 존재하지 않는다.
// -> 한 노드에서 다른 노드로 이동하는 경로가 하나만 존재한다는 의미

// 이진 검색 트리
// 왼쪽엔 루트보다 작은 값이 오른쪽엔 루트보다 큰 값이 오도록 하는 자료 구조
// 자식이 2개인 트리
// 검색시 O(logN)의 성능을 갖는 검색 자료 구조

#include "algorithm.h"
struct node *root;

// 검색함수를 만들어 보세요.

struct node* bst_search(int key, struct node *temp)
{
	// 트리 탐색시 key = data이면
	// return struct node* 
	// 일치하는 데이터가 없으면
	// temp의 데이터보다 key값이 크면 temp의 오른쪽 자식이동
	// temp의 데이터보다 key값이 작으면 temp의 왼쪽 자식이동
	// 반복하면서 검색
	// 검색 종료까지 일치하는 데이터가 존재하지 않으면
	// return NULL;
	// 1. 재귀호출 형태로 만들 수 있다.
	
	if (temp == NULL)
		return NULL;

	if (temp->data == key)
		return temp;
	if (temp->data > key)
		return bst_search(key, temp->left);
	else
		return bst_search(key, temp->right);
	
	// 2. 반복문 형태로 만들 수 있다.
	/*
	struct node* s = temp;
	// short circuit
	// AND 논리연산시에  첫번째 연산이 거짓이면 나머지 연산은 수행하지 않음 -> 무조건 거짓
	// OR 논리연산시에 첫번째 연산이 참이면 나머지 연산은 수행하지 않음 -> 무조건 참
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

// 이진 검색 트리의 균형을 잡아는 주는 방법
// 1. 배열을 선언한다.
// 2. in-order하면서 배열에 데이터를 채운다.
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
	// a의 배열은 temp->data
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
	// 1. 배열을 선언하고
	// 2. 배열을 채운다.
	// 3. bal() 호출
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

	// 검색수행
	/*
	temp = bst_search(9, root);
	if (temp != NULL)
		printf("found\n");
	else
		printf("failed\n");
	*/
}
