#include <stdio.h>

int cmp(const void* a, const void* b) {
	return *(int*)a < *(int*)b ? 1 : -1;
}

int main() {
	int n, i, price, total, coin[100], change, num[100] = { 0 };
	scanf("%d", &n);
	for (i = 0; i < n; ++i) {
		scanf("%d", &coin[i]);
	}
	scanf("%d %d", &price, &total);
	qsort(coin, n, sizeof(coin[0]), cmp);
	change = total - price;
	i = 0;
	while (change > 0) {
		num[i] = change / coin[i];
		change -= num[i] * coin[i];
		i++;
	}
	printf("change: %d\n", total - price);
	for (i = 0; i < n; ++i) {
		printf("%d ", num[i]);
	}
	printf("\n");
}