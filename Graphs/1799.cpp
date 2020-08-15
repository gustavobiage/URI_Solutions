#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <queue>
#include <utility>

using namespace std;

int p, l;
int visited[4001];
int adj[4001][4001];
int pointer;
map<string, int> map_;
char n1[1000], n2[1000];
int ans;
int si[4001];

int getNodeId(const char * name) {
	if (map_.find(name) == map_.end()) {
		map_[name] = pointer++;
	}
	return map_[name];
}

int bfs(int s, int f) {
	memset(visited, 0, sizeof(int)*4001);
	queue<pair<int, int>> q;
	visited[s] = 1;
	q.push(make_pair(s, 1));
	int u, v, w;
	while (!q.empty()) {
		u = q.front().first;
		w = q.front().second;
		q.pop();
		for (int i = 0; i < si[u]; i++) {
			v = adj[u][i];
			if (!visited[v]) {
				visited[v] = w+1;
				q.push(make_pair(v, w+1));
			}
		}
	}
	return visited[f]-1;
}

int main() {
	scanf("%d %d ", &p, &l);
	pointer = 0;
	int u, v;
	for (int i = 0; i < l; i++) {
		scanf("%s %s ", n1, n2);
		u = getNodeId(n1);
		v = getNodeId(n2);
		adj[v][si[v]++] = u;
		adj[u][si[u]++] = v;
	}
	ans = bfs(getNodeId("Entrada"), getNodeId("*"));
	ans += bfs(getNodeId("*"), getNodeId("Saida"));
	printf("%d\n", ans);
	return 0;
}