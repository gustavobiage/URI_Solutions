#include <stdlib.h>
#include <stdio.h>

int N;
char line[3][205];
char digit;
int n;

void insert(int v, int u) {
	// printf("insert %d on %d\n", v, u);
	switch(v) {
		case 1: case 2: case 3: case 4:
		case 5: case 6: case 7: case 8:
		line[0][u] = '*';
		break;
		default:
		line[0][u] = '.';
	}

	switch(v) {
		case 3: case 4:
		case 6: case 7: case 9: case 0:
		line[0][u+1] = '*';
		break;
		default:
		line[0][u+1] = '.';
	}

	switch(v) {
		case 2: case 6: case 7: case 8: 
		case 9: case 0:
		line[1][u] = '*';
		break;
		default:
		line[1][u] = '.';
	}

	switch(v) {
		case 4: case 5: case 7: case 8: 
		case 0:
		line[1][u+1] = '*';
		break;
		default:
		line[1][u+1] = '.';
	}

	line[2][u] = '.';

	line[2][u+1] = '.';
	// printf("%c%c\n%c%c\n%c%c\n", line[0][u]);
}

int eval(int index) {
	if (line[0][index] == '.' && line[0][index+1] == '*' &&
		line[1][index] == '*' && line[1][index+1] == '*' &&
		line[2][index] == '.' && line[2][index+1] == '.') {
		//0
		return 0;
	} else if (line[0][index] == '*' && line[0][index+1] == '.' &&
			line[1][index] == '.' && line[1][index+1] == '.' &&
			line[2][index] == '.' && line[2][index+1] == '.') {
		//1
		return 1;
	} else if (line[0][index] == '*' && line[0][index+1] == '.' &&
			line[1][index] == '*' && line[1][index+1] == '.' &&
			line[2][index] == '.' && line[2][index+1] == '.') {
	//2
		return 2;
	} else if (line[0][index] == '*' && line[0][index+1] == '*' &&
			line[1][index] == '.' && line[1][index+1] == '.' &&
			line[2][index] == '.' && line[2][index+1] == '.') {
	//3
		return 3;
	} else if (line[0][index] == '*' && line[0][index+1] == '*' &&
			line[1][index] == '.' && line[1][index+1] == '*' &&
			line[2][index] == '.' && line[2][index+1] == '.') {
	//4
		return 4;
	} else if (line[0][index] == '*' && line[0][index+1] == '.' &&
			line[1][index] == '.' && line[1][index+1] == '*' &&
			line[2][index] == '.' && line[2][index+1] == '.') {
	//5
		return 5;
	} else if (line[0][index] == '*' && line[0][index+1] == '*' &&
			line[1][index] == '*' && line[1][index+1] == '.' &&
			line[2][index] == '.' && line[2][index+1] == '.') {
	//6
		return 6;
	} else if (line[0][index] == '*' && line[0][index+1] == '*' &&
			line[1][index] == '*' && line[1][index+1] == '*' &&
			line[2][index] == '.' && line[2][index+1] == '.') {
	//7
		return 7;
	} else if (line[0][index] == '*' && line[0][index+1] == '.' &&
			line[1][index] == '*' && line[1][index+1] == '*' &&
			line[2][index] == '.' && line[2][index+1] == '.') {
	//8
		return 8;
	} else if (line[0][index] == '.' && line[0][index+1] == '*' &&
			line[1][index] == '*' && line[1][index+1] == '.' &&
			line[2][index] == '.' && line[2][index+1] == '.') {
	//9
		return 9;
	}

	return -1;
}

int main() {
	int index;
	char c;
	while (1) {
		scanf("%d ", &N);
		
		if (!N)
			break;

		scanf("%c ", &c);
		index = 0;
		int f = 1;
		if (c == 'S') {
			for (int i = 0; i < N; i++) {
				scanf("%c", &digit);
				n = digit - '0';
				insert(n, index);
				index += 2;
			}
			// Drop \n
			scanf("%*c");
			for (int j = 0; j < 3; j++) {
				f = 1;
				for (int i = 0; i < N; i++) {
					if (f) {
						f = 0;
						printf("%c%c", line[j][i*2], line[j][i*2 + 1]);
					} else {
						printf(" %c%c", line[j][i*2], line[j][i*2 + 1]);
					}
				}
				printf("\n");
			}
		} else if (c == 'B') {
			for (int j = 0; j < 3; j++) {
				for (int i = 0; i < N; i++) {
					scanf(" %s ", &line[j][i*2]);
				}
			}
			for (int i = 0; i < N; i++) {
				printf("%d", eval(i*2));
			}
			printf("\n");
		}
	}
	return 0;
}