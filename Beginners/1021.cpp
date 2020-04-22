#include <stdlib.h>
#include <stdio.h>

int main() {
	int amnt1, amnt2;
	int notes[] = {100, 50, 20, 10, 5, 2, 1};
	int coins[] = {50, 25, 10, 5, 1};
	int lenNotes = 7;
	int lenCoins = 5;

	scanf("%d.%d ", &amnt1, &amnt2);
	int v = amnt1;
	printf("NOTAS:\n");
	for (int i = 0; i < lenNotes; i++) {
		int c = v / notes[i];
		v = v % notes[i];
		if (i == lenNotes - 1) {
			printf("MOEDAS:\n");
			printf("%d moeda(s) de R$ 1.00\n", c);
		} else {
			printf("%d nota(s) de R$ %d.00\n", c, notes[i]);
		}
	}

	v = amnt2;
	for (int i = 0; i < lenCoins; i++) {
		int c = v / coins[i];
		v = v % coins[i];
		if (i >= lenCoins - 2) {
			printf("%d moeda(s) de R$ 0.0%d\n", c, coins[i]);
		} else {
			printf("%d moeda(s) de R$ 0.%d\n", c, coins[i]);
		}
	}

	return 0;
}