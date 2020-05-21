#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;

int T;
int N, v;
set<int> s;
int main() {

	scanf("%d ", &T);
	while (T) {

		scanf("%d ", &N);
		s.clear();
		for (int i = 0; i < N; i++) {
			scanf("%d ", &v);
			s.insert(v);
		}

		printf("%d\n", (int)s.size());
		T--;
	}
	return 0;
}