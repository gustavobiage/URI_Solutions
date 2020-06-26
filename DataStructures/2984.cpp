#include <stdlib.h>
#include <stdio.h>

char line[100009];

int main() {
	scanf(" %s ", line);
	int open = 0;
	for (int i = 0; line[i] != '\0'; i++) {
		if (line[i] == '(') {
			open++;
		} else if (open) {
			open--;
		}
	}

	if (open) {
		printf("Ainda temos %d assunto(s) pendente(s)!\n", open);
	} else {
		printf("Partiu RU!\n");
	}
	return 0;
}