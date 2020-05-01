#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>

using namespace std;

map<int, int> M;
map<int, int> F;
char line[1000000];

int N;
int v, f;

char c;

int main() {
	int counter = 0;
	f = 1;

	while (scanf("%d ", &N) != EOF) {
		counter++;
		M.clear();
		F.clear();
		
		if (!f) {
			printf("\n");
		} else {
			f = 0;
		}

		fgets(line, 1000000, stdin);
		int index = 0;
		while (sscanf(&line[index], " %d %c ", &v, &c) != EOF) {
			for (;line[index] != 'M' && line[index] != 'F' && line[index] != '\0'; index++);
			index++;
			if (c == 'F') {
				F[v]++;
			} else if (c == 'M') {
				M[v]++;
			}
		}

		printf("Caso %d:\n", counter);
		printf("Pares Iguais: %d\n", F[N] + M[N]);
		printf("F: %d\n", F[N]);
		printf("M: %d\n", M[N]);
	}

	return 0;
}