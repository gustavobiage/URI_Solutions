#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>

using namespace std;

struct p {
	char c;
	int v;
};

int N, M;
vector<struct p> vec;
struct p p;

bool cmp(struct p a, struct p b) {
	if (a.c == b.c) {
		return b.v < a.v;
	}
	return b.c < a.c;
}

int main() {
	scanf("%d %d ", &N, &M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d%c ", &p.v, &p.c);
			vec.push_back(p);
		}
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < N*M; i++) {
		printf("%d%c\n", vec[i].v, vec[i].c);
	}
}