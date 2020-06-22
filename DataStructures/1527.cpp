#include <stdlib.h>
#include <stdio.h>

#define LEAF 1
#define NODE 2

struct t {
	int points;
	int status;
	struct t * next;
	int containsR;
};

int N, M;
struct t arr[100001];
int Q, A, B;
int c, v;

struct t* getLeaf(struct t* pointer) {
	if (pointer->status == LEAF) {
		return pointer;
	}
	struct t * aux = getLeaf(pointer->next);
	pointer->next = aux;
	return aux;
}

void set_union(int a, int b) {
	struct t * g1 = getLeaf(&arr[a]);
	struct t * g2 = getLeaf(&arr[b]);
	if (g1 != g2) {
		g1->points += g2->points;
		g1->containsR = g1->containsR || g2->containsR;
		g2->status = NODE;
		g2->next = g1;
	}
}

int battle(int a, int b) {
	struct t * g1 = getLeaf(&arr[a]);
	struct t * g2 = getLeaf(&arr[b]);
	return g1->points > g2->points && g1->containsR || g1->points < g2->points && g2->containsR;
}

int main() {
	while (1) {
		scanf("%d %d ", &N, &M);
		if (!N && !M) {
			break;
		}
		c = 0;
		for (int i = 1; i <= N; i++) {
			arr[i].points = 0;
			arr[i].status = LEAF;
			scanf("%d ", &v);
			arr[i].points += v;
			arr[i].containsR = i == 1;
		}

		for (int i = 0; i < M; i++) {
			scanf("%d %d %d ", &Q, &A, &B);
			if (Q == 1) {
				set_union(A, B);
			} else {
				c += battle(A, B);
			}
		}
		printf("%d\n", c);
	}
	return 0;
}