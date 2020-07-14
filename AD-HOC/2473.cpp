#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const char * arr[] = {"azar", "azar", "azar", "terno", "quadra", "quina", "sena"};
int cnt[100];
int v, ans;

int main() {
	memset(cnt, 0, sizeof(int)*100);
	for (int i = 0 ; i < 6; i++) {
		scanf("%d ", &v);
		cnt[v]++;
	}
	ans = 0;
	for (int i = 0; i < 6; i++) {
		scanf("%d ", &v);
		if (cnt[v]--) {
			ans++;
		}
	}
	printf("%s\n", arr[ans]);
}