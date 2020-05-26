#include <stdlib.h>
#include <stdio.h>

int A, V;

struct aer{
	int from;
	int to;
	int id;
};

struct aer arr[101];
int a, b;

int cmp(const void * a, const void * b) {
	int v1 = ((struct aer*)a)->from + ((struct aer*)a)->to; 
	int v2 = ((struct aer*)b)->from + ((struct aer*)b)->to; 
	if (v1 != v2) {
		return v2 - v1;
	}
	return ((struct aer*)a)->id - ((struct aer*)b)->id;
}

int main() {
	int c = 0;
	while (1) {
		scanf("%d %d ", &A, &V);
		if (!A && !V) {
			break;
		}
		c++;
		for (int i = 1; i <= A; i++) {
			arr[i].from = 0;
			arr[i].to = 0;
			arr[i].id = i;
		}

		for (int i = 0; i < V; i++) {
			scanf("%d %d ", &a, &b);
			arr[a].from += 1;
			arr[b].to += 1;
		}

		qsort(&arr[1], A, sizeof(struct aer), cmp);
		
		printf("Teste %d\n", c);
		int amount = arr[1].from + arr[1].to;
		for (int i = 1; i <= A && arr[i].from + arr[i].to == amount; i++) {
			printf("%d ", arr[i].id);
		}
		printf("\n\n");
	}
	return 0;
}