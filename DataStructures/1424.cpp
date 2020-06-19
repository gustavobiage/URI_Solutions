#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

int N, M;
map<int, vector<int> > m;
vector<int> empty_;
int k, v;

int main() {
	while (scanf("%d %d ", &N, &M) != EOF) {
		m.clear();
		for (int i = 0; i < N; i++) {
			scanf("%d ", &v);
			if (m.find(v) == m.end()) {
				m[v] = empty_;
			}
			m[v].push_back(i+1);
		}

		for (int i = 0; i < M; i++) {
			scanf("%d %d ", &k, &v);
			if (m.find(v) != m.end()) {
				vector<int> *p = &m[v];
				if (p->size() >= k) {
					printf("%d\n", (*p)[k-1]);
				} else {
					printf("0\n");
				}
			} else {
				printf("0\n");
			}
		}
	}

	return 0;
}