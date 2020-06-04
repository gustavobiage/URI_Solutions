#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int N;

int binary_search(int begin, int end, int base) {
	if (begin > end) {
		return -1;
	}

	int mid = begin + (end - begin) / 2;
	int value = mid*mid;
	if (value > N - base) {
		return binary_search(begin, mid-1, base);
	} else if (value < N - base) {
		return binary_search(mid+1, end, base);
	}
	return mid;
}

int main() {
	int j, res;
	while (scanf("%d ", &N) != EOF) {
		res = 0;
		for (int i = 0; i*i <= N; i++) {
			j = binary_search(0, N-(i*i), i*i);
			if (j != -1) {
				res = 1;
				break;
			}
		}

		if (res) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}

	return 0;
}