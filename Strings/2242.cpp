#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char arr[100];
char line[100];
char c;
int pointer;
const char * vogals = "aeiou";
int res;

int isVogal(char c) {
	for (int i = 0; vogals[i] != '\0'; i++) {
		if (vogals[i] == c) {
			return 1;
		}
	}
	return 0;
}

int main() {
	scanf("%s ", line);
	pointer = 0;
	for (int i = 0; line[i] != '\0'; i++) {
		if (isVogal(line[i])) {
			arr[pointer++] = line[i];
		}
	}
	arr[pointer] = '\0';
	int len = strlen(arr);
	res = 1;
	for (int i = 0; i < len/2; i++) {
		if (arr[i] != arr[len-i-1]) {
			res = 0;
			break;
		}
	}
	if (res) {
		printf("S\n");
	} else {
		printf("N\n");
	}
	return 0;
}