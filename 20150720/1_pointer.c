#include <stdio.h>

int main() {
	int b[3][4] = { 0, };
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j) {
			b[i][j] = j;
		}
	}
	int(*p3)[4] = b;
	p3[0][0] = 10;
	p3[2][0] = 3;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 4; ++j)
			printf("%d ", p3[i][j]);
		printf("\n");
	}
}