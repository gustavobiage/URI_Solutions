#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>

#define SUM 0
#define CONSTANT 1

using namespace std;

char line[100];
int len, type;
char a[20], b[20];
char x[20];
string str;
map<string, int> m;
int y, z;

int main() {

	while (fgets(line, 100, stdin) != NULL) {
		len = strlen(line);
		type = CONSTANT;
		for (int i = 0; i < len; i++) {
			if (line[i] == '+') {
				type = SUM;
			}
		}

		if (type == CONSTANT) {
			sscanf(line, " %s := %d ", x, &y);
			str = x;
			m[str] = y;
		} else {
			sscanf(line, " %s := %s + %s ", x, a, b);
			str = a;
			if (m.find(str) != m.end()) {
				y = m[str];
			} else {
				sscanf(a, " %d ", &y);
			}
			str = b;
			if (m.find(str) != m.end()) {
				z = m[str];
			} else {
				sscanf(b, " %d ", &z);
			}
			str = x;
			m[str] = y + z;
		}
	}

	printf("%d\n", m[str]);
	return 0;
}