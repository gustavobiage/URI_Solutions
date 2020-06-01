#include <stdlib.h>
#include <stdio.h>

int arr[100001];
long long int dp[100001];
long long int s;
long long int max;
int index;
int N;

long long int min(long long int a, long long int b) {
	if (a < b) {
		return a;
	}
	return b;
}

void binary_search(int begin, int end) {
	if (begin > end) {
		return;
	}

	int mid = begin + (end - begin)/2;
	long long int v1 = dp[mid];
	long long int v2 = dp[N-1] - v1;
	
	long long int m = min(v1, v2);

	if (m > max) {
		max = m;
		index = mid;
	}

	if (v1 > v2) {
		binary_search(begin, mid-1);
	} else {
		binary_search(mid+1, end);
	}
}

int main() {
	while (scanf("%d ", &N) != EOF) {
		s = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
			s += arr[i];
			dp[i] = s;
		}
		max = 0;
		index = -1;
		binary_search(0, N-1);
		long long int v1 = dp[index];
		long long int v2 = dp[N-1] - dp[index];
		printf("%Ld %Ld\n", min(v1, v2), v1 + v2 - min(v1, v2));
	}

}