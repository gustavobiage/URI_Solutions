#include <stdlib.h>
#include <stdio.h>

int N;
int J, Z;
int tj, tz;
int c;

int main() {
	c = 0;
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		c++;
		printf("Teste %d\n", c);
		for (int i = 0; i < N; i++) {
			scanf("%d %d ", &J, &Z);
			tj += J;
			tz += Z;
			printf("%d\n", tj-tz);
		}
		printf("\n");
	}
	return 0;
}