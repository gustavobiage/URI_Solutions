#include <stdlib.h>
#include <stdio.h>

int CORRECT = 2002;
int password;

int main() {
	while (1) {
		scanf("%d ", &password);
		if (password == CORRECT) {
			printf("Acesso Permitido\n");
			break;
		} else {
			printf("Senha Invalida\n");
		}
	}
	return 0;
}