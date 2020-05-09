#include <stdlib.h>
#include <stdio.h>
#include <set>

#define ACTUAL 0
#define REFERENCE 1

using namespace std;

int N, K;

struct s{
	int type;
	set<int> s;
	struct s * pointer;
};

struct s s[100001];
struct s * arr[100001];

char op;
int a, b;

struct s * find(int n) {
	struct s * p = arr[n];
	while (p->type != ACTUAL) {
		p = p->pointer;
	}
	return p;
}

int cmp(struct s * a, struct s * b) {
	return a == b;
}

void unionf(struct s * p1, struct s * p2) {
	if (p1->s.size() < p2->s.size()) {
		p1->type = REFERENCE;
		for (auto it = p1->s.begin(); it != p1->s.end(); ++it) {
			p2->s.insert(*it);
		}
		p1->s.clear();
		p1->pointer = p2;
	} else {
		p2->type = REFERENCE;
		for (auto it = p2->s.begin(); it != p2->s.end(); ++it) {
			p1->s.insert(*it);
		}
		p2->s.clear();
		p2->pointer = p1;
	}
}

int main() {

	scanf("%d %d ", &N, &K);
	for (int i = 1; i <= N; i++) {
		// s[i].s.clear();
		s[i].s.insert(i);
		s[i].type = ACTUAL;
		arr[i] = &s[i];
	}

	struct s * fa;
	struct s * fb;
	for (int i = 0; i < K; i++) {
		scanf("%c %d %d ", &op, &a, &b);
		fa = find(a);
		fb = find(b);
		if (op == 'C') {
			// printf("%d %d\n", find(a), find(b));
			if (cmp(fa, fb)) {
				printf("S\n");
			} else {
				printf("N\n");
			}
		} else if (op == 'F') {
			if (!cmp(fa, fb)) {
				unionf(fa, fb);
			}
		}
	}
	return 0;
}