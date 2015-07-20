
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) < (b) ? (a) : (b))
int maxSum1(int *a, int n) {
	int res = -1e5;
	for (int begin = 0; begin < n; ++begin) {
		int sum = 0;
		for (int end = begin; end < n; ++end) {
			sum += a[end];
			res = max(res, sum);
		}
	}
	return res;
}

int fastSum(int *a, int lo, int hi) {
	if (lo == hi) return a[lo];
	int mid = (lo + hi) / 2;
	int single = max(fastSum(a, lo, mid), fastSum(a, mid + 1, hi));
	int sum;
	int left = 0;
	sum = 0;
	for (int i = mid; i >= lo; --i) {
		sum += a[i];
		left = max(sum, left);
	}
	int right = 0;
	sum = 0;
	for (int i = mid+1; i <= hi; ++i) {
		sum += a[i];
		right = max(sum, right);
	}
	return max(left + right, single);
}
int maxSum2(int *a, int n) {
	return fastSum(a, 0, n);
}

int maxSum3(int *a, int n) {
	int *subsum = (int*)malloc(sizeof(int)*n);
	subsum[0] = a[0];
	for (int i = 1; i < n; ++i) {
		subsum[i] = subsum[i - 1] + a[i];
	}
	int maxvalue = -1e5, minvalue = 1e5;
	for (int i = 0; i < n; ++i) {
		maxvalue = max(maxvalue, subsum[i]);
		minvalue = min(minvalue, subsum[i]);
	}
	return maxvalue - minvalue;
}

int main() {
	int a[] = { 1, 4, -9, 2, 8, -1, 9, 3 };
	int n = sizeof(a) / sizeof(a[0]);
	printf("maxsum: %d\n", maxSum1(a, n));
	printf("maxsum: %d\n", maxSum2(a, n));
	printf("maxsum: %d\n", maxSum3(a, n));
	return 0;
}