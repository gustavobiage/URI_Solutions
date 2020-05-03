#include <stdlib.h>
#include <stdio.h>

#define EMPTY 0
#define WRONG 1
#define RIGHT 2

int T;
int N;
int t;
int p;
int m[109];
int state[109];
int sum;

int main() {

	scanf("%d ", &T);
	while (T) {
		scanf("%d ", &N);
		for (int i = 0; i <= 100; i++) {
			m[i] = 0;
			state[i] = EMPTY;
		}

		for (int i = 0; i < N; i++) {
			scanf("%d %d ", &t, &p);
			if ((m[t] < p || state[t] == WRONG) && p <= 100 && p >= 10) {
				m[t] = p;
				state[t] = RIGHT;
			}
			 else if ((state[t] == WRONG || state[t] == EMPTY) && m[t] < p) {
				m[t] = p;
				state[t] = WRONG;
			}
		}

		sum = 0;
		for (int i = 1; i <= 100; i++) {
			sum += m[i];
		}

		printf("%d\n", sum);

		T--;
	}
	return 0;
}