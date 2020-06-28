#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

int filter(int n);

int N, T;
vector<int> adj[100001];
int f[100001];
int v;

bool cmp(int a, int b) {
	int v1 = filter(a);
	int v2 = filter(b);
	return v1 < v2;
}

int filter(int n) {
	if (f[n] != -1) {
		return f[n];
	}
	int c = 0;
	int len = adj[n].size();
	if (len) {
		sort(adj[n].begin(), adj[n].end(), cmp);
		for (int i = 0; i < len && (double) i / len * 100 < T; i++) {
			c += filter(adj[n][i]);
		}
		f[n] = c;
	} else {
		f[n] = 1;
	}
	return f[n];
}

int main() {

	while (1) {
		scanf("%d %d ", &N, &T);
		if (!N && !T) {
			break;
		}
		for (int i = 0; i <= N; i++) {
			adj[i].clear();
			f[i] = -1;
		}
		for (int i = 1; i <= N; i++) {
			scanf("%d ", &v);
			adj[v].push_back(i);
		}
		int ans = filter(0); 
		printf("%d\n", ans);
	}
	return 0;
}