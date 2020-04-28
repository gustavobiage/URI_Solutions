#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>

#define INF 2222222

using namespace std;

const char * ans = "Iloveyou!";
map<char, int> count;

int main() {

	char word[100002];
	int x;
	int min;

	while (scanf(" %s ", word) != EOF) {
		int len = strlen(word);
		for (int i = 0; i < len; i++) {
			count[word[i]] += 1;
		}

	}

	min = INF;

	for (int i = 0; i < strlen(ans); i++) {
		x = count[ans[i]];
		if (ans[i] == 'o') {
			x = x / 2;
		}

		if (min > x) {
			min = x;
		}
	}
	
	printf("%d\n", min);
	return  0;
}