#include <stdlib.h>
#include <stdio.h>

#define END 1
#define CONTINUE 0

#define WRONG 0
#define RIGHT 1
#define NIL 0

struct wall {
	int D;
	int A;
	int B;
};

int N;
struct wall arr[1009];
int DT, AT, BT;
int s, divisor;
int res;

int search() {
	int v;

	for (int i = 0; i < N; i++) {
	 	v = s * arr[i].D; 
		if (v >= arr[i].A * divisor && v <= arr[i].B * divisor) {
			// PASS
		} else {
			res = WRONG;
			return CONTINUE;
		}
	}

	v = s * DT;
	if (v >= AT * divisor && v <= BT * divisor) {
		res = RIGHT;
		return END;
	}

	res = WRONG;
	return CONTINUE;
}

int main() {

	scanf("%d ", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d %d %d ", &arr[i].D, &arr[i].A, &arr[i].B);
	}

	res = NIL;
	
	scanf("%d %d %d ", &DT, &AT, &BT);
	
	for (int i = 0; i < N; i++) {
		divisor = arr[i].D;

		s = arr[i].A;
		if (search()) {
			goto PRT;
		}

		s = arr[i].B;
		if (search()) {
			goto PRT;	
		}
	}

	divisor = DT;

	s = AT;
	if (search()) {
		goto PRT;
	}

	s = BT;
	if (search()) {
		goto PRT;	
	}

	PRT:
	if (res) {
		printf("Y\n");
	} else {
		printf("N\n");
	}

	return 0;
}