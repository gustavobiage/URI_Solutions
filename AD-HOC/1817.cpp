#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <math.h>

#define LLD long long int

using namespace std;

int c;
int n, m;
unsigned char w1[108], w2[1009];
map<int, LLD> previous;
int found[600][108];
int size_[600];

int main() {
	c = 0;
	while (1) {
		scanf("%d %d ", &m, &n);
		if (!n && !m) {
			break;
		}
		scanf("%s ", w1);
		scanf("%s ", w2);
		memset(size_, 0, sizeof(int) * 600);
		for (int i = m-1; i >= 0; i--) {
			unsigned char c = w1[i];
			found[c][size_[c]++] = i;
		}
		previous.clear();
		for (int i = 0; i < n; i++) {
			unsigned char c = w2[i];
			for (int j = 0; j < size_[c]; j++) {
				int index = found[c][j];
				if (index != 0) {
					previous[index] += previous[index-1];
				} else {
					previous[index]++;
				}
			}
		}
		printf("Instancia %d\n", ++c);
		printf("%Ld\n", previous[m-1]);
		printf("\n");
	}
	return 0;
}