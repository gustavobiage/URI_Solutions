#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char D[102], C[102];
int lenD, lenC;

int main() {
	int j, res;
	while (scanf(" %s ", D) != EOF) {
		scanf(" %s ", C);
		lenD = strlen(D);
		lenC = strlen(C);
		res = 0;
		if (lenC <= lenD) {
			for (int i = 0; i <= lenD - lenC; i++) {
				for (j = i; D[j] == C[j-i] && j-i < lenC; j++);
				if (j-i == strlen(C)) {
					res = 1;
					break;
				}
			}
		}

		if (res) {
			printf("Resistente\n");
		} else {
			printf("Nao resistente\n");
		}
	}
	return 0;
}