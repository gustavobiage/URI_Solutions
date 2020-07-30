#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N, K;
char arr[101][100];

int cmp(const void * a, const void * b) {
	char * v1 = (char*)a;
	char * v2 = (char*)b;
	return strcmp(v1, v2);
}

int main() {
	scanf("%d %d ", &N, &K);
	for (int i = 0; i < N; i++) {
		scanf("%s ", arr[i]);
	}
	qsort(arr, N, sizeof(char)*100, cmp);
	printf("%s\n", arr[K-1]);
}
