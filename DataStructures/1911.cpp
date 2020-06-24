#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>

using namespace std;

int N, M, c;
string strN, strA, strB;
char arr[25];
map<string, string> m;

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		m.clear();
		c = 0;
		for (int i = 0; i < N; i++) {
			scanf("%s ", arr);
			strN = arr;
			scanf("%s ", arr);
			strA = arr;
			m[strN] = strA;
		}
		scanf("%d ", &M);
		for (int i = 0; i < M; i++) {
			scanf("%s ", arr);
			strN = arr;
			scanf("%s ", arr);
			strA = arr;
			if (m.find(strN) != m.end()) {
				const char * a = m[strN].c_str();
				const char * b = strA.c_str();
				int cnt = 0;
				for (int j = 0; a[j] != '\0'; j++) {
					if (a[j] != b[j]) {
						cnt++;
					}
				}
				if (cnt > 1) {
					c++;
				}
			}
		}
		printf("%d\n", c);
	}
	return 0;
}