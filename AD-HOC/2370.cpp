#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N, M;
struct p {
	char name[100];
	int n;
};

int cmp(const void * a, const void * b) {
	struct p v1 = *((struct p*)a);
	struct p v2 = *((struct p*)b);
	return v2.n - v1.n;
}

int cmp_name(const void * a, const void * b) {
	struct p v1 = *((struct p*)a);
	struct p v2 = *((struct p*)b);
	return strcmp(v1.name, v2.name);
}

struct p t[1000][5000];
int size[1000];
struct  p arr[10000];

int main() {
	scanf("%d %d ", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf(" %s %d ", arr[i].name, &arr[i].n);
	}
	
	for (int i = 0; i < M; i++) {
		size[i] = 0;
	}

	qsort(arr, N, sizeof(struct p), cmp);

	int pointer = 0;
	for (int i = 0; i < N; i++) {
		t[pointer][size[pointer]++] = arr[i];
		pointer = (pointer + 1) % M;
	}

	for (int i = 0; i < M; i++) {
		qsort(t[i], size[i], sizeof(struct p), cmp_name);
		printf("Time %d\n", i+1);
		for (int j = 0; j < size[i]; j++) {
			printf("%s\n", t[i][j].name);
		}
		printf("\n");
	}
	return 0;
}