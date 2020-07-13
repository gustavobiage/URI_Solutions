#include <stdlib.h>
#include <stdio.h>
#include <algorithm>

struct node {
	int value;
	struct node * next;
	struct node * previous;
};

int T;
int N;
int begin, end;
struct node * pointerBegin, * pointerEnd;
int arr[100];
int c;

void push_front(int v) {
	struct node * node = (struct node*) malloc(sizeof(struct node));
	node->value = v;
	if (pointerBegin == NULL) {
		pointerBegin = pointerEnd = node;
	} else {
		node->next = pointerBegin;
		pointerBegin->previous = node;
		pointerBegin = node;
	}
}

void push_back(int v) {
	struct node * node = (struct node*) malloc(sizeof(struct node));
	node->value = v;
	if (pointerBegin == NULL) {
		pointerBegin = pointerEnd = node;
	} else {
		node->previous = pointerEnd;
		pointerEnd->next = node;
		pointerEnd = node;
	}
}

int main() {
	c = 0;
	scanf("%d ", &T);
	while (T--) {
		c++;
		scanf("%d ", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d ", &arr[i]);
		}
		begin = 0;
		end = N-1;
		pointerBegin = pointerEnd = NULL;
		std::sort(arr, arr+N);
		push_back(arr[end--]);
		while (begin <= end) {
			int v[4];
			v[0] = abs(pointerBegin->value - arr[begin]);
			v[1] = abs(pointerEnd->value - arr[begin]);
			v[2] = abs(pointerBegin->value - arr[end]);
			v[3] = abs(pointerEnd->value - arr[end]);
			int m = -1;
			int index = -1;
			for (int i = 0; i < 4; i++) {
				if (v[i] > m) {
					m = v[i];
					index = i;
				}
			}
			switch(index) {
				case 0:
					push_front(arr[begin++]);
					break;
				case 1:
					push_back(arr[begin++]);
					break;
				case 2:
					push_front(arr[end--]);
					break;
				case 3:
					push_back(arr[end--]);
					break;
			}
		}
		struct node * aux = pointerBegin;
		int s = 0;
		while (aux->next != NULL) {
			s += abs(aux->value - aux->next->value);
			aux = aux->next;
		}
		printf("Case %d: %d\n", c, s);
	}
	return 0;
}