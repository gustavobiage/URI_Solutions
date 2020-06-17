#include <stdlib.h>
#include <stdio.h>

int T;
char line[20];
char num[20];
int p;
int final, v;

int main() {
	scanf("%d ", &T);
	while (T) {
		scanf("%s ", line);
		final = 0;
		p = 0;
		for (int i = 0; line[i] != '\0'; i++) {
			if (line[i] >= '0' && line[i] <= '9') {
				num[p++] = line[i];
			} else {
				if (p) {
					num[p] = '\0';
					sscanf(num, "%d ", &v);
					final += v;
				}
				p = 0;
			}
		}
		
		if (p) {
			num[p] = '\0';
			sscanf(num, "%d ", &v);
			final += v;
		}
		printf("%d\n", final);
		T--;
	}
	return 0;
}