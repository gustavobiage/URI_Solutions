#include <stdlib.h>
#include <stdio.h>
#include <map>

using namespace std;

int T;
int N, M;
int v;
map<int, int> m;
int max_, ans;

int main() {
	scanf("%d ", &T);
	while (T) {
		scanf("%d %d ", &N, &M);
		m.clear();
		for (int i = 0; i < M; i++) {
			scanf("%d ", &v);
			m[v]++;
		}
		max_ = 0;
		ans = -1;
		for (auto it = m.begin(); it != m.end(); ++it) {
			if (it->second > max_ && it->second > M/2) {
				max_ = it->second;
				ans = it->first;
			}
		}
		printf("%d\n", ans);
		T--;
	}
	return 0;
}