#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int T;
int x, y;
int f;

int main() {
	scanf("%d ", &T);
	while (T) {

		scanf("%dx%d ", &x, &y);
		for (int i = 5; i <= 10; i++) {
			f = 1;
			if (x != y) {
					printf("%d x %d = %d", x, i, x*i);
					printf(" && %d x %d = %d", y, i, y*i);
			} else {
					printf("%d x %d = %d", x, i, x*i);
			}
			printf("\n");
		}
		T--;
	}
	return 0;
}