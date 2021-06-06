#include <stdlib.h>
#include <stdio.h>

double notes[] = {100, 50, 20, 10, 5, 2};
int cnotes = 6;
double coins[] = {1, 0.50, 0.25, 0.10, 0.05, 0.01};
int ccoins = 6;
double value;
int counter;

int main() {
	scanf("%lf ", &value);
	// Confome mencionado no forum.
	value += 0.001;

	int pointer = 0;
	printf("NOTAS:\n");
	while (pointer < cnotes) {
		counter = 0;
		counter = (int) (value / notes[pointer]);
		value = value - counter * notes[pointer];
		printf("%d nota(s) de R$ %0.2lf\n", counter, notes[pointer]);
		pointer++;
	}
	pointer = 0;
	printf("MOEDAS:\n");
	while (pointer < ccoins) {
		counter = (int) (value / coins[pointer]);
		value = value - counter * coins[pointer];
		printf("%d moeda(s) de R$ %0.2lf\n", counter, coins[pointer]);
		pointer++;
	}
	return 0;
}