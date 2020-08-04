#include <stdlib.h>
#include <stdio.h>
#include <stack>

using namespace std;

char line[10002];
stack<char> stack_;
char output[10002];
int pointer, lexicalError, syntaxError;
int last;

int getPriority(char c) {
	switch (c) {
		case '^': return 6;
		case '*': case '/': return 5;
		case '+': case '-': return 4;
		case '>': case '<': case '=': case '#': return 3;
		case '.': return 2;
		case '|': return 1;
	}
	return 0;
}

int isOperator(char c) {
	// return c == '+' || c == '-' || c == '*' || c == '.' || c == '|' ||
		// c == '<' || c == '>' || c == '=' || c == '#' || c == '^' || c == '/';
	return getPriority(c);
}

int isOperand(char c) {
	return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z' || c  >= '0' && c <= '9';
}

int getType(char c) {
	if (isOperand(c)) {
		return 1;
	}
	if (isOperator(c)) {
		return 2;
	}
	if (c == '(') {
		return 3;
	} else if (c == ')') {
		return 4;
	}
	return 0;
}

void prt(char c) {
	output[pointer++] = c;
}

int main() {
	while (scanf(" %s ", line) != EOF) {
		pointer = syntaxError = lexicalError = 0;
		if (isOperator(line[0])) {
			syntaxError = 1;
		}
		for (int i = 0; line[i] != '\0' && !lexicalError && !syntaxError; i++) {
			if (i) {
				int t = getType(line[i]);
				if (last == t && last == 2) {
					syntaxError = 1;
					continue;
				} else if (last == t && last == 1) {
					syntaxError = 1;
					continue;
				} else if (last == 3 && t == 2 || last == 4 && t == 1 || last == 1 && t == 3 || last == 2 && t == 4) {
					syntaxError = 1;
					continue;
				} else if (last == 3 && t == 4) {
					syntaxError = 1;
					continue;
				}
			}

			if (isOperand(line[i])) {
				prt(line[i]);
			} else if (line[i] == '(') {
				stack_.push(line[i]);
			} else if (line[i] == ')') {
				while (!stack_.empty() && stack_.top() != '(') {
					prt(stack_.top());
					stack_.pop();
				}

				if (!stack_.empty() && stack_.top() == '(') {
					stack_.pop();
				} else {
					syntaxError = 1;
				}
			} else {
				while (!stack_.empty() && getPriority(stack_.top()) >= getPriority(line[i]) && stack_.top() != '(') {
					prt(stack_.top());
					stack_.pop();
				}
				stack_.push(line[i]);
			}

			last = getType(line[i]);
			if (!last) {
				lexicalError = 1;
			}
		}
		while (!stack_.empty() && !syntaxError && !lexicalError) {
			if (stack_.top() == '(') {
				syntaxError = 1;
			}
			prt(stack_.top());
			stack_.pop();
		}
		
		stack<char> empty_;
		empty_.swap(stack_);

		if (syntaxError) {
			printf("Syntax Error!\n");
		} else if (lexicalError) {
			printf("Lexical Error!\n");
		} else {
			output[pointer] = '\0';
			printf("%s\n", output);
		}
	}
	return 0;
}