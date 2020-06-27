#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>

using namespace std;

map<string, double> m;
string str;
char name[100000];
double v, sum;
int amnt;
int T, N;

int main() {
	scanf("%d ", &T);
	while (T--) {
		m.clear();
		sum = 0;
		scanf("%d ", &N);
		for (int i = 0; i < N; i++) {
			scanf("%s %lf", name, &v);
			str = name;
			m[str] =v;
		}
		scanf("%d ", &N);
		for (int i = 0; i < N; i++) {
			scanf("%s %d", name, &amnt);
			str = name;
			sum += amnt*m[str];
		}
		printf("R$ %0.2lf\n", sum);
	}

	return 0;
}