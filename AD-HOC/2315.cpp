#include <stdlib.h>
#include <stdio.h>

int d1, m1, d2, m2;

int getDays(int m) {
	int amnt = 0;
	switch (m) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		amnt += 1;
		case 4: case 6: case 9: case 11:
		amnt += 2;
		case 2:
		amnt += 28;
	}
	return amnt;
}

int main() {
	scanf("%d %d ", &d1, &m1);
	scanf("%d %d ", &d2, &m2);
	int sum = 0;
	for (int i = m1+1; i < m2; i++) {
		sum += getDays(i);
	}
	if (m1 != m2) {
		sum += getDays(m1) - d1;
		sum += d2;
	} else {
		sum += d2 - d1;
	}
	printf("%d\n", sum);
	return 0;
}