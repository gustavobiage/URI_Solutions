#include <stdlib.h>
#include <stdio.h>

int N, K;
int arr[1001];
int cnt;

int main() {
	scanf("%d %d ", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%d ", &arr[i]);
	}
	cnt = 0;
	for (int i = 1; i < N-1; i++) {
		if (arr[i] > arr[i-1] && arr[i] > arr[i+1]) {
			cnt++;
		}
	}
	if (cnt == K) {
		printf("beautiful\n");
	} else {
		printf("ugly\n");
	}
	return 0;
}