#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N, K;
int v;
char names[5][100];

void init() {
	strcpy(names[1], "Rolien");
	strcpy(names[2], "Naej");
	strcpy(names[3], "Elehcim");
	strcpy(names[4], "Odranoel");
}

int main() {
	init();
	scanf("%d ", &N);
	while (N--) {
		scanf("%d ", &K);
		for (int i = 0; i < K; i++) {
			scanf("%d ", &v);
			printf("%s\n", names[v]);
		}
	}
	return 0;
}