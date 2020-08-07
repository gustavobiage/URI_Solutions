#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <utility>

using namespace std;

int N;
int A[201], B[201];
long long int a, b;
set<pair<int, int> > s;

int min(int a, int b) {
	if (a < b) {
		return a;
	}
	return b;
}

int euclides(int a, int b) {
	if (b > a) {
		return euclides(b, a);
	}
	if (!b) {
		return a;
	}
	return euclides(b, a%b);
}

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		s.clear();
		for (int i = 0; i < N; i++) {
			scanf("%d ", &A[i]);
		}
		for (int i = 0; i < N; i++) {
			scanf("%d ", &B[i]);
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				a = A[i];
				b = B[j];
				if (s.find(make_pair(a, b)) == s.end()) {
					if (euclides(a, b) == 1) {
						s.insert(make_pair(b, a));
						s.insert(make_pair(a, b));
					}
				}
			}
		}
		printf("%d\n", (int)s.size());
	}
	return 0;
}