#include <stdlib.h>
#include <stdio.h>

#define LLD long long int
#define G1 100
#define G2 (10000 - 100)
#define G3 (1000000 - 10000)
#define INF 9999999999

LLD A, B;
LLD grupos[] = {G1, G2, G3, INF};
LLD custos[] = {2, 3, 5, 7};

LLD encontrar_consumo(LLD custo) {
	LLD consumo = 0;
	for (int i = 0; i < 4; i++) {
		if (custo <= grupos[i] * custos[i]) {
			consumo += custo / custos[i];
			custo = 0;
		} else {
			consumo += grupos[i];
			custo -= grupos[i] * custos[i];
		}
	}
	return consumo;
}

LLD encontrar_custo(LLD consumo) {
	LLD custo = 0;
	for (int i = 0; i < 4; i++) {
		if (consumo <= grupos[i]) {
			custo += consumo * custos[i];
			consumo = 0;
		} else {
			custo += grupos[i] * custos[i];
			consumo -= grupos[i];
		}
	}
	return custo;
}

LLD busca_binaria(LLD begin, LLD end, LLD consumo_total) {
	if (begin > end) {
		return -1;
	}
	LLD mid = begin + (end - begin)/2;
	LLD complemento = consumo_total - mid;

	LLD custo1 = encontrar_custo(mid);
	LLD custo2 = encontrar_custo(complemento);
	LLD diff = custo2 - custo1;

	if (diff > B) {
		return busca_binaria(mid+1, end, consumo_total);
	} else if (diff < B) {
		return busca_binaria(begin, mid-1, consumo_total);
	} else {
		return custo1;
	}
}

int main() {
	while (1) {
		scanf("%Ld %Ld ", &A, &B);
		if (!A && !B) {
			break;
		}
		LLD consumo = encontrar_consumo(A);
		consumo = busca_binaria(0, consumo/2, consumo);
		printf("%Ld\n", consumo);
	}
	return 0;
}