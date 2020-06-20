#include <stdlib.h>
#include <stdio.h>
#include <map>

#define NONE 0
#define END 1

using namespace std;

struct node {
	int size;
	struct node * m[30];
	int status;
};

int N;
struct node * firstWords[30];
char arr[100001][85];
char c;
struct node * node;
int cnt, res;

void insert(int a, int index, struct node * n) {
	char c = arr[a][index];
	if (c == '\0') {
		n->status = END;
	} else {
		if (n->m[c-'a'] == NULL) {
			struct node * node = (struct node*) malloc(sizeof(struct node));
			node->status = NONE;
			node->size = 0;
			n->m[c-'a'] = node;
			n->size++;
		}
		insert(a, index+1, n->m[c-'a']);
	}
}

int main() {
	while (scanf("%d ", &N) != EOF) {
		for (int i = 'a'; i <= 'z'; i++) {
			firstWords[i-'a'] = NULL;
		}
		for (int i = 0; i < N; i++) {
			scanf(" %s ", arr[i]);
			c = arr[i][0];
			if (firstWords[c-'a'] == NULL) {
				node = (struct node*) malloc(sizeof(struct node));
				node->size = 0;
				node->status = NONE;
				firstWords[c-'a'] = node;
			}
			insert(i, 1, firstWords[c-'a']);
		}
		int done;
		res = 0;
		for (int i = 0; i < N; i++) {
			cnt = 1;
			node = firstWords[arr[i][0]-'a'];
			done = node == NULL;
			for (int j = 1; arr[i][j] != '\0'; j++) {
				if (done || node->size > 1 || node->m[arr[i][j]-'a'] == NULL || node->status == END) {
					cnt++;
				}
				if (!done) {
					node = node->m[arr[i][j]-'a'];
					done = node == NULL;
				}
			}
			res += cnt;
		}
		printf("%0.2lf\n", (double) res / N);
	}
	
	return 0;
}