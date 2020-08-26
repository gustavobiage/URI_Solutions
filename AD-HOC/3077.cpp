#include <stdlib.h>
#include <stdio.h>

struct node {
	int v;
	struct node * next;
	struct node * previous;
};

struct node list[1001];
int n, k;
int arr[1001];

int main() {
	scanf("%d %d ", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d ", &list[i].v);
	}
	list[0].previous = &list[n-1];
	for (int i = 1; i < n; i++) {
		list[i].previous = &list[i-1];
	}

	list[n-1].next = &list[0];
	for (int i = 0; i < n-1; i++) {
		list[i].next = &list[i+1];
	}

	struct node * node;	
	for (int i = 0; i < n; i++) {
		if (i) {
			arr[i] = arr[i-1] + list[i].v - node->v;
			node = node->next;
			printf(" %d", arr[i]);
		} else {
			node = &list[i];
			for (int j = 0; j < k; j++) {
				arr[i] += node->v;
				node = node->previous;
			}
			node = node->next;
			printf("%d", arr[i]);
		}
	}

	printf("\n");
	return 0;
}