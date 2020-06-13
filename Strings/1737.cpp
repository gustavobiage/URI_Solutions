#include <stdlib.h>
#include <stdio.h>
#include <utility>
#include <map>
#include <string.h>

using namespace std;

struct dig {
	char a;
	char b;
	int freq;
};

int N;
char line[102], word[102];
int pointer;
struct dig list[256*256];
map<pair<char, char>, struct dig*> m;
int len, c;

void addDig(char c1, char c2) {
	pair<char, char> p = make_pair(c1, c2);
	struct dig * d; 
	if (m.find(p) != m.end()) {
		d = m[p];
	} else {
		d = &list[pointer];
		d->a = c1;
		d->b = c2;
		d->freq = 0;
		m[p] = d;
		pointer++;
	}
	d->freq++;
}

int cmp(const void * a, const void * b) {
	struct dig v1 = *((struct dig*)a);
	struct dig v2 = *((struct dig*)b);
	if (v1.freq != v2.freq) {
		return v2.freq - v1.freq;
	} else {
		if (v1.a != v2.a) {
			return v1.a - v2.a;
		} else {
			return v1.b - v2.b;
		}
	}
}

int main() {
	while (1) {
		scanf("%d", &N);
		scanf("%*c");
		if (!N) {
			break;
		}
		m.clear();
		pointer = 0;
		c = 0;
		char last = 0;
		for (int i = 0; i < N; i++) {
			fgets(line, 102, stdin);
			len = strlen(line);
			line[len-1] = '\0';
			len--;
			if (last != 0 && len > 0) {
				addDig(last, line[0]);
			}
			for (int j = 0; j < len-1; j++) {
				addDig(line[j], line[j+1]);
			}
			last = line[len-1];
			c += len;
		}
		qsort(list, pointer, sizeof(struct dig), cmp);
		for (int i = 0; i < 5 && i < pointer; i++) {
			printf("%c%c %d %0.6Lf\n", list[i].a, list[i].b, list[i].freq, (long double)list[i].freq/(c-1));
		}
		printf("\n");
	}
	return 0;
}