#include <stdlib.h>
#include <stdio.h>

#define LLD long long int

using namespace std;

LLD arr[1000001];
LLD sum;

struct node {
	int index;
	struct node * next;
	struct node * previous;
};

struct node * head;
struct node * tail;
int size;

void insertTail(int index) {
	struct node * n = (struct node*) malloc(sizeof(struct node));
	n->index = index;
	if (size) {
		tail->next = n;
		n->previous = tail;
		tail = n;
	} else {
		tail = head = n;
	}
	size++;
}

int peakHead() {
	return head->index;
}

int peakTail() {
	return tail->index;
}

void popTail() {
	if (size) {
		tail = tail->previous;
		size--;
	}
}

void popHead() {
	if (size) {
		head = head->next;
		size--;
	}
}

void clear() {
	while (size) {
		popHead();
	}
}

int N, K, S;
int T;

int main() {
	scanf("%d ", &T);
	while (T) {
		sum = 0;
		head = tail = NULL;
		size = 0;
		scanf("%d %d %d ", &N, &K, &S);
		arr[0] = S;
		insertTail(0);
		for (int i = 1; i < N; ++i) {
		    arr[i] = (1LL*arr[i-1]*1103515245 + 12345) % (2147483648LL);
		    if (i >= K) {	
		    	sum += arr[peakHead()];
		    }
			while (size && arr[peakTail()] <= arr[i]) {
				popTail();
			}
			insertTail(i);
			if (peakHead() == i - K) {
				popHead();
			}
		}
		sum += arr[peakHead()];
		printf("%Ld\n", sum);
		T--;
	}
	return 0;
}