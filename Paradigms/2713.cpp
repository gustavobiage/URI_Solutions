#include <stdlib.h>
#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

struct s {
	int x, v, d;
};

struct cmp {
	bool operator()(const struct s& s1, const struct s& s2) {
        long double v1 = (long double)s1.x/s1.v - (long double)s1.x/(s1.v+s1.d);
		long double v2 = (long double)s2.x/s2.v - (long double)s2.x/(s2.v+s2.d);
		if (abs(v1-v2) < 0.000000001) {
			return 0;
		} else {
			return v1 < v2;
		}
    }
};

int N, K, V;
priority_queue<struct s, vector<struct s>, struct cmp> pq;
long double time;
struct s s;

int main() {
	while (scanf("%d %d %d ", &N, &K, &V) != EOF) {
		time = 0;

		for (int i = 0; i < N; i++) {
			scanf("%d %d ", &s.x, &s.d);
			s.v = V;
			pq.push(s);
		}

		for (int i = 0; i < K; i++) {
			s = pq.top();
			pq.pop();
			s.v += s.d;
			time += (long double)s.x/s.v;
		}

		while (!pq.empty()) {
			s = pq.top();
			pq.pop();
			time += (long double)s.x/s.v;
		}
		printf("%0.4Lf\n", time);
	}
	return 0;
}