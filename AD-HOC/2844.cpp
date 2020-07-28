#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char line[10000];
int am, rm, em;
int av, rv, ev;
int m, v;

int main() {
	scanf("%d %d %d ", &am, &rm, &em);
	scanf("%d %d %d ", &av, &rv, &ev);
	fgets(line, 10000, stdin);
	int len = strlen(line);
	if (line[len-1] == '\n') {
		len--;
	}
	m = 2*am + rm + em*len;
	v = 2*av + rv + ev*len;
	if (m < v) {
		printf("Matheus\n");
	} else if (v < m) {
		printf("Vinicius\n");
	} else {
		printf("Empate\n");
	}
}