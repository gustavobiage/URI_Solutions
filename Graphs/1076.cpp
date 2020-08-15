#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int t, n;
int v, a;

int adj[200][200];
int s[200];
char visited[200];

int cnt;

void dfs(int u) {
	visited[u] = 1;
	int v;
	for (int i = 0; i < s[u]; i++) {
		v = adj[u][i];
		if (!visited[v]) {
			cnt++;
			dfs(v);
			cnt++;
		}
	}
}

int main() {
	scanf("%d ", &t);
	while (t--) {
		scanf("%d ", &n);
		scanf("%d %d ", &v, &a);
		memset(s, 0, sizeof(int)*200);
		int u, v;
		for (int i = 0; i < a; i++) {
			scanf("%d %d ", &u, &v);
			adj[u][s[u]++] = v;
			adj[v][s[v]++] = u;
		}
		memset(visited, 0, 200);
		cnt = 0;
		dfs(n);
		printf("%d\n", cnt);
	}
	return 0;
}