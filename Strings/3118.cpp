#include <stdlib.h>
#include <stdio.h>
#include <map>
#include <string>
#include <string.h>

using namespace std;

map<int, std::string> map_a;
map<int, std::string> map_b;

char bac[25][1000009];
char s1[1000009], s2[10];

int ca, cb;
int n, m;
int pointer, len, pos;
char last;
const char * cc;

int main() {

    scanf("%d %d ", &n, &m);
    bac[0][0] = 'A';
    bac[0][1] = '\0';

    for (int i = 0; i < m; i++) {
        scanf("%s %s ", s1, s2);
        len = strlen(s1);
        if (s1[0] == 'A') {
            map_a[len] = s2;
        } else {
            map_b[len] = s2;
        }
    }
    pos = 1;
    for (int it = 0; it < n; it++) {
        len = pos;
        last = bac[it][0];
        pointer = 1;
        bac[it+1][0] = '\0';
        pos = 0;
        for (int i = 1; i < len; i++) {
            if (bac[it][i] != last) {
                if (last == 'A') {
                    cc = map_a[pointer].c_str();
                } else {
                    cc = map_b[pointer].c_str();
                }
                for (int j = 0; cc[j] != '\0'; j++) {
                    bac[it+1][pos++] = cc[j];
                }
                pointer = 0;
                last = bac[it][i];
            }
            pointer++;
        }
        if (last == 'A') {
            cc = map_a[pointer].c_str();
        } else {
            cc = map_b[pointer].c_str();
        }
        for (int j = 0; cc[j] != '\0'; j++) {
            bac[it+1][pos++] = cc[j];
        }
        bac[it+1][pos] = '\0';
    }

    len = pos;
    ca = cb = 0;
    for (int i = 0; i < len; i++) {
        if (bac[n][i] == 'A') {
            ca++;
        } else if (bac[n][i] == 'B') {
            cb++;
        }
    }
    printf("%d %d\n", ca, cb);

    return 0;
}