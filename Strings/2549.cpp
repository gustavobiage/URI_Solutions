#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <string>
#include <string.h>

using namespace std;

set<string> s;
string str;
int N;
char A[100];
char line[1000];
char name[1000];
char id[1000];
int pointer, index_;
int cnt;

int readName() {
	while (line[pointer] == ' ' && line[pointer] != '\0' && line[pointer] != '\n') {
		pointer++;
	}
	if (line[pointer] == '\0' || line[pointer] == '\n') {
		return EOF;
	}
	sscanf(&line[pointer], "%s ", name);
	pointer += strlen(name)+1;
	return 1;
}

int main() {
	while (scanf("%d %s", &N, A) != EOF) {
		scanf("%*c");
		cnt = 0;
		s.clear();
		for (int i = 0; i < N; i++) {
			fgets(line, 1000, stdin);
			pointer = index_ = 0;
			while (readName() != EOF) {
				id[index_++] = name[0];
			}
			for (int i = 0; A[i] != '\0'; i++) {
				id[index_++] = A[i];
			}
			id[index_] = '\0';
			if (s.find(id) != s.end()) {
				cnt++;
			} else {
				s.insert(id);
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}