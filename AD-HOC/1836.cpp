#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int T;
char name[10001];
int lvl;
const char * attr[] = {"HP", "AT", "DF", "SP"};
int BS, IV, EV;
int ans;
int c;

int main() {
	scanf("%d ", &T);
	c = 0;
	while (T--) {
		c++;
		scanf("%s %d ", name, &lvl);
		printf("Caso #%d: %s nivel %d\n", c, name, lvl);
		for (int i = 0; i < 4; i++) {
			scanf("%d %d %d ", &BS, &IV, &EV);
			ans = ((IV + BS + sqrt(EV)/8 + 50*(!i)) * lvl) / 50 + 5 + 5*(!i);
			printf("%s: %d\n", attr[i], ans);
		}
	}
	return 0;
}