#include <stdlib.h>
#include <stdio.h>

#define Q 0
#define J 1
#define K 2
#define A 3
#define final 4

int n;
char line[10001];
int state;

void eval(char c) {
	if (state == Q && c == 'Q') {
		state++;
	} else if (state == J && c == 'J') {
		state++;
	} else if (state == K && c == 'K') {
		state++;
	} else if (state == A && c == 'A') {
		state++;
	}
}

int main() {
	scanf("%d ", &n);
	while (n--) {
		scanf(" %s ", line);
		state = 0;
		for (int i = 0; line[i] != '\0'; i++) {
			eval(line[i]);
		}
		if (state == final) {
			printf("Agora vai\n");
		} else {
			printf("Agora apertou sem abracar\n");
		}
	}
	return 0;
}