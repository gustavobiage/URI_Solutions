#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MOD 131071

char line[10000];
char bin[10000];
int len, exp;
int value;

int main() {

	while (scanf(" %s ", line) != EOF) {
		len = strlen(line);

		strcat(bin, line);
		if (line[len-1] == '#') {
			len = strlen(bin);
			exp = 1;
			value = 0;
			for (int i = len - 2; i >= 0; i--) {
				value += ((bin[i] - '0') * exp) % MOD;
				value = value % MOD;
				exp = (exp * 2) % MOD;
			}

			if (value == 0) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}

			bin[0] = '\0';
		}
	}

	return 0;
}