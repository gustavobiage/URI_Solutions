#include <stdio.h>
#include <math.h>

#define LIM 100

double L;

int main(){

    while(scanf("%lf", &L) != EOF){
        double res = sqrt(3)*L*L/4;    
        L = L / 3;
        long long int mul = 3;

        for (int i = 0; mul > 0 && i < LIM; i++) {
            res = res + sqrt(3)*L*L/4 * mul;
            mul = mul * 4;
            L = L / 3;
        }

        printf("%0.2lf\n", res);
    }
}
