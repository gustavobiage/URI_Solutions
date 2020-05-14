#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <set>

using namespace std;

set<int> s[10001];
int T, N, Q, M;
int op, X, Y;
int v;

void s_instersect(set<int> * v1, set<int> * v2) {
	int c = 0;
	auto p1 = v1->begin(), p2 = v2->begin();
	while (p1 != v1->end() && p2 != v2->end()) {
		if (*p1 > *p2) {
			++p2;
		} else if (*p1 < * p2) {
			++p1;
		} else {
			c++;
			++p1;
			++p2;
		}
	}
	printf("%d\n", c);
}

void s_union(set<int> * v1, set<int> * v2) {
	int c = 0;
	auto p1 = v1->begin(), p2 = v2->begin();
	while (p1 != v1->end() && p2 != v2->end()) {
		if (*p1 > *p2) {
			c++;
			++p2;
		} else if (*p1 < * p2) {
			c++;
			++p1;
		} else {
			c++;
			++p1;
			++p2;
		}
	}

	while (p1 != v1->end()) {
		c++;
		++p1;
	}

	while (p2 != v2->end()) {
		c++;
		++p2;	
	}
	
	printf("%d\n", c);
}

int main() {

	scanf("%d ", &T);

	while (T) {

		scanf("%d ", &N);
		for (int i = 1; i <= N; i++) {
			scanf("%d ", &M);
			s[i].clear();
			for (int j = 0; j < M; j++) {
				scanf("%d ", &v);
				s[i].insert(v);
			}
		}

		scanf("%d ", &Q);
		for (int i = 0; i < Q; i++) {
			scanf("%d %d %d ", &op, &X, &Y);
			// printf("%d %d %d\n", op, X, Y);
			if (op == 1) {
				s_instersect(&s[X], &s[Y]);
			} else if (op == 2) {
				s_union(&s[X], &s[Y]);
			}
		}

		T--;
	}

	return 0;
}