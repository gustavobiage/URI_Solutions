#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>

using namespace std;

struct t {
	char name[1000];
	int p;
};

int N;
struct t arr[101];
map<string, int> map_;
char n1[1000], n2[1000];
int g1, g2;

int cmp(const void * a, const void *b) {
	struct t v1 = *((struct t*)a);
	struct t v2 = *((struct t*)b);
	return v2.p - v1.p;
}

int main() {
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		for (int i = 0; i < N; i++) {
			scanf("%s %d ", arr[i].name, &arr[i].p);
			map_[arr[i].name] = i;
		}
		int index1, index2;
		for (int i = 0; i < N/2; i++) {
			scanf("%s %d-%d %s ", n1, &g1, &g2, n2);
			index1 = map_[n1];
			index2 = map_[n2];
			arr[index1].p += g1*3;
			arr[index2].p += g2*3;
			if (g1 == g2) {
				arr[index1].p += 1;
				arr[index2].p += 1;
			} else if (g1 > g2) {
				arr[index1].p += 5;
			} else if (g2 > g1) {
				arr[index2].p += 5;
			}
		}
		qsort(arr, N, sizeof(struct t), cmp);
		if (!strcmp(arr[0].name, "Sport")) {
			printf("O Sport foi o campeao com %d pontos :D\n", arr[0].p);
		} else {
			printf("O Sport nao foi o campeao. O time campeao foi o %s com %d pontos :(\n", arr[0].name, arr[0].p);
		}
		printf("\n");
	}
	return 0;
}