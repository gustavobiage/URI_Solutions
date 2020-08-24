#include <stdlib.h>
#include <stdio.h>

int R;
int S[3];

int main() {
	scanf("%d %d %d %d ", &S[0], &S[1], &S[2], &R);
	int res = S[0]*S[0] + S[1]*S[1] + S[2]*S[2] <= 4*R*R;
	
	if (res) {
		printf("S\n");
	} else {
		printf("N\n");
	}

	return 0;
}