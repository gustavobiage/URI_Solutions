#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <map>
#include <string.h>

using namespace std;

int L, N;
char key[1000], name[1000];
map<string, string> map_;

int isVogal(char c) {
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main() {
	scanf("%d %d ", &L, &N);
	for (int i = 0; i < L; i++) {
		scanf("%s %s ", key, name);
		map_[key] = name;
	}
	for (int i = 0; i < N; i++) {
		scanf("%s ", name);
		if (map_.find(name) != map_.end()) {
			printf("%s\n", map_[name].c_str());
		} else {
			int len = strlen(name);
			if (len > 1 && !isVogal(name[len-2]) && name[len-1] == 'y') {
				name[len-1] = '\0';
				printf("%sies\n", name);
			} else if (
				name[len-1] == 'o' ||
				name[len-1] == 's' ||
				name[len-1] == 'x' ||
				!strcmp(&name[len-2], "ch") ||
				!strcmp(&name[len-2], "sh")
				) {
				printf("%ses\n", name);
			} else {
				printf("%ss\n", name);
			}
		}
	}
	return 0;
}