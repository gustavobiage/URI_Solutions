#include <stdlib.h>
#include <stdio.h>

struct c {
	char name[50];
	int v;
	struct c *next, *previous;
};

int N;
struct c list[150];

struct c* removeNext(struct c * p) {
	int v = p->v;
	struct c * aux = p;
	for (int i = 0; i < v; i++) {
		aux = aux->next;
	}
	aux->previous->next = aux->next;
	aux->next->previous = aux->previous;
	// printf("n: %s\n", aux->name);
	return aux;
}

struct c* removePrevious(struct c * p) {
	int v = p->v;
	struct c * aux = p;
	for (int i = 0; i < v; i++) {
		// printf("%s->", aux->name);
		aux = aux->previous;
	}
	// printf("\n");
	aux->previous->next = aux->next;
	aux->next->previous = aux->previous;
	// printf("p: %s\n", aux->name);
	return aux;
}

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		for (int i = 0; i < N; i++) {
			scanf(" %s %d ", list[i].name, &list[i].v);
		}
		if (N > 1) {
			for (int i = 1; i < N-1; i++) {
				list[i].next = &list[i+1];
				list[i].previous = &list[i-1];
			}
			list[0].next = &list[1];
			list[0].previous = &list[N-1];
			list[N-1].next = &list[0];
			list[N-1].previous = &list[N-2];
		} else {
			list[0].next = &list[0];
		}

		struct c * pointer = &list[0];
		while (N > 1) {
			if (pointer->v % 2) {
				pointer = removeNext(pointer);
			} else {
				pointer = removePrevious(pointer);
			}
			N--;
		}
		pointer = pointer->next;
		printf("Vencedor(a): %s\n", pointer->name);
	}
	return 0;
}