#include <stdlib.h>
#include <stdio.h>

struct node {
	int id;
	int x;
};

int n, m, q;
int w, k, a, b;
int op;
struct node group[100001];
int groupCnt[100001][101];

int getLeaf(int id) {
	if (group[id].id == id) {
		return id;
	}
	int aux = getLeaf(group[id].id);
	group[id].id = aux;
	return aux;
}

void merge(int a, int b) {
	int na = getLeaf(a);
	int nb = getLeaf(b);
	if (na != nb) {
		group[na].id = nb;
	}
}

void update(int index, int x, int delta) {
	for (; x <= 100; x+=x&-x) {
		groupCnt[index][x] += delta;
	}
}

int get(int index, int x) {
	int ans = 0;
	for (; x; x-=x&-x) {
		ans += groupCnt[index][x];
	}
	return ans;
}

int main() {
	scanf("%d ", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d ", &group[i].x);
		group[i].id = i;
	}
	scanf("%d ", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d ", &a, &b);
		merge(a, b);
	}
	for (int i = 1; i <= n; i++) {
		update(getLeaf(i), group[i].x, 1);
	}
	scanf("%d ", &q);
	for (int i = 0; i < q; i++) {
		scanf("%d ", &op);
		if (op == 1) {
			scanf("%d ", &w);
			printf("%d\n", get(getLeaf(w), group[w].x-1));
		} else if (op == 2) {
			scanf("%d %d ", &w, &k);
			int l = getLeaf(w);
			update(l, k, 1);
			update(l, group[w].x, -1);
			group[w].x = k;
		}
	}
	return 0;
}