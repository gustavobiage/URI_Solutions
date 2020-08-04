#include <stdlib.h>
#include <stdio.h>

long long int xor_, bit_, xorr, xorl;
int N;
long long int arr[100001];

int main() {
    while (scanf("%d ", &N) != EOF) { // Read Forum for an explanation
        if (!N) {
            break;
        }
        xor_ = xorr = xorl = 0;
        for (int i = 0; i < N; i++) {
            scanf("%Ld ", &arr[i]);
            xor_ = xor_ ^ arr[i];
        }
        bit_ = xor_&-xor_;
        for (int i = 0; i < N; i++) {
            if (arr[i] & bit_) {
                xorr = xorr ^ arr[i];
            } else {
                xorl = xorl ^ arr[i];
            }
        }
        if (xorr > xorl) {
            printf("%Ld %Ld\n", xorl, xorr);
        } else {
            printf("%Ld %Ld\n", xorr, xorl);
        }
    }
    return 0;
}