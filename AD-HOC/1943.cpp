#include <stdlib.h>
#include <stdio.h>

int arr[] = {0, 1, 3, 5, 10, 25, 50, 100};
int K;

int main() {
	scanf("%d ", &K);
	for (int i = 7; i > 0; i--) {
		if (arr[i] >= K && arr[i-1] < K) {
			printf("Top %d\n", arr[i]);
			break;
		}
	}
	return 0;
}