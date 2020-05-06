#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <string>

using namespace std;

set<string> s;
int N;
char w[1003];

int main() {
	scanf("%d ", &N);

	for (int i = 0; i < N; i++) {
		scanf(" %s ", w);
		s.insert(w);
	}

	printf("Falta(m) %d pomekon(s).\n", 151 - (int)s.size());
	return 0;
}