#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <queue>

using namespace std;

int N;
int U, R, I;
int Ui, Ri, Ii;
int pu, pr, pi;
priority_queue<int> pq;

int isPower2(int n) {
	long double d = log(n) / log(2);
	if (abs(d - (int)d) < 1e-9) {
		return 1;
	}
	return 0;
}

void clear(priority_queue<int> * pq) {
	priority_queue<int> empty;
	pq->swap(empty);
}

int main() {

	while (1) {
		scanf("%d ", &N);
		
		if (!N) {
			break;
		}

		U = R = I = 0;

		for (int i = 0; i < N; i++) {
			scanf("%d %d %d ", &Ui, &Ri, &Ii);
			clear(&pq);
			
			pq.push(Ui);
			pu = isPower2(Ui);
			if (pu) {
				U += 1;
			}

			pq.push(Ri);
			pr = isPower2(Ri);
			if (pr) {
				R += 1;
			}

			pq.push(Ii);
			pi = isPower2(Ii);
			if (pi) {
				I += 1;
			}

			if (pq.top() == Ui && pu) {
				U += 1;
			} else if (pq.top() == Ri && pr) {
				R += 1;
			} else if (pq.top() == Ii && pi) {
				I += 1;
			}
		}

		if (U > R && U > I) {
			printf("Uilton\n");
		} else if (R > U && R > I) {
			printf("Rita\n");
		} else if (I > U && I > R) {
			printf("Ingred\n");
		} else {
			printf("URI\n");
		}
	}
	return 0;
}