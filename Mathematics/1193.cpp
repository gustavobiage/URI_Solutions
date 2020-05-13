#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>

#define BIN "bin"
#define DEC "dec"
#define HEX "hex"

using namespace std;

int T, t;
char num[10000];
char type[5];
map<char, int> hex_to_decimal;
map<int, char> decimal_to_hex;
long long int dec;

long long int power(int a, int b) {
	long long int res = 1;
	for (int i = 0; i < b; i++) {
		res = res * a;
	}
	return res;
}

void init_hex_map() {
	const char * alf = "0123456789abcdef";
	const char * alfCAPS = "0123456789ABCDEF";
	for (int i = 0; i <  16; i++) {
		decimal_to_hex[i] = alf[i];
		hex_to_decimal[alf[i]] = i;
		hex_to_decimal[alfCAPS[i]] = i;
	}
}

long long int toDecimal(char * num, int base) {
	long long int decimal = 0;

	int index = strlen(num) - 1;
	int pow = 0;
	while (index >= 0) {
		decimal += hex_to_decimal[num[index]] * power(base, pow++);
		index--;
	}
	return decimal;
}

int decimalToBase(long long int decimal, int base) {
	int arr[100];
	int index = 0;
	int digit;
	while (decimal) {
		digit = decimal % base;
		decimal = decimal / base;
		arr[index++] = digit;
	}

	for (int i = index-1; i >= 0 && index <= 32; i--) {
		printf("%c", decimal_to_hex[arr[i]]);
	}

	if (base == 16) {
		printf(" hex\n");
	} else if (base == 2) {
		printf(" bin\n");
	}
}

int main() {

	init_hex_map();

	scanf("%d ", &T);
	for (t = 1; t <= T; t++) {
		printf("Case %d:\n", t);
		scanf("%s %s ", num, type);

		if (strcmp(type, BIN) == 0) {
			//BINARY
			dec = toDecimal(num, 2);
			printf("%d dec\n", (int) dec);
			decimalToBase(dec, 16);
		} else if (strcmp(type, HEX) == 0) {
			//HEX
			dec = toDecimal(num, 16);
			printf("%d dec\n", (int) dec);
			decimalToBase(dec, 2);
		} else {
			//DECIMAL
			dec = toDecimal(num, 10);
			decimalToBase(dec, 16);
			decimalToBase(dec, 2);
		}
		printf("\n");
	}
	return 0;
}