#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;

set<int> s;
int E, Q, v;

int main() {

	scanf("%d %d ", &Q, &E);

	for (int i = 0; i < E; i++) {
		scanf("%d ", &v);
		s.insert(v);
	}

	for (int i = 0; i < Q; i++) {
		scanf("%d ", &v);
		if (s.find(v) != s.end()) {
			printf("0\n");
		} else {
			s.insert(v);
			printf("1\n");
		}
	}

	return 0;
}