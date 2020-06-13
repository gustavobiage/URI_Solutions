#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

int T;
int vetor[30001];
char input[100002];
char operations[100002];
int pointer, nextInput, finalInput;
stack<int> beginLoop;
char op;
int c, len;

int main() {
	c = 0;
	scanf("%d", &T);
	scanf("%*c");
	while (T) {
		scanf("%*c");
		fgets(input, 100002, stdin);
		len = strlen(input);
		if (input[len] == '\n') {
			input[len-1] == '\0';
			len--;
		}
		memset(vetor, 0, sizeof(int)*30001);
		fgets(operations, 100002, stdin);
		len = strlen(operations);
		if (operations[len] == '\n') {
			operations[len-1] == '\0';
			len--;
		}
		c++;
		printf("Instancia %d\n", c);
		pointer = nextInput = 0;
		finalInput = strlen(input) - 1;

		for (int i = 0; i < strlen(operations); i++) {
			op = operations[i];
			if (op == '>') {
				if (pointer == 29999) {
					pointer = 0;
				} else {
					pointer++;
				}
			} else if (op == '<') {
				if (pointer == 0) {
					pointer = 29999;
				} else {
					pointer--;
				}
			} else if (op == '+') {
				if (vetor[pointer] == 255) {
					vetor[pointer] = 0;
				} else {
					vetor[pointer]++;
				}
			} else if (op == '-') {
				if (vetor[pointer] == 0) {
					vetor[pointer] = 255;
				} else {
					vetor[pointer]--;
				}
			} else if (op == '.') {
				printf("%c", vetor[pointer]);
			} else if (op == ',') {
				if (nextInput < finalInput) {
					vetor[pointer] = input[nextInput++];
				} else {
					vetor[pointer] = 0;
				}
			} else if (op == '[') {
				if (vetor[pointer] != 0) {
					beginLoop.push(i);
				} else {
					int open = 1;
					i++;
					while (open > 0) {
						if (operations[i] == '[') {
							open++;
						} else if (operations[i] == ']') {
							open--;
						}
						i++;
					}
					i--;
				}
			} else if (op == ']') {
				if (vetor[pointer] != 0) {
					i = beginLoop.top();
				} else {
					beginLoop.pop();
				}
			} else if (op == '#') {
				for (int i = 0; i < 10; i++) {
					printf("%c", vetor[i]);
				}
			}
		}
		printf("\n\n");
		T--;
	}

	return 0;
}