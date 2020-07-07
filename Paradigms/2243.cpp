#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int N;
int arr[50001];
int DP_foward[50002];
int DP_backward[50002];
int max;
int aux;

int main() {
	scanf("%d ", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d ", &arr[i]);
	}
	DP_foward[0] = 0;
	for (int i = 1; i <= N; i++) {
		int h = DP_foward[i-1];
		if (arr[i] > h) {
			DP_foward[i] = h + 1;
		} else {
			DP_foward[i] = arr[i];
		}
	}
	DP_backward[N+1] = 0;
	for (int i = N; i >= 0; i--) {
		int h = DP_backward[i+1];
		if (arr[i] > h) {
			DP_backward[i] = h + 1;
		} else {
			DP_backward[i] = arr[i];
		}
	}

	for (int i = 1; i <= N; i++) {
		aux = fmin(DP_foward[i], DP_backward[i]);
		if (aux > max) {
			max = aux;
		}
	}
	printf("%d\n", max);
	return 0;
}