#include <stdlib.h>
#include <stdio.h>

struct node {
	int value;
	int max;
	struct node * next;
	struct node * previous;
};

struct node * order[102];
struct node list[102];
struct node * pointer;
int N, A;
int poss;

int cmp(const void * a, const void * b) {
	struct node v1 = *((struct node *)a);
	struct node v2 = *((struct node *)b);
	return v2.max - v1.max;
}

void remove(struct node * n) {
	n->previous->next = n->next;
	n->next->previous = n->previous;
}

int main() {

	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		poss = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d ", &list[i].max);
			order[i] = &list[i];
			list[i].value = 0;
			poss += list[i].max;
		}

		qsort(list, N, sizeof(struct node), cmp);

		for (int i = 1; i < N-1; i++) {
			list[i].next = &list[i+1];
			list[i].previous = &list[i-1];
		}
		list[N-1].next = &list[0];
		list[N-1].previous = &list[N-2];
		list[0].next = &list[1];
		list[0].previous = &list[N-1];

		pointer = &list[0];
		scanf("%d ", &A);
		if (poss >= A) {
			while (A) {
				// Max can be initialy zero
				while (pointer->max == 0) {
					remove(pointer);
					pointer = pointer->next;
				}

				pointer->value++;
				A--;
				if (pointer->value == pointer->max) {
					remove(pointer);
				}
				pointer = pointer-> next;
			}

			for (int i = 0; i < N; i++) {
				printf("%d\n", order[i]->value);
			}
		} else {
			printf("Impossible\n");
		}

	}
	return 0;
}