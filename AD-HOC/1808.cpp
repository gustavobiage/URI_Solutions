#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char S[1000];

int main() {

	scanf(" %s ", S);
	int len = strlen(S);
	int c = 0;
	int sum = 0;
	for (int i = 0; i < len;) {
		if (i != len-1 &&
			S[i] == '1' &&
			S[i+1] == '0') {
			sum += 10;
			i += 2;
		} else {
			sum += S[i] - '0';
			i++;
		}
		c++;
	}
	printf("%0.2lf\n", (double) sum / c);

	return 0;
}