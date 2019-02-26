#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <set>
#include <utility>
#include <string.h>
//2646

std::map<std::pair<char, int>, char> map;
std::map<char, int> counter;

std::set<char> searched;

int n, m;
char a, b;
char word_A[100], word_B[100];
int can;

int search(char looking, char from) {

	searched.insert(from);

	for(int i = 0; i < counter[from]; i++) {
		
		if(searched.find(map[std::make_pair(from, i)]) != searched.end()) continue;

		if(map[std::make_pair(from, i)] == looking) {
			return 1;
		} else {
			if(search(looking, map[std::make_pair(from, i)]) == 1) {
				return 1;
			}
		}
	}

	return 0;
}

int main() {

	scanf("%d %d ", &n, &m);

	for(int i = 0; i < n; i++) {
		scanf("%c %c ", &a, &b);
		map[std::make_pair(a, counter[a])] = b;
		counter[a]++;
	}
	// printf("DONE\n");
	for(int i = 0; i < m; i++) {
		scanf(" %s ", word_A);
		scanf(" %s ", word_B);
		
		if(strlen(word_A) == strlen(word_B)) can = 1;
		else can = 0;

		for(int j = 0; j < strlen(word_A); j++) {
			if(!can) break;

			if(word_A[j] == word_B[j]) continue;
			
			searched.clear();

			if(search(word_B[j], word_A[j])) {
				continue;
			} else {
				can = 0;
			}
		}

		if(!can) {
			printf("no\n");
		} else {
			printf("yes\n");
		}
	}

	return 0;
}