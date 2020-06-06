#include <stdlib.h>
#include <stdio.h>

int V, P;

int main() {

	scanf("%d %d ", &V, &P);
	int aux;
	for (int i = 0; i < P; i++) {
		aux = V%(P);
		if (aux != 0) {
			printf("%d\n", V/P+1);
			V--;
		} else {
			printf("%d\n", V/P);
		}
	}
	return 0;
}