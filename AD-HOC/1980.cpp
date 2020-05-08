#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string.h>

using namespace std;

map<char, int> counter;
char word[50];

long long int factorial(int n) {
	long long int fac = 1;
	for (int i = 1; i <= n; i++) {
		fac = fac * i;
	}
	return fac;
}

long long int dividendo(int total, int max) {
	long long int fac = 1;
	for (int i = max+1; i <= total; i++) {
		fac = fac * i;
	}
	return fac;
}

long long int divisor(char max_c) {
	char c;
	long long int div = 1;
	for (auto it = counter.begin(); it != counter.end(); ++it) {
		c = it->first;
		if (c != max_c) {
			div = div * factorial(it->second);
		}
	}
	return div;
}

int main() {

	int total;
	char max_c;
	int maximum = 0;
	int aux;
	long long int p1;
	long long int p2;
	while (1) {
		scanf(" %s ", word);
		if (strcmp(word, "0") == 0) {
			break;
		}

		counter.clear();
		
		total = strlen(word);
		for (int i = 0; i < total; i++) {
			counter[word[i]]++;
			aux = counter[word[i]];
			if (aux > maximum) {
				maximum = aux;
				max_c = word[i];
			}
		}

		p1 = dividendo(total, maximum);
		p2 = divisor(max_c);

		printf("%Ld\n", p1 / p2);
	}

	return 0;
}