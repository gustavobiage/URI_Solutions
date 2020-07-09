#include <stdlib.h>
#include <stdio.h>

int N, T;
int DP[10005];
int arr[10005];
int A, B;

int abs(int a) {
	if (a < 0) {
		return -a;
	}
	return a;
}

int search(int index) {
	if (abs(A-B) > 5) {
		return 0;
	}
	
	if (index == N) {
		return 1;
	}

	A += arr[index];
	if (search(index+1)) {
		return 1;
	}
	A -= arr[index];
	B += arr[index];
	if (search(index+1)) {
		return 1;
	}
	B -= arr[index];
	return 0;
}

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf("%d ", &N);
		A = B = 0;
		DP[0] = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
		}
		for (int i = N-1; i >= 0; i--) {
			DP[i] = DP[i+1] + arr[i];
		}

		if (search(0)) {
			printf("Feliz Natal!\n");
		} else {
			printf("Ho Ho Ho!\n");
		}
	}
	return 0;
}