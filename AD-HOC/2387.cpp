#include <stdlib.h>
#include <stdio.h>

#define INF 1000002

int N;
int X[10002];
int Y[10003];
int DP[10003];
int time, c;

int main() {
	scanf("%d ", &N);
	time = 0;
	
	for (int i = 0; i < N; i++) {
		scanf("%d %d ", &X[i], &Y[i]);
	}
	
	c = 0;
	
	for (int i = 0; i < N; i++) {
		if (X[i] >= time) {
			time = Y[i];
			c++;
		} else if (Y[i] < time) {
			time = Y[i];
		}
	}

	printf("%d\n", c);
	return 0;
}