#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <set>
#include <string>

using namespace std;

int T, N;
const char * CHIRRIN = "chirrin";
const char * CHIRRION = "chirrion";
char word[4000002];
char magic[4000002];
set<string> s;

int main() {
	scanf("%d ", &T);
	while (T--) {
		scanf("%d ", &N);
		s.clear();
		for (int i = 0; i < N; i++) {
			scanf("%s %s ", word, magic);
			if (strcmp(magic, CHIRRION) == 0) {
				s.erase(word);
			} else if (strcmp(magic, CHIRRIN) == 0) {
				s.insert(word);
			}
		}
		printf("TOTAL\n");
		for (auto it = s.begin(); it != s.end(); ++it) {
			printf("%s\n", it->c_str());
		}
	}
}