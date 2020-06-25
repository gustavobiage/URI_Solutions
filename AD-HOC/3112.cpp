#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#include <set>

#define LLU long long int unsigned
#define LLD long long int

using namespace std;

int N, M, T;
char line[20009];
char input[20009];
char pat[30][30];
int lps[30][30];
char match;
set<pair<int, int> > s;
map<char, string> m;
string str;
int c, len;

using namespace std;

void computeLPSArray(int index); 
  
void KMPSearch(int index) {
    int M = strlen(pat[index]); 
 
    int i = 0; 
    int j = 0; 
    while (i < N) { 
        if (pat[index][j] == line[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
            s.insert(make_pair(i-j, i-1));
            j = lps[index][j - 1]; 
        } 
  
        else if (i < N && pat[index][j] != line[i]) { 
            if (j != 0) 
                j = lps[index][j - 1]; 
            else
                i = i + 1; 
        } 
    } 
} 
  
void computeLPSArray(int index) { 
    int len = 0; 
  
    lps[index][0] = 0;
  
    int i = 1; 
    while (i < M) { 
        if (pat[index][i] == pat[index][len]) { 
            len++; 
            lps[index][i] = len; 
            i++; 
        } else { 
            if (len != 0) { 
                len = lps[index][len - 1]; 
  			} else { 
                lps[index][i] = 0; 
                i++; 
            } 
        } 
    } 
} 

void search(int start) {
	if (start == N) {
		c++;
		return;
	}
	auto it = s.lower_bound(make_pair(start, 0));
	for (; it != s.end() && it->first == start && c < 2; ++it) {
		search(it->second+1);
	}
}

int main() {
	scanf("%d ", &T);
	for (int i = 0; i < T; i++) {
		scanf(" %s %c ", pat[i], &match);
		str = pat[i];
		m[match] = str;
		M = strlen(pat[i]);
		computeLPSArray(i);
	}
	scanf(" %s ", input);
	int pointer = 0;
	for (int i = 0; input[i] != '\0'; i++) {
		str = m[input[i]];
		const char * c = str.c_str();
		for (int j = 0; c[j] != '\0'; j++) {
			line[pointer++] = c[j];
		}
	}
	line[pointer] = '\0';
	N = pointer;
	for (int i = 0; i < T; i++) {
		M = strlen(pat[i]);
		KMPSearch(i);
	}
	search(0);
	if (c == 2) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
}