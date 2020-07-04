#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N;
struct c {
	int cnt;
	int id;
};

struct c arr[4];
char a[4][100];
char b[100];

void clear(char * c) {
	int len = strlen(c);
	if (c[len-1] == '\n') {
		c[len-1] = '\0';
	}
}

int cmp(const void * a, const void * b) {
	struct c v1 = *((struct c*)a);
	struct c v2 = *((struct c*)b);
	return v2.cnt - v1.cnt;
}

int main() {
	scanf("%d ", &N);
	for (int i = 0; i < 4; i++) {
		arr[i].id = i+1;
	}
	while (N--) {
		scanf("%*s");
		scanf("%*c");
		for (int i = 0; i < 4; i++) {
			fgets(a[i], 100, stdin);
			clear(a[i]);
		}
		scanf("%*s");
		scanf("%*c");
		for (int i = 0; i < 4; i++) {
			fgets(b, 100, stdin);
			clear(b);
			if (strcmp(a[i], b)) {
				arr[i].cnt++;
			}
		}
	}
	qsort(arr, 4, sizeof(struct c), cmp);
	int last = -1;
	int i = 0;
	while (last == -1 || arr[i].cnt == last) {
		if (last == -1) {
			printf("%d", arr[i].id);
		} else {
			printf(" %d", arr[i].id);
		}
		last = arr[i].cnt;
		i++;
	}
	printf("\n");

	return 0;
}