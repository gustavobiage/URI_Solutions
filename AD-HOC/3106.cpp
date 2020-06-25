#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define LLU long long int unsigned
#define LLD long long int
#define RIGHT 0
#define DOWN 1
#define LEFT 2
#define UP 3

#define MAX 100001

int N;
int v;

int main() {
	scanf("%d ", &N);
	long long int s;
	for (int i = 0; i < N; i++) {
		scanf("%d ", &v);
		s += v / 3;
	}
	printf("%Ld\n", s*3);
	return 0;
}