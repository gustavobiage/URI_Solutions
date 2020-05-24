#include <stdlib.h>
#include <stdio.h>

int N;
char c1[1000];
char c2[1000];
int v1, v2;
int c;
int main() {
	c = 0;

	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		c++;
		
		scanf(" %s ", c1);
		scanf(" %s ", c2);
		printf("Teste %d\n", c);
		for (int i = 0; i < N; i++) {
			scanf("%d %d ", &v1, &v2);
			if ((v1 + v2) % 2) {
				printf("%s\n", c2);
			} else {
				printf("%s\n", c1);
			}
		}
		printf("\n");
	}

	return 0;
}