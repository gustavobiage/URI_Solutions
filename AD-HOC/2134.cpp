#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct al {
	int val;
	char name[50];
};

struct al arr[102];
int N, c;

int cmp(const void * a, const void * b) {
	struct al * v1 = (struct al *) a;
	struct al * v2 = (struct al *) b;
	if (v1->val != v2->val) {
		return v1->val - v2->val;
	}
	return -strcmp(v1->name, v2->name);
}

int main() {
	c = 0;
	while (scanf("%d ", &N) != EOF) {
		c++;
		for (int i = 0; i < N; i++) {
			scanf(" %s %d ", arr[i].name, &arr[i].val);
		}

		qsort(arr, N, sizeof(struct al), cmp);

		printf("Instancia %d\n", c);
		printf("%s\n", arr[0].name);
		printf("\n");
	}
	return 0;
}