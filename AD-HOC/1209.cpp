#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <set>

// Submited with C++, not C++17

std::map<int, std::vector<int> > m;
std::vector<int> empty;
std::set<int> inside;

struct node * head;
int N, M, K;
int counter[1004];
int a, b;

int main() {
	int f;
	while (scanf("%d %d %d ", &N, &M, &K) != EOF) {
		m.clear();
		inside.clear();
		for (int i = 1; i <= N; i++) {
			m[i] = empty;
			inside.insert(i);
			counter[i] = 0;
		}

		for (int i = 0; i < M; i++) {
			scanf("%d %d ", &a, &b);
			counter[a]++;
			counter[b]++;
			m[a].push_back(b);
			m[b].push_back(a);
		}

		int changed = 1;
		std::vector<int> * vec;

		
		while (changed) {
			changed = 0;
			int u, v;
			for (auto it = inside.begin(); it != inside.end(); ++it) {
				u = *it;
				if (counter[u] < K) {
					changed = 1;
					vec = &m[u];
					for (int i = 0; i < vec->size(); i++) {
						counter[(*vec)[i]]--;
					}
					inside.erase(it);
				}
			}
		}

		f = 1;
		for (auto it = inside.begin(); it != inside.end(); ++it) {
			if (f) {
				printf("%d", *it);
				f = 0;
			} else {
				printf(" %d", *it);
			}
		}

		if (inside.size() == 0) {
			printf("0");
		}

		printf("\n");
	}

	return 0;
}