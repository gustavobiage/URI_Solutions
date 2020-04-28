#include <stdlib.h>
#include <stdio.h>

int N;
int arr[100];
int K;

int search(int index) {
	if (arr[index-1] == index) {
		return index;
	}
	return search(arr[index-1]);
}

int main() {

	while (1) {
		scanf("%d ", &N);
		if (N == 0) {
			break;
		}

		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
		}

		scanf("%d ", &K);
		printf("%d\n", search(K));
	}
	return 0;
}