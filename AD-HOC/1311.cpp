#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <set>
#include <math.h>

using namespace std;

struct s {
	struct s * e;
	struct s * d;
	int id;
};

int S, B;
int a, b;
struct s arr[100002];
map<int, struct s *> m;
set<int> set_;
int m_index = 1;

void remove(int a, int b) {
	struct s * p1 = arr[a].e;
	struct s* p2 = arr[b].d;

	if (p1 != NULL && p2 != NULL) {
		p1->d = p2;
		p2->e = p1;
	} else if (p1 != NULL) {
		p1->d = NULL;
	} else if (p2 != NULL) {
		p2->e = NULL;
	}
}

int main() {
	for (int i = 1; i <= 100000; i++) {
		arr[i].id = i;
	}

	while (1) {
		scanf("%d %d ", &S, &B);
		
		if (!S && !B) {
			break;
		}

		set_.clear();

		for (int i = 1; i <= S; i++) {
			set_.insert(i);
		}

		for (int i = m_index; i <= S; i++) {
			m[i] = &arr[i];
		}

		m_index = fmax(m_index, S+1);

		arr[1].e = NULL;
		arr[S].d = NULL;
		if (S != 1) {
			arr[1].d = &arr[2];
			arr[S].e = &arr[S-1];
		}

		for (int i = 2; i < S-1; i++) {
			arr[i].d = &arr[i+1];
			arr[i].e = &arr[i-1];
		}

		for (int i = 0; i < B; i++) {
			scanf("%d %d ", &a, &b);
			remove(a, b);
			for (int j = a; j <= b; j++) {
				set_.erase(j);
			}

			set<int>::iterator it1 = set_.lower_bound(a);
			if (it1 != set_.begin()) {
				it1--;
				printf("%d ", *it1);
			} else {
				printf("* ");
			}

			set<int>::iterator it2 = set_.upper_bound(b);
			if (it2 != set_.end()) {
				printf("%d\n", *it2);
			} else {
				printf("*\n");
			}
		}
		printf("-\n");
	}
	return 0;
}