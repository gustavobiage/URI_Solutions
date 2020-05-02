#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <set>

using namespace std;

map<int, int> D;
map<int, int> E;
set<int> s;
int N, v;
char c;

int main() {

	while (scanf("%d ", &N) != EOF) {
		s.clear();
		D.clear();
		E.clear();

		for (int i = 0; i < N; i++) {
			scanf("%d %c ", &v, &c);
			if (c == 'E') {
				E[v]++;
			} else if (c == 'D') {
				D[v]++;
			}
			s.insert(v);
		}

		int count = 0;
		for (auto it = s.begin(); it != s.end(); ++it) {
			v = *it;
			count += min(D[v], E[v]);
		}

		printf("%d\n", count);
	}
	return 0;
}