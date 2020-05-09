#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <utility>

using namespace std;

int N, H, D;

set<pair<int, int> > s;

int main() {

	scanf("%d ", &N);

	for (int i = 0; i < N; i++) {
	scanf("%d %d ", &H, &D);
		s.insert(make_pair(H, H + D));
	}
	int a, b;
	int time = -1;
	int c = 0;
	for (auto it = s.begin(); it != s.end(); ++it) {
		a = it->first;
		b = it->second;
		if (a >= time) {
			time = b;
			c++;
		} else if (b < time) {
			time = b;
		}
	}

	printf("%d\n", c);
	return 0;
}