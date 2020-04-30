#include <stdlib.h>
#include <stdio.h>

int N;
int map[1008][1008];
int main() {

	int x, y;
	scanf("%d ", &N);
	
	for (int i = 0; i < 1008; i++) {
		for (int j = 0; j < 1008; j++) {
			map[i][j] = 0;
		}
	}

	int yes = 0;
	for (int i = 0; i < N; i++) {
		scanf("%d %d ", &x, &y);
		if (map[x][y]) {
			yes = 1;
			goto END;
		}
		map[x][y] = 1;
	}

	END:
	printf("%d\n", yes);

	return 0;
}