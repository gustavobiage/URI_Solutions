#include <stdlib.h>
#include <stdio.h>

int A, B, C;
int H, L;

int main() {

	scanf("%d %d %d ", &A, &B, &C);
	scanf("%d %d ", &H, &L);
	int x1, x2, x3, x4, x5, x6;
	int y1, y2, y3, y4, y5, y6;
	
	x1 = A; y1 = B;
	x2 = A; y2 = C;
	x3 = B; y3 = A;
	x4 = B; y4 = C;
	x5 = C; y5 = A;
	x6 = C; y6 = B;

	if (x1 <= H && y1 <= L ||
		x2 <= H && y2 <= L ||
		x3 <= H && y3 <= L ||
		x4 <= H && y4 <= L ||
		x5 <= H && y5 <= L ||
		x6 <= H && y6 <= L) {
		printf("S\n");
	} else {
		printf("N\n");
	}
	return 0;
}