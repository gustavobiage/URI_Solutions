#include <stdlib.h>
#include <stdio.h>

int last;
int N;

int main() {
	last = -1;
	while (scanf("%d ", &N) != EOF) {
		if (N <= last) {
			goto END;
		}
		last = N;
	}

	END:
	printf("%d\n", last + 1);
	return 0;
}