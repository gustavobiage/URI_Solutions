#include <stdlib.h>
#include <stdio.h>

int a;

int printA(int n) {
	for (int i = 0; i < n; i++) {
		printf("a");
	}
}

int main() {
	scanf("%d ", &a);
	printf("Ent");
	printA(a);
	printf("o eh N");
	printA(a);
	printf("t");
	printA(a);
	printf("l!\n");
}