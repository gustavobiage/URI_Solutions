#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <set>
#include <string>
#include <utility>

// Submited with C++, not C++17
int N, M;
int n;
char id[40];
std::map<std::string, std::set<int> > m;
std::set<int> empty;
std::set<std::pair<int, int> > res;
std::set<int> * aux;

int main() {

	while (1) {
		scanf("%d %d ", &N, &M);
		if (N == 0 && M == 0) {
			break;
		}
		m.clear();
		res.clear();

		for (int i = 0; i < N; i++) {
			scanf("%d ", &n);
			for (int j = 0; j < n; j++) {
				scanf(" %s ", id);
				if (m.find(id) == m.end()) {
					m[id] = empty;
				}
				m[id].insert(i);
			}
		}

		for (int i = 0; i < M; i++) {
			scanf("%d ", &n);
			for (int j = 0; j < n; j++) {
				scanf(" %s ", id);
				aux = &m[id];
				for (auto it = aux->begin(); it != aux->end(); ++it) {
					res.insert(std::make_pair(i, *it));
				}
			}
		}
		printf("%d\n", (int)res.size());
	}
	return 0;
}