#include <stdlib.h>
#include <stdio.h>

int N;

int main() {
	int ci, cj;

	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}

		double counter = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d %d ", &ci, &cj);
			counter += 0.5 * (cj / 2);
		}

		printf("%d\n", (int) counter);
	}
	return 0;
}