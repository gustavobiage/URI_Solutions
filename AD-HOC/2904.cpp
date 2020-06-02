#include <stdlib.h>
#include <stdio.h>

#define LLU long long unsigned int
#define INF  200000

int N;
int arr[100001];
LLU s;
LLU dp[100001];

int binary_search(int begin, int end, int i, int value) {
	if (begin > end) {
		return INF;
	}

	int mid = begin + (end - begin) / 2;
	int v = dp[mid] - dp[i];
	if (v > value) {
		return binary_search(begin, mid-1, i, value);
	} else if (v < value) {
		return binary_search(mid+1, end, i, value);
	}
	return mid;
}

int binary_search_half(int begin, int end, int i) {
	if (begin > end) {
		return INF;
	}

	int mid = begin + (end - begin) / 2;
	LLU v1 = dp[mid] - dp[i];
	LLU v2 = s - dp[mid] + dp[i];
	if (v1 > v2) {
		return binary_search_half(begin, mid-1, i);
	} else if (v2 > v1) {
		return binary_search_half(mid+1, end, i);
	}
	return mid;
}


int main() {
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d ", &arr[i]);
		s += arr[i];
		dp[i] = s;
	}
	int res = 0;
	LLU v;
	if (!(s & 1)) {
		for (int i = 0; i < N; i++) {
			int j = binary_search_half(i+1, N-1, i);
			if (j != INF) {
				for (int k = j+1; k != i; k = (k + 1) % N) {
					if (k > j) {
						v = dp[k] - dp[j];
					} else {
						v = s - dp[j] + dp[k];
					}

					int m = binary_search(i+1, j, i, v);
					if (m != INF) {
						res = 1;
						goto PRT;
					}
				}
			}
		}
	}
	PRT:;
	if (res) {
		printf("Y\n");
	} else {
		printf("N\n");
	}
	return 0;
}