#include <stdlib.h>
#include <stdio.h>

struct item {
	char name[109];
	int v;
};

int cmp(const void * a, const void * b) {
	struct item i1 = *((struct item*)a);
	struct item i2 = *((struct item*)b);
	return i2.v - i1.v;
}

char toLower(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 'a';
	}
	return c;
}

struct item arr[102];
char used[30];
int n, d;
int pointer;

int main() {
	scanf("%d %d ", &n, &d);
	for (int i = 0; i < n; i++) {
		fgets(arr[i].name, 109, stdin);
		arr[i].v = 0;
		for (int j = 0; arr[i].name[j] != '\0'; j++) {
			char c = arr[i].name[j];
			if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
				arr[i].v++;
			}
		}
	}
	qsort(arr, n, sizeof(struct item), cmp);
	pointer = 0;
	int ans = 0;
	while (d && pointer < n) {
		if (!used[toLower(arr[pointer].name[0]) - 'a']) {
			used[toLower(arr[pointer].name[0]) - 'a'] = 1;
			ans += arr[pointer].v;
			d--;
		}
		pointer++;
	}
	printf("%d\n", ans);
	return 0;
}