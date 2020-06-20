#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int N, M;

int byte[100001];
int arr[100001];

int v, x, y;
char op;

long long int get(int index) { 
    index = index+1;
    long long int sum = 0;
    while (index) { 
        sum += byte[index]; 
    	index-=index&(-index); 
    }
    return sum; 
} 
  
void update(int index, int delta) { 
    index = index+1;
    while (index<=N) {
    	byte[index] += delta;
   		index += index & (-index); 
    } 
}

int main() {
	while (scanf("%d %d ", &N, &M) != EOF) {
		memset(byte, 0, sizeof(int)*100001);
		for (int i = 0; i < N; i++) {
			scanf("%d ", &v);
			if (v > 0) {
				arr[i] = 0;
			} else if (v == 0) {
				arr[i] = 100001;
			} else {
				arr[i] = 1;
			}
			update(i, arr[i]);
		}
		
		for (int i = 0; i < M; i++) {
			scanf("%c %d %d ", &op, &x, &y);
			x--;
			if (op == 'C') {
				if (y > 0) {
					y = 0;
				} else if (y == 0) {
					y = 100001;
				} else {
					y = 1;
				}
				int delta = arr[x] - y;
				arr[x] = y;
				update(x, -delta);
			} else if (op == 'P') {
				y--;
				long long int s = get(y) - get(x) + arr[x];
				if (s >= 100001) {
					printf("0");
				} else if (s % 2) {
					printf("-");
				} else {
					printf("+");
				}
			}
		}
		printf("\n");
	}
	return 0;
}

// Reference:
// https://www.geeksforgeeks.org/binary-indexed-tree-or-fenwick-tree-2/