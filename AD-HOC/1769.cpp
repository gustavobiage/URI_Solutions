#include <stdlib.h>
#include <stdio.h>

char arr[10];
int barr[3];
char b[3];
int s;
int main() {

	while (scanf("%c%c%c.%c%c%c.%c%c%c-%c%c ",
		&arr[1], &arr[2], &arr[3], 
		&arr[4], &arr[5], &arr[6], 
		&arr[7], &arr[8], &arr[9], 
		&b[1], &b[2])
		!= EOF) {
		
		s = 0;
		for (int i = 1; i <= 9; i++) {
			s += (arr[i] - '0') * i;
		}
		barr[1] = (s % 11) % 10;
		s = 0;
		for (int i = 1; i <= 9; i++) {
			s += (arr[i] - '0') * (10-i);
		}
		barr[2] = (s % 11) % 10;
		if (barr[1] + '0' == b[1] && barr[2] + '0' == b[2]) {
			printf("CPF valido\n");
		} else {
			printf("CPF invalido\n");
		}
	}
	

	return 0;
}