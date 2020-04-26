#include <stdlib.h>
#include <stdio.h>

#define A 1
#define B 0

int T;
int At, Bt;
int Ad, Bd;
int H;
int main() {

	scanf("%d ", &T);

	while (T) {

		scanf("%d %d ", &At, &Ad);
		scanf("%d %d ", &Bt, &Bd);

		int ta, tb;
		ta = tb = 0;
		
		scanf("%d ", &H);

		int wins;

		while (H > 0) {
			if (ta <= tb) {
				wins = A;
				H -= At;
				ta += Ad;
			} else {
				wins = B;
				H -= Bt;
				tb += Bd;
			}
		}

		if (wins == A) {
			printf("Andre\n");
		} else {
			printf("Beto\n");
		}

		T--;
	}

	return 0;
}