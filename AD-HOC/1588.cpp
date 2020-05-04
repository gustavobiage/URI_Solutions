#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

struct t {
	int gols;
	int vic;
	int points;
	char name[1000];
};

int T, N, M;
struct t arr[102];
map<string, int> m;
int a, b;
char s1[1000], s2[1000];
int i1, i2;

int compare(const struct t a, const struct t b) {
	if (a.points != b.points) {
		return a.points > b.points;
	} else 
	if (a.vic != b.vic) {
		return a.vic > b.vic;
	} else 
	if (a.gols != b.gols) {
		return a.gols > b.gols;
	} else {
		return m[a.name] < m[b.name];
	}
}

int main() {

	scanf("%d ", &T);

	while (T) {
		scanf("%d %d ", &N, &M);
		
		m.clear();

		for (int i = 0; i < 102; i++) {
			arr[i].gols = 0;
			arr[i].points = 0;
			arr[i].vic = 0;
		}
		
		for (int i = 0; i < N; i++) {
			scanf(" %s ", arr[i].name);
			m[arr[i].name] = i;
		}

		for (int i = 0; i < M; i++) {
			scanf("%d %s %d %s ", &a, s1, &b, s2);
			i1 = m[s1];
			i2 = m[s2];
			
			arr[i1].gols += a;
			arr[i2].gols += b;
			if (a > b) {
				arr[i1].vic += 1;
				arr[i1].points += 3;
			} else if (b > a) {
				arr[i2].vic += 1;
				arr[i2].points += 3;
			} else {
				arr[i1].points += 1;
				arr[i2].points += 1;
			}
		}

		std::sort(arr, arr + N, compare);

		for (int i = 0; i < N; i++) {
			printf("%s\n", arr[i].name);
		}
		T--;
	}
	return 0;
}