#include <stdlib.h>
#include <stdio.h>

#define DIST 42195

int N, M;

int a, b;
int r;
int main() {

	scanf("%d %d ", &N, &M);

	b = 0;
	r = 1;
	for (int i = 0; i < N; i++) {
		scanf("%d ", &a);

		if (a - b <= M) {
			b = a;
		} else {
			r = 0;
			goto END;
		}
	}

	r = r && (DIST - b <= M);

	END:
	if (!r) {
		printf("N\n");
	} else {
		printf("S\n");
	}

	return 0;
}