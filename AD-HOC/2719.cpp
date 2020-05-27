#include <stdlib.h>
#include <stdio.h>

int T, N, M;
int c, v, t;

int main() {

	scanf("%d ", &T);
	while (T) {
		scanf("%d %d ", &N, &M);
		t = c = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d ", &v);
			if (c + v <= M) {
				c = c + v;
			} else {
				c = v;
				t++;
			}
		}
		t++;
		printf("%d\n", t);
		T--;
	}
	return 0;
}