#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define G 9.80665
#define PI 3.14159

long double H;
int P1, P2;
long double A, V; // ANGULO, VELOCIDADE INICIAL
long double vs, vd; // VELOCIDADE SUBIDA, VELOCIDADE HORIZONTAL; 
long double ts, td; // TEMPO SUBIDA, TEMPO DECIDA;
long double alt; // ALTURA;
long double a; // POSIÇÃO DE ACERTO
int N;


int main() {

	while (scanf("%Lf ", &H) != EOF) {
		scanf("%d %d ", &P1, &P2);
		scanf("%d ", &N);
		for (int i = 0; i < N; i++) {
			scanf("%Lf %Lf ", &A, &V);
		
			vs = sin(A*PI/180) * V;
			vd = cos(A*PI/180) * V;
			
			ts = vs / G;
			alt = (vs*ts - G*ts*ts/2) + H;
			td = sqrt(alt*2 / G);
			a = (ts+td)*vd;

			printf("%0.5Lf -> ", a);
			if (a >= P1-1e-9 && a <= P2+1e-9) {
				printf("DUCK\n");
			} else {
				printf("NUCK\n");
			}
		}
	}

	return 0;
}