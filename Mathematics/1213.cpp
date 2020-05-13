#include <stdlib.h>
#include <stdio.h>

int N;
int arr[10];

void init(int n) {
	for (int i = 0; i <= 9; i++) {
		arr[i] = n * i;
	}
}

int find(int goal) {
	for (int i = 0; i <= 9; i++) {
		if (arr[i] % 10 == goal) {
			return arr[i];
		}
	}
	return -1;
}

void search(int carry, int counter, int first) {
	int goal;
	
	int b = carry % 10;
	goal = 11 - carry % 10;
	carry = carry / 10;
	if (goal >= 10) {
		goal = goal - 10;
	}

	if (goal == 0 && carry == 0) {
		printf("%d\n", counter);
		return;
	}

	int dig = find(goal);
	carry += dig / 10 + (b > 1);
	dig = dig % 10;

	search(carry, counter+1, 0);
}

int main() {

	while (scanf("%d ", &N) != EOF) {
		if (N != 1) {
			init(N);
			search(0, 1, 1);
		} else {
			printf("1\n");
		}
	}

	return 0;
}