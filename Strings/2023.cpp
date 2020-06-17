#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char ** name;
int pointer;
int len;

char tolower(char c) {
	if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 'a'; 
	}
	return c;
}

int strclowcmp(char *a, char *b) {
    while (1) {
        int dif = tolower((unsigned char)*a) - tolower((unsigned char)*b);
        if (dif != 0 || !a[0]) {
            return dif;
        }
    	a++; b++;
    }
}

int cmp(const void * a, const void * b) {
	return strclowcmp(*((char **)a), *((char **)b));
}

int main() {
	name = (char **) malloc(sizeof(char *) * 1001);
	for (int i = 0; i < 1001; i++) {
		name[i] = (char *) malloc(sizeof(char)*100);
	}

	pointer = 0;
	while (fgets(name[pointer], 100, stdin) != NULL) {
		len = strlen(name[pointer]);
		if (name[pointer][len-1] == '\n') {
			name[pointer][len-1] = '\0';
		}
		pointer++;
	}
	
	qsort(name, pointer, sizeof(char *), cmp);
	printf("%s\n", name[pointer-1]);
	return 0;
}