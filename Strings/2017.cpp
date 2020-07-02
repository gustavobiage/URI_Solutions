#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int K;
char word[100001];
char arr[100001];
int pointer;
int min;

int cmp() {
	int c = 0;
	for (int i = 0; word[i] != '\0' && arr[i] != 0; i++) {
		if (arr[i] != word[i]) {
			c++;
		}
	}
	int lenWord = strlen(word);
	int lenArr = strlen(arr);
	if (lenWord > lenArr) {
		c += strlen(word) - strlen(arr);
	} else {
		c += strlen(arr) - strlen(word);
	}
	return c;
}

int main() {
	scanf("%s ", word);
	scanf("%d ", &K);
	min = -1;
	pointer = -1;
	for (int i = 0; i < 5; i++) {
		scanf("%s ", arr);
		int v = cmp();
		if ((v < min || min == -1) && v <= K) {
			min = v;
			pointer = i;
		}
	}
	printf("%d\n", pointer+1);
	if (pointer != -1) {
		printf("%d\n", min);
	}
	return 0;
}