#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <set>
#include <string>

using namespace std;

char line[1001];
char prt[1001];
int len;
string str;
set<string> s;

void search(int index, int from) {
	if (index > 0) {
		prt[index] = '\0';
		str = prt;
		s.insert(str);
	}

	if (index >= len) {
		return;
	}

	set<char> already;
	for (int i = from; i < len; i++) {
		if (already.find(line[i]) == already.end()) {
			prt[index] = line[i];
			search(index+1, i+1);
			already.insert(line[i]);
		}
	}
}

int main() {

	while (scanf(" %s ", line) != EOF) {
		len = strlen(line);
		s.clear();
		search(0, 0);
		for (auto it = s.begin(); it != s.end(); ++it) {
			printf("%s\n", it->c_str());
		}
		printf("\n");
	}

	return 0;
}