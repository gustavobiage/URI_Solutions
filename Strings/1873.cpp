#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TESOURA 1
#define PAPEL 10
#define PEDRA 100
#define LAGARTO 1000
#define SPOCK 10000
#define STR_TESOURA "tesoura"
#define STR_PAPEL "papel"
#define STR_PEDRA "pedra"
#define STR_LAGARTO "lagarto"
#define STR_SPOCK "spock"

int getValue(char * word) {
	if (strcmp(word, STR_TESOURA) == 0) {
		return TESOURA;
	} else if (strcmp(word, STR_PAPEL) == 0) {
		return PAPEL;
	} else if (strcmp(word, STR_PEDRA) == 0) {
		return PEDRA;
	} else if (strcmp(word, STR_LAGARTO) == 0) {
		return LAGARTO;
	} else if (strcmp(word, STR_SPOCK) == 0) {
		return SPOCK;
	}
}

int wins(int a, int b) {
	int c = a - b;
	switch (c) {
		case TESOURA-PAPEL:
		case PAPEL-PEDRA:
		case PEDRA-LAGARTO:
		case LAGARTO-SPOCK:
		case SPOCK-TESOURA:
		case TESOURA-LAGARTO:
		case LAGARTO-PAPEL:
		case PAPEL-SPOCK:
		case SPOCK-PEDRA:
		case PEDRA-TESOURA:
		return 1;
	}
	return 0;
}

int T;
char v1[100], v2[100];
int p1, p2;

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf("%s %s ", v1, v2);
		p1 = getValue(v1);
		p2 = getValue(v2);
		if (p1 == p2) {
			printf("empate\n");
		} else if (wins(p1, p2)) {
			printf("rajesh\n");
		} else {
			printf("sheldon\n");
		}
	}
	return 0;
}