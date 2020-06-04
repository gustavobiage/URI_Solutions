#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

int N, Q;
int K, M;

char line[102];
char arr[102];
char alfabeto[] = {'x', 'o'};

int main() {

	while (1) {
		scanf("%d %d ", &N, &Q);
		if (!N && !Q) {
			break;
		}

		scanf(" %s ", line);
		for (int i = 0; i < N; i++) {
			if (line[i] == 'x') {
				line[i] = 0;
			} else {
				line[i] = 1;
			}
		}
		
		arr[N] = '\0';
		for (int q = 0; q < Q; q++) {
			scanf("%d %d ", &K, &M);
			
			M = M % (N*2);
			
			for (int i = 0; i < N; i++) {
				arr[i] = line[i];
			}

			if (M != 0) {
				int index = 0;
				arr[index] = (arr[index] + 1) % 2;
				for (int i = 0; i < M-1; i++) {
					index = (index + K) % N;
					arr[index] = (arr[index] + 1) % 2;
				}
			}

			for (int i = 0; i < N; i++) {
				arr[i] = alfabeto[arr[i]];
			}
			printf("%s\n", arr);
		}
	}
	return 0;
}