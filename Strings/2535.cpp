#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N;
char specie[102];
char breed[102];
char name[102];
int len;

int cmp;
int equal_char;
int c;
int main() {
	
	while (scanf("%d ", &N) != EOF) {
		c = 0;
		for (int i = 0; i < N; i++) {
			cmp = equal_char = 0;
			fgets(specie, 102, stdin);
			fgets(breed, 102, stdin);
			fgets(name, 102, stdin);
			// printf("{\n%s%s%s}", specie, breed, name);
			scanf("%*c");
			len = strlen(specie);
			specie[len-1] = '\0';
			if (strcmp(specie, "cachorro") == 0) {
				len = strlen(name);
				equal_char = (name[0] == breed[0]);
				for (int i = 0; i < len-1; i++) {
					if (name[i] == ' ' && name[i+1] != ' ') {
						cmp = 1;
						if (name[i+1] == breed[0]) {
							equal_char = 1;
						}
					}
				}
				if (cmp && equal_char) {
					c++;
				}
			}
		}
		printf("%d\n", c);
	}

	return 0;
}