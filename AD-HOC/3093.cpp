#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cnt[20];
int n;
char line[1009];

int eval(char c) {
	if (c >= '0' && c <= '7') {
		return c - '0';
	}
	switch (c) {
		case 'A': return 1;
		case 'J': return 11;
		case 'Q': return 12;
		case 'K': return 13;
	}
	return -1;
}

int main() {
	scanf("%d ", &n);
	while (n--) {
		scanf(" %s ", line);
		memset(cnt, 0, sizeof(int)*20);
		for (int i = 0; line[i] != '\0'; i++) {
			cnt[eval(line[i])]++;
		}
		if (cnt[1] && cnt[11] && cnt[12] && cnt[13]) {
			printf("Aaah muleke\n");
		} else {
			printf("Ooo raca viu\n");
		}
	}
	return 0;
}