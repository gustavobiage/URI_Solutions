#include <stdlib.h>
#include <stdio.h>

struct node {
	int id;
	struct node * next;
};

struct node list[102];
struct node * root;
int c, v;
int P, R, N, J;
int t;

void remove(int index) {
	if (index == 0) {
		root = root->next;
		return;
	}
	struct node * aux = root;
	for (int i = 0; i < index - 1; i++) {
		aux = aux->next;
	}
	aux->next = aux->next->next;
}

int main() {
	t = 0;
	while (1) {
		scanf("%d %d ", &P, &R);
		if (!P && !R) {
			break;
		}
		t++;
		for (int i = 0; i < P; i++) {
			scanf("%d ", &list[i].id);
			list[i].next = &list[i+1];
		}
		list[P-1].next = NULL;
		root = &list[0];

		for (int i = 0; i < R; i++) {
			scanf("%d ", &N);
			scanf("%d ", &J);
			c = 0;
			for (int j = 0; j < N; j++) {
				scanf("%d ", &v);
				if (v != J) {
					remove(j - c);
					c++;
				}
			}
		}

		printf("Teste %d\n", t);
		printf("%d\n", root->id);
		printf("\n");
	}
	return 0;
}