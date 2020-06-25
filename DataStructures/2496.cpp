#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <string.h>

int c;
char arr[50];
char sorted[50];
int N, M;

int cmp(const void * a, const void * b) {
	char c1 = *((char*)a);
	char c2 = *((char*)b);
	return c1 - c2;
}

int main() {
	scanf("%d ", &N);
	while (N) {
		scanf("%d ", &M);
		scanf("%s ", arr);
		strcpy(sorted, arr);
		qsort(sorted, M, sizeof(char), cmp);
		c = 0;
		for (int i = 0; i < M; i++) {
			if (sorted[i] != arr[i]) {
				c++;
			}
		}
		if (c == 2) {
			printf("There are the chance.\n");
		} else {
			printf("There aren't the chance.\n");
		}
		N--;
	}
	return 0;
}