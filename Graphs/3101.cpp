#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

struct node {
	int pi;
	int cnt;
};

int n, m;
int a, b;
int x, y;
struct node f[501];
char alive[501];
int ans[501];
int c;

int leaf(int n) {
	if (f[n].pi == n) {
		return n;
	}
	int aux = leaf(f[n].pi);
	f[n].pi = aux;
	return aux;
}

void merge(int a, int b) {
	int pa = leaf(a);
	int pb = leaf(b);
	if (pa != pb) {
		f[pa].pi = pb;
		f[pb].cnt += f[pa].cnt;
	}
}

int main() {
	scanf("%d %d ", &n, &m);
	for (int i = 1; i <= n; i++) {
		f[i].pi = i;
		f[i].cnt = 1;
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d ", &a, &b);
		merge(a, b);
	}
	memset(alive, 1, 501);
	scanf("%d ", &x);
	for (int i = 0; i < x; i++) {
		scanf("%d ", &y);
		if (alive[y]) {
			f[leaf(y)].cnt--;
			alive[y] = 0;
		}
	}

	c = 0;
	for (int i = 1; i <= n; i++) {
		if (f[i].pi == i && f[i].cnt) {
			ans[c++] = f[i].cnt;
		}
	}
	std::sort(ans, ans + c);
	printf("Quantidade de familias: %d\n", c);
	printf("Numero de habitantes em cada: ");
	for (int i = 0; i < c; i++) {
		if (i != c-1 && i != 0) {
			printf(", %d", ans[i]);
		} else if (i == 0) {
			printf("%d", ans[i]);
		} else {
			printf(" e %d", ans[i]);
		}
	}
	printf("\n");
	return 0;
}