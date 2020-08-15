#include <stdlib.h>
#include <stdio.h>

struct edge {
	int u, v;
	int w;
};

int n, m;
struct edge edges[124751];
int pi[501];

int cmp(const void * a, const void * b) {
	struct edge e1 = *((struct edge *)a);
	struct edge e2 = *((struct edge *)b);
	return e1.w - e2.w;
}

int leaf(int n) {
	if (pi[n] == n) {
		return n;
	}
	int aux = leaf(pi[n]);
	pi[n] = aux;
	return aux;
}

void merge(int a, int b) {
	pi[a] = b;
}

int kruskal() {
	qsort(edges, m, sizeof(struct edge), cmp);
	for (int i = 1; i <= n; i++) {
		pi[i] = i;
	}
	int lu, lv;
	int ans = 0;
	for (int i = 0; i < m; i++) {
		lu = leaf(edges[i].u);
		lv = leaf(edges[i].v);
		if (lu != lv) {
			ans+= edges[i].w;
			merge(lu, lv);
		}
	}
	return ans;
}

int main() {
	scanf("%d %d ", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d ", &edges[i].u, &edges[i].v, &edges[i].w);
	}
	printf("%d\n", kruskal());
	return 0;
}