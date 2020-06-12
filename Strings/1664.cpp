#include <stdlib.h>
#include <stdio.h>
#include <set>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

char line[102];
char word[102];
int pointers[102];
int push_, is_word;

set<string> s;
string str;
vector<int> vec;

int sum, d;

int euclides(int a, int b) {
	if (a < b) {
		return euclides(b, a);
	}

	if (b == 0) {
		return a;
	}

	return euclides(b, a%b);
}

int main() {

	while (fgets(line, 102, stdin) != NULL) {
		push_ = 0;
		is_word = 0;
		for (int i = 0; line[i] != '\0'; i++) {
			if (line[i] >= 'A' && line[i] <= 'Z') {
				line[i] = line[i] - 'A' + 'a';
			}

			if (line[i] >= 'a' && line[i] <= 'z') {
				if (!is_word) {
					pointers[push_++] = i;
					is_word = 1;
				}
			} else {
				line[i] = '\0';
				is_word = 0;
			}
		}

		for (int i = 0; i < push_; i++) {
			sscanf(&line[pointers[i]], " %s ", word);
			if (strcmp(word, "bullshit") == 0) {
				vec.push_back((int)s.size());
				s.clear();
			} else {
				str = word;
				s.insert(word);
			}
		}
	}
	sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		sum += vec[i];
	}
	d = euclides(sum, (int)vec.size());
	printf("%d / %d\n", sum/d, (int)vec.size() / d);
	return 0;
}