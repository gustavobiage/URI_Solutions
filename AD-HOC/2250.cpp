#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int J;

struct j {
	char name[20];
	int points;
};

struct j arr[1001];
int points[13];
int c;
int ind;

int basic_cmp(const void * a, const void * b) {
	int v1 = *((int *)a);
	int v2 = *((int *)b);
	return v1 - v2;
}

int j_cmp(const void *a, const void * b) {
	struct j v1 = *((struct j *) a);
	struct j v2 = *((struct j *) b);
	if (v2.points != v1.points) {
		return v2.points - v1.points;
	}
	return strcmp(v1.name, v2.name);
}

int main() {
	c = 0;
	while (1) {
		scanf("%d ", &J);
		if (!J) {
			break;
		}
		c++;
		for (int i = 0; i < J; i++) {
			scanf(" %s ", arr[i].name);
			for (int j = 0; j < 12; j++) {
				scanf("%d ", &points[j]);
			}
			qsort(points, 12, sizeof(int), basic_cmp);
			int sum = 0;
			for (int j = 1; j < 11; j++) {
				sum += points[j];
			}
			arr[i].points = sum;
		}

		qsort(arr, J, sizeof(struct j), j_cmp);
		printf("Teste %d\n", c);
		ind = 1;
		for (int i = 0; i < J; i++) {
			if (i >= 1) {
				if (arr[i].points != arr[i-1].points) {
					ind = i+1;
				}
				printf("%d %d %s\n", ind, arr[i].points, arr[i].name);
			} else {
				printf("%d %d %s\n", i+1, arr[i].points, arr[i].name);
			}
		}
		printf("\n");
	}
	return 0;
}