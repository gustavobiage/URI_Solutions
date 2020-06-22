#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define NORMAL 0
#define SPECIAL 1

struct s {
	int cnt;
	char c;
	int status;
};

char c;
char last;
struct s arr[100000];
int cnt;
int pointer;
struct s s;

void eval() {
	s.cnt = cnt;
	s.c = last;
	if (cnt > 1) {
		s.status = SPECIAL;
	} else {
		s.status = NORMAL;
	}
	arr[pointer++] = s;
}

void prt() {
	int begin = 0;
	for (int i = 0; i < pointer; i++) {
		if (arr[i].cnt > 1) {
			if (begin) {
				printf("1");
			}
			begin = 0;
			while (arr[i].cnt) {
				int m = fmin(arr[i].cnt, 9);
				arr[i].cnt -= m;
				if (m == 1) {
					begin = 1;
					printf("1%c", arr[i].c);
					if (arr[i].c == '1') {
						printf("1");
					}
					begin = 1;
				} else {
					printf("%c%c", m + '0', arr[i].c);
				}
			}
		} else if (begin) {
			printf("%c", arr[i].c);
			if (arr[i].c == '1') {
				printf("1");
			}
		} else {
			printf("1%c", arr[i].c);
			if (arr[i].c == '1') {
				printf("1");
			}
			begin = 1;
		}
	}
	if (begin) {
		printf("1");
	}
	printf("\n");
}

int main() {
	cnt = 0;
	last = 2;
	while (scanf("%c", &c) != EOF) {
		if (c == '\n') {
			if (cnt != 0) {
				eval();
			}
			prt();
			pointer = 0;
			last = 2;
			cnt = 0;
		} else if (c == last) {
			cnt++;
		} else {
			if (cnt != 0) {
				eval();
			}
			cnt = 1;
			last = c;
		}
	}
	return 0;
}