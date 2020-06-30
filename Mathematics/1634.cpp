#include <stdlib.h>
#include <stdio.h>

int N, M;
int sum;
int arr[10000];

int euclides(int a, int b) {
	if (a < b) {
		return euclides(b, a);
	}
	if (!b) {
		return a;
	}
	return euclides(b, a % b);
}

int main() {
	while (1) {
		scanf("%d %d ", &N, &M);
		if (!N && !M) {
			break;
		}
		sum = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M-1; j++) {
				scanf("%*d ");
			}
			scanf("%d ", &arr[i]);
			sum += arr[i];
		}
		for (int i = 0; i < N; i++) {
			int v = euclides(arr[i], sum);
			printf("%d / %d\n", arr[i]/v, sum/v);
		}
	}
	return 0;
}