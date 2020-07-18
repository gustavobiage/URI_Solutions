#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N, A, T;
char name[100];
char ans[100];
int m;

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		m = 2115;
		for (int i = 0; i < N; i++) {
			scanf("%s %d %d ", name, &A, &T);
			if (A-T < m) {
				m = A-T;
				strcpy(ans, name);
			}
		}
		printf("%s\n", ans);
	}

	return 0;
}