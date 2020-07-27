#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;

int N;
set<int> s;
int v, ans;
int last;

int main() {
	scanf("%d ", &N);
	ans = 1;
	for (int i = 0; i < N; i++) {
		scanf("%d ", &v);
		if (v <= 8) {
			s.insert(v);
		} else {
			auto it = s.lower_bound(v-8);
			if (it == s.end()) {
				ans = 0;
				break;
			} else if (*it <= v+8) {
				s.insert(v);
				last = *it;
			} else {
				ans = 0;
				break;
			}
		}
	}
	while (last != -1 && ans) {
		auto it = s.lower_bound(last-8);
		if (it == s.end()) {
			ans = 0;
		} else if (*it <= 8) {
			last = -1;
		} else if (*it < last) {
			last = *it;
		} else {
			ans = 0;
		}
	}
	if (ans) {
		printf("S\n");
	} else {
		printf("N\n");
	}
	return 0;
}