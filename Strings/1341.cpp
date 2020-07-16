#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int T;
int N, M;
char arr[25][25];
char s1[100005], s2[100005];
int pointer1, pointer2;
char instr[100005];
int X, Y;
int H, W;
int first_foward1[30][100005];
int first_foward2[30][100005];
int cnt1, cnt2;
int c;

using namespace std;

void next(char c) {
	if (c == 'E') {
		Y++;
	} else if (c == 'W') {
		Y--;
	} else if (c == 'S') {
		X++;
	} else if (c == 'N') {
		X--;
	}
}

void search() {
	int p1, p2;
	p1 = p2 = 0;
	int l1, l2;
	l1 = strlen(s1);
	l2 = strlen(s2);
	int i1, i2;
	while (p1 < l1 && p2 < l2) {
		if (s1[p1] == s2[p2]) {
			p1++;
			p2++;
		} else {
			i1 = first_foward1[s2[p2]-'A'][p1];
			i2 = first_foward2[s1[p1]-'A'][p2];
			if (i1 != 0 && i2 == 0 || i1 != 0 && i1 - p1 <= i2 - p2) {
				cnt1 += i1 - p1;
				p1 = i1+1;
				p2++;
			} else if (i2 != 0 && i1 == 0 || i2 != 0 && i1 - p1 >= i2 - p2) {
				cnt2 += i2 - p2;
				p2 = i2+1;
				p1++;
			} else {
				p1++;
				p2++;
				cnt1++;
				cnt2++;
			}
		}
	}
	cnt1 += l1 - p1;
	cnt2 += l2 - p2;
}

int main() {
	c = 0;
	scanf("%d ", &T);
	while (T) {
		c++;
		scanf("%d %d ", &H, &W);
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				scanf("%c ", &arr[i][j]);
			}
		}
		pointer1 = pointer2 = 0;
		scanf("%d %d %d ", &N, &X, &Y);
		s1[pointer1++] = arr[X][Y];
		if (N != 0) {
			scanf("%s ", instr);
		}
		for (int i = 1; i <= N; i++) {
			next(instr[i]);
			s1[pointer1++] = arr[X][Y];
		}
		s1[pointer1] = '\0';
		for (int i = 'A'; i <= 'Z'; i++) {
			first_foward1[i-'A'][pointer1] = 0;
		}
		for (int i = pointer1-1; i>= 0; i--) {
			for (int j = 'A'; j <= 'Z'; j++) {
				first_foward1[j - 'A'][i] = first_foward1[j - 'A'][i+1];
			}
			first_foward1[s1[i]-'A'][i] = i;
		}

		scanf("%d %d %d ", &M, &X, &Y);
		s2[pointer2++] = arr[X][Y];
		if (M != 0) {
			scanf("%s ", instr);
		}
		for (int i = 0; i < M; i++) {
			next(instr[i]);
			s2[pointer2++] = arr[X][Y];
		}
		s2[pointer2] = '\0';
		for (int i = 'A'; i <= 'Z'; i++) {
			first_foward2[i-'A'][pointer2] = 0;
		}
		for (int i = pointer2-1; i>= 0; i--) {
			for (int j = 'A'; j <= 'Z'; j++) {
				first_foward2[j - 'A'][i] = first_foward2[j - 'A'][i+1];
			}
			first_foward2[s2[i]-'A'][i] = i;
		}

		cnt1 = cnt2 = 0;
		search();
		printf("Case %d: %d %d\n", c, cnt1, cnt2);
		T--;
	}
	return 0;
}
