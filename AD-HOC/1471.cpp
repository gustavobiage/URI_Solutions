#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;

set<int> s;
int v, N, R;

int main() {

	while (scanf("%d %d ", &N, &R) != EOF) {
		s.clear();
		for (int i = 1; i <= N; i++) {
			s.insert(i);
		}

		for (int i = 0; i < R; i++) {
			scanf("%d ", &v);
			s.erase(v);
		}
		
		if (R == N) {
			printf("*");
		}

		for (auto it = s.begin(); it != s.end(); ++it) {
				printf("%d ", *it);
		}
		printf("\n");
	}

	return 0;
}