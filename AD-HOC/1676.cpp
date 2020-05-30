#include <stdlib.h>
#include <stdio.h>

struct node {
	int id;
	struct node * next;
};

struct node list[300011];
int res[3001];
int index;
int N;

int main() {
	
	list[0].next = &list[1];
	list[0].id = -1;

	for (int i = 1; i < 300011; i++) {
		list[i].id = i+1;
		list[i].next = &list[i+1];
	}

	struct node * pointer = &list[1];
	struct node * aux, * init;
	index = 0;
	while (index < 3001) {
		int k = pointer->id;
		res[index++] = k;
		init = pointer;
		// Guessed that highest answear is less them 60000
		while (pointer->id < 60000) {
			for (int i = 0; i < k-1; i++) {
				pointer = pointer->next;
			}
			aux = pointer->next;
			pointer->next = pointer->next->next;
			pointer = aux;
		}
		pointer = init->next;
	}

	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		printf("%d\n", res[N-1]);
	}

	return 0;
}