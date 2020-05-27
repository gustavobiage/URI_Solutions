#include <stdlib.h>
#include <stdio.h>

int T, P, N;
int arr[7];
int bias, maior_superior, maior_recuperacao;
int valor, soma;
double med;

int main() {

	scanf("%d ", &T);
	while (T) {
		soma = 0;
		scanf("%d %d ", &P, &N);
		for (int i = 0; i < N; i++) {
			maior_superior = 0;
			maior_recuperacao = 0;
			soma = 0;
			for (int j = 0; j < P; j++) {
				scanf("%d.%d ", &arr[j], &bias);
				valor = arr[j] * 10 + bias;
				soma += valor;
				if (valor > maior_superior) {
					maior_superior = valor;
				}

				if (valor > maior_recuperacao &&
				valor < 70 && valor >= 40) {
					maior_recuperacao = valor;
				}
			}

			med = (double) soma / P;

			if (med >= 70) {
				if (maior_superior > med) {
					printf("%0.2lf\n", maior_superior/10.0);
				} else {
					printf("%0.2lf\n", med/10);
				}
			} else if (med >= 40){
				if (maior_recuperacao > med) {
					printf("%0.2lf\n", maior_recuperacao/10.0);
				} else {
					printf("%0.2lf\n", med/10);
				}
			} else {
				printf("%0.2lf\n", med/10);
			}
		}
		T--;
	}

	return 0;
}