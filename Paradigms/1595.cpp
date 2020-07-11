#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

int S, C, R;
int T;
int arr[100001];

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf("%d %d %d ", &S, &C, &R);
		for (int i = 0; i < S; i++) {
			scanf("%d ", &arr[i]);
		}
		std::sort(arr, arr + S);
		for (int i = 0; i < C; i++) {
			arr[i] += R;
		}
		long double time = 0;
		for (int i = 0; i < S; i++) {
			time += (long double) 1 / arr[i];
		}
		printf("%0.2Lf\n", time);
	}
	return 0;
}