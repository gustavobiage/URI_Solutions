#include <stdlib.h>
#include <stdio.h>

#define LLD long long int

struct edge {
	int a, b;
	int w;
};

struct edge edges[200001];
struct edge ans[200001];
int pointer;
int pi[200001];
int m, n;
LLD total;

int cmp(const void * a, const void * b) {
	struct edge e1 = *((struct edge*)a);
	struct edge e2 = *((struct edge*)b);
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

LLD kruskal() {
	qsort(edges, n, sizeof(struct edge), cmp);
	for (int i = 0; i < m; i++) {
		pi[i] = i;
	}
	LLD tree_weight = 0;
	pointer = 0;
	int la, lb;
	for (int i = 0; i < n && pointer < m-1; i++) {
		la = leaf(edges[i].a);
		lb = leaf(edges[i].b);
		if (la != lb) {
			merge(la, lb);
			ans[pointer++] = edges[i];
			tree_weight += edges[i].w;
		}
	}
	return tree_weight;
}

int main() {
	while (1) {
		scanf("%d %d ", &m, &n);
		if (!m && !n) {
			break;
		}
		total = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d ", &edges[i].a, &edges[i].b, &edges[i].w);
			total += edges[i].w;
		}
		printf("%Ld\n", total-kruskal());
	}
	return 0;
}