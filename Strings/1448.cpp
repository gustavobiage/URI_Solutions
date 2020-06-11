#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int T, t;
char orig[200];
char line1[200], line2[200];
int f1, f2, c1, c2;

int main() {
	scanf("%d ", &T);
	t = 0;
	while (T) {
		t++;
		fgets(orig, 200, stdin);
		fgets(line1, 200, stdin);
		fgets(line2, 200, stdin);
		f1 = f2 = -1;
		c1 = c2 = 0;
		for (int i = 0; i < strlen(orig)-1; i++) {
			if (orig[i] == line1[i]) {
				if (f1 == -1 && orig[i] != line2[i]) {
					f1 = i;
				}
				c1++;
			}
			if (orig[i] == line2[i]) {
				if (f2 == -1 && orig[i] != line1[i]) {
					f2 = i;
				}
				c2++;
			}
		}
		// printf("%s vs %s; orig = %s\n", line1, line2, orig);
		// printf("%d %d %d %d\n", c1, f1, c2, f2);
		printf("Instancia %d\n", t);
		if (c1 != c2) {
			if (c1 > c2) {
				printf("time 1\n");
			} else {
				printf("time 2\n");
			}
		} else {
			if (f1 != -1 && f1 < f2) {
				printf("time 1\n");
			} else if (f2 != -1 && f2 < f1) {
				printf("time 2\n");
			} else {
				printf("empate\n");
			}
		}
		printf("\n");
		T--;
	}
}