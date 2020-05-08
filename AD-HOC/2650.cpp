#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N, W;
char line[1500];
char * name;
char * cinteger;

int main() {

	scanf("%d %d ", &N, &W);
	int p, v;
	for (int i = 0; i < N; i++) {

		fgets(line, 1500, stdin);
		p = strlen(line);
		line[--p] = '\0';
		while (line[p] != ' ') {
			p--;
		}
		line[p] = '\0';
		name = &line[0];
		cinteger = &line[p+1];

		v = atoi(cinteger);
		if (v > W) {
			printf("%s\n", name);
		}
	}
	return 0;
}