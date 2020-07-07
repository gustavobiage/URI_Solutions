#include <stdlib.h>
#include <stdio.h>
#include <set>

using namespace std;

struct r {
	int v;
	char c[10];
	int pointer;
};

struct cmp {
	bool operator() (const struct r& a, const struct r& b) const {
        if (a.v != b.v) {
        	return a.v < b.v;
        }
        int len = a.pointer;
        int equal = 0;
        for (int i = 0; i < len; i++) {
        	if (a.c[i] == b.c[i]) {
        		equal = 1;
        		break;
        	}
        }

        if (equal) {
        	return a.c[0] < b.c[0] || a.c[0] == b.c[0];
        } else {
        	return 0;
        }
    }
};

int N, M;
int C[10];
set<struct r, struct cmp> res;

int search(int index, set<int> * used, struct r * r, int val) {
	if (index == N) {
		r->v = val;
		if (res.find(*r) != res.end()) {
			return 1;
		} else {
			res.insert(*r);
			return 0;
		}
	}

	for (int i = 1; i <= M; i++) {
		val += C[index] * i;
		r->c[r->pointer++] = i;
		if (search(index+1, used, r, val)) {
			return 1;
		}
		r->pointer--;
		val -= C[index] * i;
	}

	return 0;
}

int main() {
	set<int> used;
	struct r r;
	while (scanf("%d %d ", &N, &M) != EOF) {
		for (int i = 0; i < N; i++) {
			scanf("%d ", &C[i]);
		}
		used.clear();
		res.clear();
		r.pointer = 0;
		if (search(0, &used, &r, 0)) {
			printf("Try again later, Denis...\n");
		} else {
			printf("Lucky Denis!\n");
		}
	}
	return 0;
}