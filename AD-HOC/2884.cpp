#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <set>

using namespace std;

int N, M, L, K;

int map[1002][1002];
int indices[1002];
vector<int> on;
int c, iterations, pos, v;

set<vector<int> > s;

int main() {

	scanf("%d %d ", &N, &M);
	scanf("%d ", &L);

	for (int i = 0; i <= M; i++) {
		on.push_back(0);
	}

	for (int i = 0; i < N; i++) {
		indices[i] = 0;
	}
	
	c = L;
	for (int i = 0; i < L; i++) {
		scanf("%d ", &v);
		on[v] = 1;
	}

	for (int i = 0; i < N; i++) {
		scanf("%d ", &K);
		for (int j = 0; j < K; j++) {
			scanf("%d ", &v);
			map[i][indices[i]++] = v;
		}
	}

	pos = 0;
	iterations = 0;
	
	while (c > 0) {
		on[0] = pos;
		iterations++;
		for (int i = 0; i < indices[pos]; i++) {
			v = map[pos][i];
			if (on[v] == 1) {
				on[v] = 0;
				c--;
			} else if (on[v] == 0) {
				on[v] = 1;
				c++;
			}
		}

		if (s.find(on) != s.end()) {
			goto END;
		}
		s.insert(on);
		pos = (pos + 1) % N;
	}

	if (0) {
		END:
		printf("-1\n");
	} else {
		printf("%d\n", iterations);
	}

	return 0;
}