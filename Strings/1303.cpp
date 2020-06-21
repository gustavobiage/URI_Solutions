#include <stdlib.h>
#include <stdio.h>

struct t {
	int id;
	int p;
	int received;
	int thrown;
};

struct t arr[102];
int N, C;
int a, b, c, d;

int cmp(const void * a, const void * b) {
	struct t v1 = *((struct t*)a);
	struct t v2 = *((struct t*)b);
	double avg1, avg2;
	if (v1.received != 0) {
		avg1 = (double) v1.thrown/v1.received;
	} else {
		avg1 = v1.thrown;
	}
	if (v2.received != 0) {
		avg2 = (double) v2.thrown/v2.received;
	} else {
		avg2 = v2.thrown;
	}
	if (v1.p != v2.p) {
		return v2.p - v1.p;
	} else if (abs(avg1-avg2) > 1e-8) {
		if (avg1 > avg2) {
			return -1;
		} else {
			return 1;
		}
	} else {
		return v1.id - v2.id;
	}
}

int main() {
	C = 0;
	while (1) {
		scanf("%d ", &N);
		if (!N) {
			break;
		}
		if (C) {
			printf("\n");
		}
		C++;
		for (int i = 0; i < N; i++) {
			arr[i].id = i+1;
			arr[i].p = 0;
			arr[i].received = 0;
			arr[i].thrown = 0;
		}
		for (int i = 0; i < N*(N-1) / 2; i++) {
			scanf("%d %d %d %d ", &a, &b, &c, &d);
			arr[a-1].received += d;
			arr[a-1].thrown += b;
			arr[c-1].received += b;
			arr[c-1].thrown += d;
			if (b > d) {
				arr[a-1].p += 2;
				arr[c-1].p += 1;
			} else {
				arr[c-1].p += 2;
				arr[a-1].p += 1;
			}
		}
		qsort(arr, N, sizeof(struct t), cmp);
		printf("Instancia %d\n", C);
		for (int i = 0; i < N; i++) {
			if (!i) {
				printf("%d", arr[i].id);
			} else {
				printf(" %d", arr[i].id);
			}
		}
		printf("\n");
	}
	return 0;
}