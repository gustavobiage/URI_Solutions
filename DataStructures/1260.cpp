#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>

using namespace std;

int N;
char line[50];
int c, len, C;
map<string, int> m;
string str;

int main() {
	c = 0;
	scanf("%d", &N);
	scanf("%*c");
	scanf("%*c");
	while (N--) {
		if (c) {
			printf("\n");
		}
		c++;
		C = 0;
		m.clear();
		while (1) {
			if (fgets(line, 50, stdin) == NULL) {
				break;
			}
			len = strlen(line);
			if (line[len - 1] == '\n') {
				line[len-1] = '\0';
				len--;
			}
			if (!len) {
				break;
			}
			C++;
			str = line;
			m[str]++;
		}
		for (auto it = m.begin(); it != m.end(); ++it) {
			printf("%s %0.4lf\n", it->first.c_str(), 100 * (double) it->second / C);
		}
	}
	return 0;
}