#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;

set<int> s;
int N, B, v;

int find(int n) {
	for (auto it = s.begin(); it != s.end(); ++it) {
		if (s.find(*it + n) != s.end() ||
			s.find(*it - n) != s.end()) {
			return 1;
		}
	}
	return 0;
}

int main() {

	while (1) {
		scanf("%d %d ", &N, &B);
		if (!N && !B) {
			break;
		}

		s.clear();
		for (int i = 0; i < B; i++) {
			scanf("%d ", &v);
			s.insert(v);
		}

		for (int i = 0; i <= N; i++) {
			if (!find(i)) {
				printf("N\n");
				goto CONTINUE;
			}
		}

		if (0) {
			CONTINUE:;
			continue;
		}

		printf("Y\n");
	}
	return 0;
}