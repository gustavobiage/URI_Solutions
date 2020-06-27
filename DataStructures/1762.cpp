#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <string.h>
#include <map>
#include <math.h>

using namespace std;

int T;
int N, amnt;
double v, M, sum;
char line[100000];
map<string, double> m;
string str;

void clear(char * c) {
	int len = strlen(c);
	if (c[len-1] == '\n') {
		c[len-1] = '\0';
	}
}

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf("%d ", &N);
		m.clear();
		sum = 0;
		for (int i = 0; i < N; i++) {
			fgets(line, 100000, stdin);
			clear(&line[0]);
			str = line;
			scanf(" %lf", &v);
			scanf("%*c");
			m[str] = v;
		}
		scanf(" %lf", &M);
		scanf("%*c");
		while (1) {
			fgets(line, 100000, stdin);
			clear(&line[0]);
			scanf("%d ", &amnt);
			if (strcmp(line, "-") == 0 && !amnt) {
				break;
			}
			str = line;
			if (m.find(str) != m.end()) {
				sum += m[str] * amnt;
			} else {
				printf("NAO LISTADO: %s\n", line);
			}
		}
		printf("Peso total: %0.2lf kg\n", sum);
		printf("Numero de trenos: %d\n", (int)ceil(sum/M));
		printf("\n");
	}
	return 0;
}