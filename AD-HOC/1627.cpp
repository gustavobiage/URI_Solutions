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
			// printf("%d -> ", H);
			if (ta <= tb) {
				// printf("Andre hit (-%d) -> ", At);
				wins = A;
				H -= At;
				ta += Ad;
			} else {
				// printf("Beto hit (-%d) -> ", Bt);
				wins = B;
				H -= Bt;
				tb += Bd;
			}
			// printf("%d\n", H);
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