#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include <set>
#include <math.h>

using namespace std;

int c;
int N;
int A, B;
set<pair<int, int> > s;

int cmp(int a, int b, int c, int d) {
	if (c <= b) {
		return 1;
	}
	return 0;
}

int main() {

	while (scanf("%d ", &N) != EOF) {
		s.clear();

		for (int i = 0; i < N; i++) {
			scanf("%d %d ", &A, &B);
			s.insert(make_pair(A, B));
		}

		int a, b;
		int u, v;
		c = 0;
		set<pair<int, int> >::iterator next;
		for (auto it = s.begin(); it != s.end(); ++it) {
			c++;
			a = it->first;
			b = it->second;
			AGAIN:
			it++;
			if (it == s.end()) {
				break;
			}
			u = it->first;
			v = it->second;
			if (cmp(a, b, u, v)) {
				// printf("%d %d %d %d\n", a, b, u, v);
				a = fmax(a, u);
				b = fmin(b, v);
				goto AGAIN;
			}
			--it;
		}
		printf("%d\n", c);
	}

	return 0;
}