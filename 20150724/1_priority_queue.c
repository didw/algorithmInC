// 1_priority_queue.c
// �켱���� ť
// �켱 ������ ���ؼ� ������ �����Ǵ� �߻����� �ڷ� ����
// ��Ʈ���� �����ؼ� ���� �� �ִ�.

// ��Ʈ���� ����
// 1. ��Ʈ���� ��� ��ȣ�� 1������ �����Ѵ�.
// 2. ��ȣ i�� ����� �θ��� ��ȣ�� i/2�̴�.
// 3. ��ȣ i�� ����� ���� �ڽ� ��ȣ�� i*2, ������ �ڽ� ��ȣ�� i*2+1�̴�.
// 4. ��Ʈ���� �ڷ� ������ n�� ���, ���� ���(�ڽ��� �ִ� ���)�� ������ n/2�����̴�.

// ��Ʈ���� ����
// 1. ���� ��忡 ������ ���� ��, upheap()�� �����Ѵ�.
// 2. �θ�� �ڽ��� ���Ͽ� �θ𺸴� �ڽ��� Ŭ ��� �θ�� �ڽ��� ��ȯ
//    index�� 0���� ũ��, �θ� �ڽĺ��� ���� ��� ���� �ݺ�

// ��Ʈ���� ����
// 1. ��Ʈ ����� �����͸� �����Ѵ�. ���� �� ����
// 2. ���� ����� �����͸� ��Ʈ�� �ִ´�. downheap()�� �����Ѵ�.
// 3. �θ�� �ڽ��� ���Ͽ� �θ� �ڽĺ��� ���� ��� �θ�� �ڽ��� ��ȯ�Ѵ�.
//    �̶�, �ڽ��� 2��(����,������) �� ���, ���� ū �ڽİ� ���Ѵ�.
// 4. index�� n/2���� ũ��, �θ� �ڽĺ��� ���� ���� �ݺ�

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
	// 1. ���� ���� �����Ѵ�.
	// 2. ���γ���� ���� 
	//    2.1. ���� �ڽ� ��带 ã�´�.
	//    2.2. ������ �ڽİ� ���� �ڽ� �� ū ���� �ε����� ���Ѵ�.
	//    2.3. ū �ڽ��� ���� ���� ���� ��, 
	//         ���� ���� �ڽĺ��� ũ�ٸ� ���� Ż��
	//         ���� ���� �ڽĺ��� �۴ٸ� �ڽİ� ��ȯ
	//    2.4. ���� �ε����� �ڽ��� �ε����� ����
	// 3. ���� �ε��� ���� ������ ���� ����
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