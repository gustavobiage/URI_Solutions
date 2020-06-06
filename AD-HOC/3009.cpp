#include <stdlib.h>
#include <stdio.h>
#include <set>

int C;
int N, M;
int a, b;

int adj[1001][1001];
int size[1001];

int DP[1001];
std::set<int> s[1001];

void bfs(int u, std::set<int> * pointer) {
	if (DP[u] != -1) {
		for (auto it = s[u].begin(); it != s[u].end(); ++it) {
			pointer->insert(*it);
		}
		return;
	}

	int v;
	pointer->insert(u);
	for (int i = 0; i < size[u]; i++) {
		v = adj[u][i];
		if (pointer->find(v) == pointer->end()) {
			bfs(v, pointer);
		}
	}
}

int main() {
	int res;
	scanf("%d ", &C);
	while (C) {
		scanf("%d %d ", &N, &M);
		
		for (int i = 1; i <= N; i++) {
			DP[i] = -1;
			size[i] = 0;
			s[i].clear();
		}

		for (int i = 0; i < M; i++) {
			scanf("%d %d ", &a, &b);
			adj[a][size[a]++] = b;
		}

		res = 0;
		for (int i = 1; i <= N; i++) {
			bfs(i, &s[i]);
			DP[i] = s[i].size();
			if (DP[i] == N) {
				res = 1;
				break;
			}
		}

		if (res) {
			printf("S\n");
		} else {
			printf("N\n");
		}
		C--;
	}
}