#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;

int N;
int v;
set<int> s;

int main() {
	scanf("%d ", &N);
	while (N--) {
		scanf("%d ", &v);
		s.insert(v);
	}
	printf("%d\n", (int) s.size());
	return 0;
}