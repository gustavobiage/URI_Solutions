#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <utility>
#include <vector>
#include <string.h>

using namespace std;

int N;
int a, b, c;
vector<int> adj[100001];
vector<int> W[100001];
int ans[100001];
char visited[100001];

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

void bfs(int s) {
	memset(visited, 0, 100001);
	visited[s] = 1;
	queue<pair<int, int> > q;
	q.push(make_pair(s, 1000000000));
	pair<int, int> p;
	while (!q.empty()) {
		p = q.front();
		q.pop();
		int u = p.first;
		int w = p.second;
		int v; 
		for (int i = 0; i < adj[u].size(); i++) {
			v = adj[u][i];
			if (!visited[v]) {
				int newW = W[u][i];
				visited[u] = 1;
				ans[v] = min(w, newW);
				q.push(make_pair(v, ans[v]));
			}
		}
	}
}

int main() {

	scanf("%d ", &N);
	for (int i = 0; i < N-1; i++) {
		scanf("%d %d %d ", &a, &b, &c);
		adj[a].push_back(b);
		W[a].push_back(c);
		adj[b].push_back(a);
		W[b].push_back(c);
	}

	bfs(N);

	for (int i = 1; i < N; i++) {
		if (i == 1) {
			printf("%d", ans[i]);
		} else {
			printf(" %d", ans[i]);
		}
	}
	printf("\n");
	return 0;
}