#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;

set<int> s;
int N, v;

int main() {
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		s.insert(i+1);
	}

	for (int i = 0; i < N - 1; i ++) {
		scanf("%d ", &v);
		s.erase(v);
	}

	printf("%d\n", *s.begin());
	return 0;
}