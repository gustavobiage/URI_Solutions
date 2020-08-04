#include <stdlib.h>
#include <stdio.h>
#include <string.h>

long long int arr[100001];
int DP_foward[100001];
int DP_backward[100001];
int N;
long long int global_max;

int searchf(int h, int i) {
	if (i == N || arr[i] < h) {
		return 0;
	}
	if (DP_foward[i] != 0) {
		return DP_foward[i] + searchf(h, i+DP_foward[i]);
	}
	DP_foward[i] = 1 + searchf(h, i+1);
	return DP_foward[i];
}

int searchb(int h, int i) {
	if (i < 0 || arr[i] < h) {
		return 0;
	}
	if (DP_backward[i] != 0) {
		return DP_backward[i] + searchb(h, i-DP_backward[i]);
	}
	DP_backward[i] = 1 + searchb(h, i-1);
	return DP_backward[i];
}

void find() {
	for (int i = N-1; i >= 0; i--) {
		searchf(arr[i], i);
	}
	for (int i = 0; i < N; i++) {
		searchb(arr[i], i);
	}
}

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		for (int i = 0; i < N; i++) {
			scanf("%Ld ", &arr[i]);
		}
		memset(DP_foward, 0, sizeof(int)*N);
		memset(DP_backward, 0, sizeof(int)*N);
		find();
		global_max = -1;
		for (int i = 0; i < N; i++) {
			if ((DP_foward[i] + DP_backward[i] - 1) * arr[i] > global_max) {
				global_max = (DP_foward[i] + DP_backward[i] - 1) * arr[i];
			}
		}
		printf("%Ld\n", global_max);
	}
	return 0;
}