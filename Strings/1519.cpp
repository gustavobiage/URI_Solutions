#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define REPLACE 0
#define INCREMENT 1

int max[30];
char words[30][10009];
char line[10009];
int lps[10009];
int N, M;
int pointer, status;
int len, c;
int stack[30], p;
int occurr;

void computeLPSArray(char* pat, int M, int* lps); 
  
void KMP(int index, int action) {
    int i = 0;
    int j = 0;
    while (i < N) { 
        if (words[index][j] == line[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) {
            if ((line[i] == ' ' || line[i] == '\0' || line[i] == '\n') &&
                (i-j-1 < 0 || line[i-j-1] == ' ')) {
                if (action == REPLACE) {
                    line[i-j+1] = '.';
                } else if (action == INCREMENT) {
                    occurr++;
                }
            }
            j = lps[j - 1]; 
        } 
  
        else if (i < N && words[index][j] != line[i]) { 
            if (j != 0) {
                j = lps[j - 1]; 
            }
            else {
                i = i + 1; 
            }
        } 
    } 
} 

void computeLPSArray(int index) { 
    int len = 0;
    lps[0] = 0;
  
    int i = 1; 
    while (i < M) { 
        if (words[index][i] == words[index][len]) { 
            len++; 
            lps[i] = len; 
            i++; 
        } else { 
            if (len != 0) { 
                len = lps[len - 1]; 
            } else { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
}

int main() {

	while (1) {
		fgets(line, 10009, stdin);
		if (strcmp(line, ".\n") == 0 || strcmp(line, ".") == 0) {
			break;
		}

		N = strlen(line);
		pointer = 0;
		for (int i = 0; i < 26; i++) {
			max[i] = 0;
		}

		while (sscanf(&line[pointer], " %s ", words[29]) != EOF) {
			len = strlen(words[29]);
			pointer += len + 1;
			M = len;
			computeLPSArray(29);
			occurr = 0;
			KMP(29, INCREMENT);
            if (max[words[29][0] - 'a'] < (len-2)*occurr && len > 2) {
				max[words[29][0] - 'a'] = (len-2)*occurr;
				strcpy(words[words[29][0] - 'a'], words[29]);
			}
		}

		p = c = 0;
		for (int i = 0; i < 26; i++) {
			if (max[i] > 0) {
				c++;
				stack[p++] = i;
				M = strlen(words[i]);
				computeLPSArray(i);
				KMP(i, REPLACE);
			}
		}

		int status = 0;
		for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) {
			if (status == 1) {
				if (line[i] == ' ') {
					status = 0;
					printf("%c", line[i]);
				}
			} else {
				if (line[i] == '.') {
					status = 1;
				}
				printf("%c", line[i]);
			}
		}

		printf("\n");
		printf("%d\n", c);
		for (int i = 0; i < p; i++) {
			printf("%c. = %s\n", stack[i] + 'a', words[stack[i]]);
		}
	}
	return 0;
}