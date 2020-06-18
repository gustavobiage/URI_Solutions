#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct o {
	char comp1[10000];
	char comp2[10000];
	char rest[10000];
};

int N;
struct o arr[67];
char line[10000];
int len, c;

int cmp(const void * a, const void * b) {
	struct o * v1 = (struct o*)a;
	struct o * v2 = (struct o*)b;
	int c = strcmp(v1->comp1, v2->comp1); 
	if (c != 0) {
		return c;
	} else {
		c = strcmp(v1->comp2, v2->comp2);
		if (c != 0) {
			return -c;
		} else {
			c = strcmp(v1->rest, v2->rest);
			return c;
		}
	}
}

int main() {
	c = 0;
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		if (c) {
			printf("\n");
		}
		c++;
		for (int i = 0; i < N; i++) {
			fgets(arr[i].rest, 10000, stdin);
			len = strlen(arr[i].rest);
			if (arr[i].rest[len-1] == '\n') {
				arr[i].rest[len-1] = '\0';
			}
			fgets(line, 10000, stdin);
			len = strlen(line);
			if (line[len-1] == '\n') {
				line[len-1] = '\0';
				len--;
			}
			int pointer;
			for (pointer = 0; line[pointer] != ' '; pointer++);
			line[pointer] = '\0';
			pointer++;
			strcpy(arr[i].comp1, &line[0]);
			strcpy(arr[i].comp2, &line[pointer]);
		}
		
		qsort(arr, N, sizeof(struct o), cmp);
		for (int i = 0; i < N; i++) {
			printf("%s %s %s\n", arr[i].comp1, arr[i].comp2, arr[i].rest);
		}
	}
	return 0;
}