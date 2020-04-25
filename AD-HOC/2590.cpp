#include <stdlib.h>
#include <stdio.h>

unsigned long long int N;
int T, v;
int power[] = {1, 7, 9, 3};

int main() {
	
	scanf("%d ", &T);
	while (T) {
		scanf("%Lu ", &N);

		v = (N % 4);
		printf("%d\n", power[v]);

		T--;
	}

	return 0;
}