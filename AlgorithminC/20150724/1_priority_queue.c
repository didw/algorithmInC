// 1_priority_queue.c
// 우선순위 큐
// 우선 순위에 의해서 순위가 유지되는 추상적인 자료 구조
// 힙트리를 구성해서 만들 수 있다.

// 힙트리의 조건
// 1. 힙트리의 노드 번호는 1번부터 시작한다.
// 2. 번호 i인 노드의 부모의 번호는 i/2이다.
// 3. 번호 i인 노드의 왼쪽 자식 번호는 i*2, 오른쪽 자식 번호는 i*2+1이다.
// 4. 힙트리의 자료 개수가 n일 경우, 내부 노드(자식이 있는 노드)의 개수는 n/2까지이다.

// 힙트리의 삽입
// 1. 말단 노드에 데이터 삽입 후, upheap()을 수행한다.
// 2. 부모와 자식을 비교하여 부모보다 자식이 클 경우 부모와 자식을 교환
//    index가 0보다 크고, 부모가 자식보다 작을 경우 동안 반복

// 힙트리의 삭제
// 1. 루트 노드의 데이터를 삭제한다. 삭제 후 리턴
// 2. 말단 노드의 데이터를 루트에 넣는다. downheap()을 수행한다.
// 3. 부모와 자식을 비교하여 부모가 자식보다 작을 경우 부모와 자식을 교환한다.
//    이때, 자식이 2개(왼쪽,오른쪽) 일 경우, 둘중 큰 자식과 비교한다.
// 4. index가 n/2보다 크고, 부모가 자식보다 작을 동안 반복

#include <stdio.h>

#define MAX 100

int heap[MAX];
int nheap = 0;

void upheap(int k)
{
	int value;
	value = heap[k];
	while (k/2 > 0 && heap[k/2] <= value)
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
	// 1. 현재 값을 보관한다.
	// 2. 내부노드일 동안 
	//    2.1. 나의 자식 노드를 찾는다.
	//    2.2. 오른쪽 자식과 왼쪽 자식 중 큰 값의 인덱스를 취한다.
	//    2.3. 큰 자식의 값과 나의 값을 비교, 
	//         만약 내가 자식보다 크다면 루프 탈출
	//         만약 내가 자식보다 작다면 자식과 교환
	//    2.4. 나의 인덱스를 자식의 인덱스로 변경
	// 3. 현재 인덱스 값에 보관한 값을 저장
	int i;
	int value = heap[k];
	while (k <= nheap / 2)
	{
		i = k * 2;
		if (i < nheap && heap[i] < heap[i + 1])
			i++;
		if (value > heap[i])
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

int main()
{
	int arr[] = { -1, 1, 5, 7, 3, 6 };
	int i;
	for (i = 1; i <= 5; i++)
		pq_insert(arr[i]);

	for (i = nheap; i >= 1; i--)
		arr[i] = pq_remove();

	for (i = 1; i <= 5; i++)
		printf("%3d", arr[i]);
	printf("\n");

	// printf("%d\n", pq_remove());
}