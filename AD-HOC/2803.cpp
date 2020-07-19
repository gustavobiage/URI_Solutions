#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char * states[] = { "acre", "amapa", "amazonas", "para", "rondonia", "roraima", "tocantins"};
int len = 7;

char line[100001];

int main() {
	fgets(line, 100001, stdin);
	int str_len = strlen(line);
	if (line[str_len-1] == '\n') {
		line[str_len-1] = '\0';
	}
	int res = 0;
	for (int i = 0; i < len; i++) {
		if (!strcmp(states[i], line)) {
			res = 1;
			break;
		}
	}
	if (res) {
		printf("Regiao Norte\n");
	} else {
		printf("Outra regiao\n");
	}
	return 0;
}