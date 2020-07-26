#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct nodeA {
	struct nodeA * next;
	struct nodeA * previous;
	char c;
};

struct nodeN {
	struct nodeN * next;
	struct nodeN * previous;
	int index;
};

int N;
struct nodeA * beginA, * endA;
struct nodeN * beginN, * endN;
char line[1000000];
char toPrt[1000000];
int stack[1000000];
int pointer, cnt, v;
vector<string> ans;

void push_backA(char c) {
	struct nodeA * node = (struct nodeA*) malloc(sizeof(struct nodeA));
	node->c = c;
	if (beginA == NULL) {
		beginA = endA = node;
	} else {
		endA->next = node;
		node->previous = endA;
		endA = node;
	}
}

void push_backN(int i) {
	struct nodeN * node = (struct nodeN*) malloc(sizeof(struct nodeN));
	node->index = i;
	if (beginN == NULL) {
		beginN = endN = node;
	} else {
		endN->next = node;
		node->previous = endN;
		endN = node;
	}
}

int getIndex(int n) {
	struct nodeN * node = beginN;
	for (int i = 0; i < n-1; i++) {
		node = node->next;
	}
	if (node != endN) {
		if (node->previous != NULL) {
			node->previous->next = node->next;
		} else {
			beginN = node->next;
		}
		if (node->next != NULL) {
			node->next->previous = node->previous;
			node->previous = endN;
			endN->next = node;
			node->next = NULL;
			endN = node;
		}
	}
	return node->index;
}

char getChar(int n) {
	struct nodeA * node = beginA;
	for (int i = 0; i < n-1; i++) {
		node = node->next;
	}
	if (node != endA) {
		if (node->previous != NULL) {
			node->previous->next = node->next;
		} else {
			beginA = node->next;
		}
		if (node->next != NULL) {
			node->next->previous = node->previous;
			node->previous = endA;
			endA->next = node;
			node->next = NULL;
			endA = node;
		}
	}
	return node->c;
}

void build() {
	beginA = endA = NULL;
	beginN = endN = NULL;
	const char * alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; alf[i] != '\0'; i++) {
		push_backA(alf[i]);
	}
	for (int i = 1; i <= 26; i++) {
		push_backN(i);
	}
}

void reset() {
	const char * alf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	struct nodeA * na = beginA;
	for (int i = 0; alf[i] != '\0'; i++) {
		na->c = alf[i];
		na = na->next;
	}
	struct nodeN * nn = beginN;
	for (int i = 1; i <= 26; i++) {
		nn->index = i;
		nn = nn->next;
	}
}

int isDigit(char c) {
	return c >= '0' && c <= '9';
}

int main() {
	cnt = 0;
	build();
	while (scanf("%d ", &N) != EOF) {
		if (cnt) {
			reset();
			printf("\n");
		}
		cnt++;
		for (int n = 0; n < N; n++) {
			fgets(line, 10000, stdin);
			pointer = 0;
			stack[pointer++] = 0;
			char last = line[0];
			for (int i = 1; line[i] != '\0'; i++) {
				if (!isDigit(last) && isDigit(line[i])) {
					stack[pointer++] = i;
					last = line[i];
				} else if (!isDigit(line[i])) {
					last = line[i];
					line[i] = '\0';
				}
			}
			for (int i = 0; i < pointer; i++) {
				sscanf(&line[stack[i]], "%d ", &v);
				if (v != 27) {
					int index = getIndex(v);
					char c = getChar(index);
					toPrt[i] = c;
				} else {
					toPrt[i] = ' ';
				}
			}
			toPrt[pointer] = '\0';
			ans.push_back(toPrt);
		}
		sort(ans.begin(), ans.end());
		printf("LISTA #%d:\n", cnt);
		for (int i = 0; i < ans.size(); i++) {
			printf("%s\n", ans[i].c_str());
		}
		ans.clear();
	}
	return 0;
}