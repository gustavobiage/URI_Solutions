#include <stdlib.h>
#include <stdio.h>

int H;
int m;

void find(int n) {
	if (n > m) {
		m = n;
	}

	if (n == 1) {
		return;
	}

	int x;
	if (n%2) {
		x = 3 * n + 1;
	} else {
		x = n/2;
	}

	find(x);
}

int main() {

	while (1) {
		scanf("%d ", &H);
		if (!H) {
			break;
		}
		m = 0;
		find(H);
		printf("%d\n", m);
	}

	return 0;
}