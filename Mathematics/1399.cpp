#include <stdlib.h>
#include <stdio.h>

long long N, M, U;
long long int arr[3000001];
long long int L, R, V, P;
long long int c, v;

int main() {

	scanf("%Ld %Ld %Ld ", &N, &M, &U);
	for (int i = 0; i < N; i++) {
		scanf("%Ld ", &arr[i]);
	}
	for (int i = 0; i < M; i++) {
		scanf("%Ld %Ld %Ld %Ld ", &L, &R, &V, &P);
		L--; R--; P--;
		c = 0;
		for (int i = L; i <= R; i++) {
			if (arr[i] < V) {
				c++;
			}
		}
		v = U*c/((R+1)-(L+1)+1);
		arr[P] = v;
	}
	for (int i = 0; i < N; i++) {
		printf("%Ld\n", arr[i]);
	}
}