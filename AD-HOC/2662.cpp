#include <stdlib.h>
#include <stdio.h>

int arr[] = {2, 2, 1, 2, 2, 2, 1};
int seq[12][62];
const char * name[] = {"do", "do#", "re", "re#", "mi", "fa", "fa#", "sol", "sol#", "la", "la#", "si"};
int tecl[100001];
int N;

int main() {
	scanf("%d ", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d ", &tecl[i]);
	}

	for (int i = 0; i < 12; i++) {
		int j = i+1;
		int index = 0;
		while (j <= 61) {
			seq[i][j] = 1;
			j += arr[index];
			index = (index + 1) % 7;
		}
		j = i+1;
		index = 6;
		while (j > 0) {
			seq[i][j] = 1;
			j -= arr[index];
			index = (index -1 + 7) % 7;
		}
	}

	int valid = 0;
	int res;
	for (int i = 0; i < 12 && !valid; i++) {
		res = i;
		for (int j = 0; j < N; j++) {
			if (seq[i][tecl[j]] != 1) {
				goto CONTINUE;
			}
		}
		valid = 1;
		goto PRT;
		CONTINUE:;
	} 

	PRT:
	if (valid) {
		printf("%s\n", name[res]);
	} else {
		printf("desafinado\n");
	}
	return 0;
}