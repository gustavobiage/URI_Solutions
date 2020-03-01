#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <map>

//Conversão Simples de Base
//Problem id: 1199
//Matematica
//Complexidade: O(Log(N)) per case, where N is a decimal value, worst case cenario.

char digits[100];
long long base10_value;
std::vector<char> base16_value;
std::map<int, char> dec_hex;
std::map<char, int> hex_dec;

//This is all college textbook stuff:
//	in decimal to hexadecimal we will converto binary and then to hex (we use "mod" and "div")
//	in hex to decimal we will convert each char to its decimal value and multiply by its a power of 16 depending on its position
long long convert_to_dec(char str[]) {
	long long number = 0;
	int n = strlen(str);
	for(int i = 2; i < n; i++) {
		number += hex_dec[str[i]]*(int)pow(16, (n-2)-i+1);
	}
	if(number < 0) number = number*(-1);
	return number;
}

std::vector<char> convert_to_hex(long long number) {
	
	std::vector<int> binary;
	std::vector<char> base16_value;

	// printf("%Ld : ", number);

	while(number >= 2) {
		binary.push_back(number%2);
		number = number/2;
	}
	if(number) {
		binary.push_back(1);
	}

	int value = 0;
	int j;

	for(int i = 0; i < binary.size(); i = j) {
		value = 0;

		for(j = i; j < i+4 && j < binary.size(); j++) {
			value += binary[j] * pow(2, j-i);
		}

		base16_value.push_back(dec_hex[value]);
	}

	return base16_value;

}

int main() {

	//this is maybe the most inportant part
	//this is where we initialize our alfabet
	char alf_hex_1[17] = "0123456789ABCDEF";
	char alf_hex_2[17] = "0123456789abcdef";

	//and now we run through the values and map the to the char in its position
	//we need to map low cap char as also high cap chars
	for(int i = 0; i <= 15; i++) {
		dec_hex[i] = alf_hex_1[i];
	}

	for(int i = 0; i <= 15; i++) {
		hex_dec[alf_hex_1[i]] = i;
		hex_dec[alf_hex_2[i]] = i;
	}


	scanf(" %s ", digits);

	while(digits[0] != '-') {

		//now we just call the functions based on what we need:
			//converto to hex if we have a decimal value
			//convert to decimal if we have a hex value
		//note that  a hex value is determine, in this problem, by the "0x" initials
		if(digits[1] == 'x') {
			base10_value = convert_to_dec(digits);
			printf("%Ld\n", base10_value);
		} else {
			base10_value = atoll(digits);

			base16_value = convert_to_hex(base10_value);

			printf("0x");
			for(int i = (int)base16_value.size() - 1; i >= 0; i--) {
				printf("%c", base16_value[i]);
			}
			printf("\n");

		}

		scanf(" %s ", digits);
	}


	return 0;
}