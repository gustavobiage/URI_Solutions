#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string.h>

using namespace std;

char Rhex[100], Ghex[100], Bhex[100];
long long unsigned R, G, B;
long long unsigned res, amount;
map<char, int> decoder;
const char * alf = "0123456789abcdef";

long long unsigned fromHex(char * c) {
	int len = strlen(c);
	int mul = 1;;
	long long unsigned value = 0;
	for (int i = len-1; i >= 0; i--) {
		value += decoder[c[i]] * mul;
		mul = mul * 16;
	}
	return value;
}

void init() {
	for (int i = 0; i < strlen(alf); i++) {
		decoder[alf[i]] = i;
	}
}

void prtHex(long long unsigned n) {
	char stack[100];
	int index = 0;
	int digit;
	while (n) {
		digit = n % 16;
		n = n / 16;
		stack[index++] = alf[digit];
	}

	index--;
	while (index >= 0) {
		printf("%c", stack[index--]);
	}
	printf("\n");
}

int main() {
	init();
	scanf("%s %s %s ", Rhex, Ghex, Bhex);
	R = fromHex(&Rhex[0]);
	G = fromHex(&Ghex[0]);
	B = fromHex(&Bhex[0]);
	amount = 1;
	res = (R / G) * (R / G);
	amount += res;
	res = res * (G / B) * (G / B);
	amount += res;
	prtHex(amount);
}