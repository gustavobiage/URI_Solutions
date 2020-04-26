#include <stdlib.h>
#include <stdio.h>

int N;
int Ax, Ay, Bx, By, Cx, Cy, Dx, Dy;
int Px, Py;

int main() {

	scanf("%d ", &N);

	while (N) {

		scanf("%d %d %d %d %d %d %d %d",
		 &Ax, &Ay, &Bx, &By,
		 &Cx, &Cy, &Dx, &Dy);

		scanf("%d %d ", &Px, &Py);

		if (Py >= Ay && Py <= Dy && Px >= Ax && Px <= Bx) {
			printf("1\n");
		} else {
			printf("0\n");
		}

		N--;
	}

	return 0;
}