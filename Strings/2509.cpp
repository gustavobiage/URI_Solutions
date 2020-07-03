#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define STR_PSTREE "pstree"
#define STR_TCIRCLE "Tcircle"

void parse_new_tree();

int pointer;
int len;
int res;
char line[10000];
char word[10000];

int isAlf(char c) {
	return c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z';
}

char peak() {
	if (pointer < len) {
		return line[pointer];
	}
	return 0;
}

char readWord() {
	int i = 0;
	while (isAlf(line[pointer]) && pointer < len) {
		word[i++] = line[pointer++];
	}
	word[i] = '\0';
}

char readChar() {
	return line[pointer++];
}

void parse_new_node() {
	int count = 0;
	char c;
	c = readChar();
	if (c == '{') {
		readWord();
		// WORD LENGTH ??
		if (strlen(word) == 1) {
			count++;
		}
	}
	c = readChar();
	res = res && count == 1 && c == '}';
}

void parse_tree_par1() {
	int count = 0;
	char c;
	c = readChar();
	if (c == '{') {
		c = readChar();
		if (c == '\\') {
			readWord();
			if (!strcmp(word, STR_TCIRCLE)) {
				parse_new_node();
				count++;
			}
		}
	}
	c = readChar();
	res = res && count == 1 && c == '}';
}

void parse_tree_par2() {
	int count = 0;
	char c;
	c = readChar();
	if (c == '{') {
		for (int i = 0; i < 2; i++) {
			c = peak();
			if (c == '\\') {
				readChar();
				readWord();
				if (!strcmp(word, STR_TCIRCLE)) {
					parse_new_node();
					count++;
				} else if (!strcmp(word, STR_PSTREE)) {
					parse_new_tree();
					count++;
				}
			} else if (c == '}') {
				break;
			}
		}
	}
	c = readChar();
	res = res && count <= 2 && c == '}';
}

void parse_new_tree() {
	parse_tree_par1(); // First parameter
	parse_tree_par2(); // Second parameter
}

void eval() {
	int count = 0;
	char c = readChar();
	
	if (c == '\\') {
		readWord();
		if (!strcmp(word, STR_PSTREE)) {
			count++;
			parse_new_tree();
		} else if (!strcmp(word, STR_TCIRCLE)) {
			count++;
			parse_new_node();
		}
	}

	res = res && count == 1;
}

int main() {
	while (scanf("%s ", line) != EOF) {
		res = 1;
		len = strlen(line);
		word[0] = '\0';
		pointer = 0;
		eval();
		res = res && pointer == len;
		if (res) {
			printf("SIM\n");
		} else {
			printf("NAO\n");
		}
	}
	return 0;
}