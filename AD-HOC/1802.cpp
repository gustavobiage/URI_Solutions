#include <stdlib.h>
#include <stdio.h>

int p[6];
int arr[10][10];
int ans[10000000];
int pointer;
int s, k;

int cmp(const void *a, const void *b) {
	int v1 = *((int*)a);
	int v2 = *((int*)b);
	return v2 - v1;
}

void search(int index, int sum) {
	if (index == 5) {
		ans[pointer++] = sum;
		return;
	}
	for (int i = 0; i < p[index]; i++) {
		search(index+1, sum+arr[index][i]);
	}
}

int main() {
	for (int i = 0; i < 5; i++) {
		scanf("%d ", &p[i]);
		for (int j = 0; j < p[i]; j++) {
			scanf("%d ", &arr[i][j]);
		}
	}
	pointer = 0;
	search(0, 0);
	qsort(ans, pointer, sizeof(int), cmp);
	scanf("%d ", &k);
	s = 0;
	for (int i = 0; i < k; i++) {
		s += ans[i];
	}
	printf("%d\n", s);
	return 0;
}