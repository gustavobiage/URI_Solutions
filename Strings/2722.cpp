#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ONE 0
#define ZERO 1

int T;
char l1[102], l2[102];
int len1, len2;
char name[204];
int state;
int p, p1, p2;
int main() {
	scanf("%d ", &T);
	while (T) {
		fgets(l1, 102, stdin);
		fgets(l2, 102, stdin);
		len1 = strlen(l1);
		l1[len1-1] = '\0';
		len1--;

		len2 = strlen(l2);
		l2[len2-1] = '\0';
		len2--;
		
		p1 = p2 = 0;
		state = ONE;
		p = 0;
		while (p2 < len2) {
			if (state == ONE) {
				name[p++] = l1[p1++];
				name[p++] = l1[p1++];
				state = ZERO;
			} else {
				name[p++] = l2[p2++];
				if (p2 == len2) {
					break;
				}
				name[p++] = l2[p2++];
				state = ONE;
			}
		}
		name[p] = '\0';
		printf("%s\n", name);
		T--;
	}

	return 0;
}