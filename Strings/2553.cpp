#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int len;
char line[1000000];
int M, m, n, dist;

int main() {

	while (fgets(line, 1000000, stdin) != NULL) {
		len = strlen(line);
		// Remove '\n' from fgets
		if (line[len-1] == '\n') {
			line[len-1] = '\0';
			len--;
		}
		M = m = n = dist = 0;
		for (int i = 0; i < len; i++) {
			if (line[i] >= 'a' && line[i] <= 'z') {
				m = 1;
			} else if (line[i] >= 'A' && line[i] <= 'Z') {
				M = 1;
			} else if (line[i] >= '0' && line[i] <= '9') {
				n = 1;
			} else {
				dist = 1;
			}
		}
		if (len >= 6 && len <= 32 && m && M && n && !dist) {
			printf("Senha valida.\n");
		} else {
			printf("Senha invalida.\n");
		}
	}

	return 0;
}