#include <stdlib.h>
#include <stdio.h>

#define BEGIN 0
#define POINTER 2
#define END 3

struct node {
	char c;
	struct node * next;
};

struct node * begin;
struct node * end;
struct node * pointer;
char line[100001];
int status;

int main() {
	while (scanf("%s ", line) != EOF) {
		status = BEGIN;
		begin = end = pointer = NULL;
		struct node * node;
		for (int i = 0; line[i] != '\0'; i++) {
			if (line[i] == '[') {
				status = BEGIN;
			} else if (line[i] == ']') {
				status = END;
			} else {
				node = (struct node *) malloc(sizeof(struct node));
				node->c = line[i];
				if (begin == NULL) {
					begin = end = node;
				} else if (status == BEGIN) {
					node->next = begin;
					begin = node;
				} else if (status == END) {
					end->next = node;
					end = node;
				} else if (status == POINTER) {
					node->next = pointer->next;
					pointer->next = node;
					if (end == pointer) {
						end = node;
					}
				}
				pointer = node;
				status = POINTER;
			}
		}
		node = begin;
		while (node != NULL) {
			printf("%c", node->c);
			node = node->next;
		}
		printf("\n");
	}
	return 0;
}