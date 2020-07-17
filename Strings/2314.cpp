#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char line[2009];
int pointer;
int identAmnt;

void ident() {
	for (int i = 0; i < identAmnt; i++) {
		printf("....");
	}
}

int main() {
	do {
		fgets(line, 2009, stdin);
		if (line[0] == '#') {
			printf("%s", line);
		}
	} while (line[0] == '#');
	int par = 0;
	int id = 0;
	for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
		if (line[i] == '(') {
			par++;
		} else if (line[i] == ')') {
			par--;
		} 

		if (line[i] == ';' && !par) {
			printf(";\n");
			id = 1;
		} else if (line[i] == '{') {
			printf("\n");
			ident();
			printf("{\n");
			identAmnt++;
			id = 1;
		} else if (line[i] == '}') {
			identAmnt--;
			ident();
			printf("}\n");
			id = 1;
		} else {
			if (id) {
				id = 0;
				ident();
			}
			printf("%c", line[i]);
		}
	}
	return 0;
}