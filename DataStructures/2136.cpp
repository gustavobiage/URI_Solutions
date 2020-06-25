#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <set>

using namespace std;

int len, m;
char ans[10];
char name[100000];
char f[100000];
set<string> Y, N;
string str;

int main() {
	m = 0;
	while (scanf("%s %s ", name ,ans)) {
		if (strcmp(name, "FIM") == 0) {
			break;
		}
		str = name;
		if (ans[0] == 'Y') {
			len = strlen(name);
			if (len > m) {
				m = len;
				strcpy(f, name);
			}
			Y.insert(str);
		} else {
			N.insert(str);
		}
	}

	for (auto it = Y.begin(); it != Y.end(); ++it) {
		printf("%s\n", it->c_str());
	}

	for (auto it = N.begin(); it != N.end(); ++it) {
		printf("%s\n", it->c_str());
	}
	printf("\nAmigo do Habay:\n%s\n", f);
	return 0;
}