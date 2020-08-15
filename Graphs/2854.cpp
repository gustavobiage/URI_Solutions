#include <stdlib.h>
#include <stdio.h>
#include <map>

using namespace std;

int m, n;
map<string, int> map_;
int pointer = 0;
char n1[1000], n2[1000];
int ans;
int pi[301];

int getNodeId(const char * n) {
	if (map_.find(n) == map_.end()) {
		map_[n] = pointer++;
	}
	return map_[n];
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
	int la = leaf(a);
	int lb = leaf(b);
	if (la != lb) {
		pi[la] = lb;
	}
}

int main() {
	scanf("%d %d ", &m, &n);
	for (int i = 0; i < m; i++) {
		pi[i] = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%s %*s %s ", n1, n2);
		merge(getNodeId(n1), getNodeId(n2));
	}
	for (int i = 0; i < m; i++) {
		if (pi[i] == i) {
			ans++;
		}
	}
	printf("%d\n", ans);
	return 0;
}