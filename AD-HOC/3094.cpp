#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int cnt[5];
char line[1001];
int len;
int n;

int main() {
	scanf("%d ", &n);
	while (n--) {
		scanf(" %s ", line);
		char c;
		memset(cnt, 0, sizeof(int)*5);
		for (int i = 0; line[i] != '\0'; i++) {
			c = line[i];
			if (c == '7') {
				cnt[0]++;
			} else if (c == 'Q') {
				if (cnt[0]) {
					cnt[0]--;
					cnt[1]++;
				}
			} else if (c == 'J') {
				if (cnt[1]) {
					cnt[1]--;
					cnt[2]++;
				}
			} else if (c == 'K') {
				if (cnt[2]) {
					cnt[2]--;
					cnt[3]++;
				}
			} else if (c == 'A') {
				if (cnt[3]) {
					cnt[3]--;
					cnt[4]++;
				}
			}
		}
		len = strlen(line);
		printf("%d\n", len-5*cnt[4]);
	}
}