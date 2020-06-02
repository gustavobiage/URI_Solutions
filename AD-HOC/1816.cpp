#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char * alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

struct node {
	char v;
	struct node * next;
};

struct node * root;

int N;
int v, c;

void init() {
	int len = strlen(alf);
	for (int i = len-1; i >= 0; i--) {
		struct node * aux = (struct node *) malloc(sizeof(struct node));
		aux->v = alf[i];
		aux->next = root;
		root = aux;
	}
}

void reset() {
	struct node * aux = root; 
	for (int i = 0; i < strlen(alf); i++) {
		aux->v = alf[i];
		aux = aux->next;
	}
}

void update(int index) {
	if (index != 0) {
		struct node * aux = root;
		struct node * del;
		for (int i = 0; i < index-1; i++) {
			aux = aux->next;
		}
		del = aux->next;
		aux->next = aux->next->next;
		del->next = root;
		root = del;
	}
	printf("%c", root->v);
}

int main() {
	c = 0;
	init();
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		c++;
		printf("Instancia %d\n", c);
		for (int i = 0; i < N; i++) {
			scanf("%d ", &v);
			update(v-1);
		}
		printf("\n\n");
		reset();
	}
}