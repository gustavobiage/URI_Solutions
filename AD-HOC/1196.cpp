#include <stdlib.h>
#include <stdio.h>
#include <map>

using namespace std;

map<char, char> m;
int init() {
	char line0[] = {'`', '1', '2', '3', '4', '5','6', '7', '8', '9', '0', '-', '='};
	char line1[] = {'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '[', ']', '\\'};
	char line2[] = {'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ';', '\''};
	char line3[] = {'Z', 'X', 'C', 'V', 'B', 'N', 'M', ',', '.', '/'};
	
	for (int i = 0; i < 12; i++) {
		m[line0[i+1]] = line0[i];
	}

	for (int i = 0; i < 12; i++) {
		m[line1[i+1]] = line1[i];
	}

	for (int i = 0; i < 10; i++) {
		m[line2[i+1]] = line2[i];
	}

	for (int i = 0; i < 9; i++) {
		m[line3[i+1]] = line3[i];
	}
}

char text[1000000];
int main() {
	init();
	while (fgets(text, 1000000, stdin) != NULL) {
		for (int i = 0; text[i] != '\n'; i++) {
			if (m.find(text[i]) != m.end()) {
				printf("%c", m[text[i]]);
			} else {
				printf("%c", text[i]);
			}
		}
		printf("\n");
	}
	return 0;
}